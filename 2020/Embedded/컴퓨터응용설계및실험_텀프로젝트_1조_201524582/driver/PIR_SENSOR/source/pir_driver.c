#include <linux/gpio.h>
#include <linux/uaccess.h>
#include <linux/input.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>

#define GPIO_DATA	IMX_GPIO_NR(2,4)

static int pir_open(struct inode *inode, struct file *file);
static int pir_release(struct inode *inode, struct file *file);
static int pir_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
static int pir_init(void);
static void pir_exit(void);
static int pir_register_cdev(void);

static int ext_major = 0, ext_minor = 0;
static dev_t pir_dev;
static struct cdev pir_cdev;


static int pir_open(struct inode *inode, struct file *file)
{	
	printk(KERN_ALERT "< Device has been opened > \n");
	return 0;
}

static int pir_release(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "< Device has been closed > \n");
	return 0;
}

static int pir_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	int res, ret;
	char data[10] = {0};
        res = gpio_get_value(GPIO_DATA);
	sprintf(data,"%d",res);
	ret = copy_to_user(buf,&data,count);
	return 0;
}

struct file_operations pir_fops = {
	.open = pir_open,
	.release = pir_release,
	.read = pir_read,
};

static int pir_init(void)
{
	int result = 0;
	
	printk(KERN_ALERT "< EXT Sensor Module is up > \n");
	if((result = pir_register_cdev())<0){
		printk(KERN_ALERT "< EXT Sensor Register Fail > \n");
		return result;
	}

	result = gpio_request(GPIO_DATA,"DATA_PIN");
	if(result != 0 ){
		printk(KERN_ALERT "< DATA_PIN Request Fail > \n");
		return -1;
	}

	result = gpio_direction_input(GPIO_DATA);
        if (result != 0) {
                printk(KERN_ALERT "< DATA_PIN Configure set Fail > \n");
                return -1;
        }

		
	return 0;
}

static void pir_exit(void)
{
	printk(KERN_ALERT "< EXT Sensor Module is down > \n");
	gpio_free(GPIO_DATA);
	cdev_del(&pir_cdev);
	unregister_chrdev_region(pir_dev,1);
}

static int pir_register_cdev(void)
{
	int error;
	
	if(ext_major){
		pir_dev = MKDEV(ext_major, ext_minor);
		error = register_chrdev_region(pir_dev,1,"pir");
	}else{
		error = alloc_chrdev_region(&pir_dev,ext_minor,1,"pir");
		ext_major = MAJOR(pir_dev);
	}

	if(error<0){
		printk(KERN_WARNING "pir : can't get major %d\n", ext_major);
		return -1;
	}

	printk(KERN_ALERT "major number = %d\n", ext_major);

	cdev_init(&pir_cdev, &pir_fops);
	pir_cdev.owner = THIS_MODULE;
	pir_cdev.ops = &pir_fops;
	error = cdev_add(&pir_cdev, pir_dev,1);
	
	if(error){
		printk(KERN_NOTICE "pir sensor Register Error %d\n", error);
	}

	return 0;
}

MODULE_AUTHOR("gunmin, lee <gmlee@huins.com>");
MODULE_DESCRIPTION("HUINS ext sensor Device Driver");
MODULE_LICENSE("GPL");

module_init(pir_init);
module_exit(pir_exit);
