#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/kdev_t.h>
#include <linux/interrupt.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

/* Funrction : IXM_GPIO_NR(x,y) */
/* -- x : Port # -- */
/* -- y : Pin # -- */
#define ULTRASONIC_ECHO IMX_GPIO_NR(2, 3)
#define ULTRASONIC_TRIGGER IMX_GPIO_NR(2, 2)
// US's ECHO -> GPIO2_PIN3
// US's TRIGGER -> GPIO2_PIN2
static int us_major=0, us_minor=0;
static int result, res;
static dev_t us_dev;
static struct cdev us_cdev;
int send_value=0;
char temp[100] = {0,};


/* Timeval 구조체 */	//in time.h
struct timeval after, before;
u32 irq = -1;

static int us_register_cdev(void);
static int us_open(struct inode *inode, struct file *filp);
static int us_release(struct inode *inode, struct file *filp);
static int us_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);

void output_sonicburst(void);
int gpio_init(void);
static irqreturn_t ultrasonics_echo_interrupt(int irq, void *dev_id, struct pt_regs *regs);


/* Type : irqreturn_t */
/* Interrupt Callback function */
static irqreturn_t ultrasonics_echo_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	// Ultrasonic의 ECHO pin의 GPIO 값에 대해서
	if(gpio_get_value(ULTRASONIC_ECHO))
	{
		// GPIO 값이 1일 때, driver module에서 시간을 측정한다.
		// driver module에서 시간을 측정하는 함수는 User 영역의 time 함수가 아닌 다른 함수 사용
		printk(KERN_ALERT "<ECHO = 1>\n");			
		// 아래의 코드를 작성하시오
		do_gettimeofday( &before);
	}
	else
	{
		// GPIO 값이 0일 때, driver module에서 시간을 측정한다.
		printk(KERN_ALERT "<ECHO = 0>\n");	
		// 아래의 코드를 작성하시오
		do_gettimeofday( &after);	
		// ECHO 값이 0일 때, driver Module에서 after 시간을 측정 후 거리를 계산한다.
		send_value = (after.tv_usec - before.tv_usec) / 58;
		// temp buf에 넣어 값을 메모리 상에 저장한다.
		sprintf(temp,"%d",send_value);
		memset(&before, 0 , sizeof(struct timeval ) );
		memset(&after , 0 , sizeof(struct timeval ) );
	}

	return IRQ_HANDLED;
}

/* Function : us_open */
/* Ultrasonic Device Driver가 User Application에서 open 명령을 수행 했을 시 실행되는 함수 */
static int us_open(struct inode *inode, struct file *filp)
{
	printk(KERN_ALERT "< Device has been opened >\n");

	return 0;
}

/* Function : us_release */
/* Ultrasonic Device Driver가 User Application에서 release 명령을 수행 했을 시 실행되는 함수 */
static int us_release(struct inode *inode, struct file *filp)
{
	printk(KERN_ALERT "< Device has been closed > \n");

	return 0;
}

/* Function : us_read */
/* Ultrasonic Device Driver가 User Application에서 read 명령을 수행 했을 시 실행되는 함수 */
static int us_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{

	printk(KERN_ALERT "<enter READ> \n");
	output_sonicburst();
	mdelay(1);
	// Kernel 영역에서 User에게 값을 전달함
	copy_to_user(buf,temp,strlen(temp));
	return 0;
}

/* Type file_operations */
/* User Application에서 명령에 따른 동작을 Binding 하기 위한 구조체 */
struct file_operations us_fops = {//COMPLETE => 3rd week's fpga_xxx_driver.c check
	// open 동작 binding
	.open = us_open,
	// release 동작 binding
	// 아래의 코드를 작성하시오	//COMP
	.release = us_release,
	// read 동작 binding
	// 아래의 코드를 작성하시오	//COMP
	.read = us_read,
};

/* Function : us_init */
/* module_init 함수의 파라미터로 사용되는, insmod 시 실행되는 함수 */
static int us_init(void)
{
	printk(KERN_ALERT "< Ultrasonic Module is up > \n");
	// timeval initialization
	// Ultrasonic의 chracter Device Driver init
	// 아래의 코드를 작성하시오	//COMP
	// device number registration
	// *us_cdev = cdev_alloc(); //substituted by cdev_init();
	// if us_cdev declared to pointer, have to use cdev_alloc();
	result = us_register_cdev(); //complete
	if(result <0)
	{
		printk(KERN_ALERT "< Ultrasonic Register Fail > \n");
		return result;
	}

	// Ultrasonic 제어에 사용할 GPIO init
	// 아래의 코드를 작성하시오	//
  	res = gpio_init(); //complete but have to check
	if(res < 0 )
		return -1;

	return 0;
}

/* Function : us_exit */
/* module_exit 함수의 파라미터로 사용되는, rmmod 시 실행되는 함수 */
static void us_exit(void)
{
	printk(KERN_ALERT "< Ultrasonic Module is down > \n");
	// GPIO interrupt release
	free_irq(irq, NULL);
	// GPIO release
	gpio_free(ULTRASONIC_TRIGGER);
	gpio_free(ULTRASONIC_ECHO);
	// Chracter device driver configuration 제거
	cdev_del(&us_cdev);
	// Character device driver release
	unregister_chrdev_region(us_dev,1);
}

/* Function : output_sonicburst */
/* Ultrasonic sensor의 수신부에서 거리 측정을 위해 Ping을 보내는 함수 */
void output_sonicburst(void)
{
	printk(KERN_ALERT "<enter sonicburst> \n");
	// 아래의 코드를 작성하시오	//COMP
	// set high for 10us trigger pin, set low for wait
	gpio_set_value(ULTRASONIC_TRIGGER,1);
	udelay(10);
	gpio_set_value(ULTRASONIC_TRIGGER,0);	
	printk(KERN_ALERT "<exit sonicburst> \n");
}

/* Function : gpio_init */
/* IMX6Q chipset의 GPIO Configuration을 진행하는 함수 */
int gpio_init(void)
{
		int rtc;

	// TRIGGER GPIO pin init
	// 아래의 코드를 작성하시오	//COMP
	rtc = gpio_request(ULTRASONIC_TRIGGER,"us_tr");
    if (rtc!=0) {
				printk(KERN_ALERT "<Trigger Pin Request Fail>\n");
	      goto fail;
    }

	// ECHO GPIO pin init
	// 아래의 코드를 작성하시오	//COMP
	rtc = gpio_request(ULTRASONIC_ECHO,"us_ec");
    if (rtc!=0) {
				printk(KERN_ALERT "<Echo Pin Request Fail>\n");
	      goto fail;
    }

	// TRIGGER GPIO pin direction init //trigger -> out
	// 아래의 코드를 작성하시오	//COMP
	rtc = gpio_direction_output(ULTRASONIC_TRIGGER,0);
    if (rtc!=0) {
				printk(KERN_ALERT "<Trigger pin Setting Fail>\n");
	      goto fail;
    }

	// ECHO GPIO pin direction init //echo -> in
	// 아래의 코드를 작성하시오	//COMP
	rtc = gpio_direction_input(ULTRASONIC_ECHO);
    if (rtc!=0) {
				printk(KERN_ALERT "<Echo Pin Setting Fail>\n");
	      goto fail;
    }

  // ECHO GPIO pin Interrupt init	//int gpio_to_irq(unsigned int gpio)
	// 아래의 코드를 작성하시오	//COMP
	rtc = gpio_to_irq(ULTRASONIC_ECHO);
		if (rtc<0) {
				printk(KERN_ALERT "<irq Pin GPIO Request Fail>\n");
		  	goto fail;
		} else {
		        irq=rtc;
		}

	// ECHO GPIO pin Interrupt 시 작동하는 함수 및 옵션 설정
	// Interrupt flag : IRQF_TRIGGER_RISING , IRQF_TRIGGER_FALLING , IRQF_DISABLED 사용
	// -- IRQ_DISABLED : 인터럽트 핸들러를 실행하는 동안 모든 인터럽트 비활성화
	// -- IRQF_TRIGGER_RISING : 신호가 상승할 때 인터럽트 인지.
	// -- IRQF_TRIGGER_FALLING : 신호가 하강할 때 인터럽트 인지.
	// 아래의 코드를 작성하시오	//COMP but have to check
	rtc = request_irq(irq, (void*) ultrasonics_echo_interrupt,IRQF_TRIGGER_RISING|IRQF_TRIGGER_FALLING|IRQF_DISABLED,"us",NULL);
	  if(rtc) {
		printk(KERN_ALERT "<irq Register Fail>\n");
	      	goto fail;
	  }

    printk(KERN_INFO "Ultrasonic device Enable\n");
		gpio_set_value(ULTRASONIC_TRIGGER,0);
		return 0;

		fail:
			return -1;
}

/* Function : us_register_cdev */
/* Ultrasonic에 사용할 chracter device driver 초기화 및 설정하는 init 함수 */
static int us_register_cdev(void)	//=>COMPLETE
{
	int error;

	// Chracter device driver 초기화
	if(us_major) {
		// major #이 존재할 때, device driver 초기화
		// 아래의 코드를 작성하시오	//COMP
		us_dev = MKDEV(us_major,us_minor);
		error = register_chrdev_region(us_dev,1,"us");
	}else{
		// major #이 존재하지 않을 때, device driver 초기화
		// 아래의 코드를 작성하시오	//COMP
		error = alloc_chrdev_region(&us_dev,us_minor,1,"us");
	   	us_major = MAJOR(us_dev);//get allocated major#
		//us_major = MAJOR(&us_dev); //=>have to check!
	}

	if(error<0) {
		printk(KERN_WARNING "us: can't get major %d\n", us_major);
		return result;
	}

	printk(KERN_ALERT "major number = %d\n", us_major);

	// Chracter deivce driver configuration의 File file_operations 설정
	// 아래의 코드를 작성하시오		//COMP
	
	cdev_init(&us_cdev,&us_fops);
	
	// Character device driver owner 및 file_operations 등록
	us_cdev.owner = THIS_MODULE;
	us_cdev.ops = &us_fops;
	// Character device driver에 chracter device driver configuration 등록
	// 아래의 코드를 작성하시오		//COMP
	
	error = cdev_add(&us_cdev,us_dev,1);
	
	if(error)
	{
		printk(KERN_NOTICE "us Register Error %d\n", error);
	}
	return 0;
}


MODULE_AUTHOR("gunmin, lee <gmlee@huins.com>");
MODULE_DESCRIPTION("HUINS ext sensor Device Driver");
MODULE_LICENSE("GPL");

// Module을 insmod 명령을 통해 Kernel 상에 등록 시켰을 경우 실행되는 함수
module_init(us_init);
// Module을 rmmod 명령을 통해 Kernel 상에서 삭제 시켰을 경우 실행되는 함수
module_exit(us_exit);
