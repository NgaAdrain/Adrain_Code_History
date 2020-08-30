/* FPGA Push Switch Test Application
File : fpga_test_push.c
Auth : largest@huins.com 
Mod  : Adrain
*/
//201524582 CSE JEONGHEESEOK


#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>	 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <signal.h>
#include <time.h>

#include "./fpga_dot_font.h"

#define MAX_BUTTON 9
#define DOT_OUT_A 0
#define DOT_OUT_P 1

//push_sw_buff[0] => SW8
//push_sw_buff[1] => SW13
//push_sw_buff[2] => SW9
//push_sw_buff[3] => SW10
//push_sw_buff[4] => SW11
//push_sw_buff[5] => SW12
//push_sw_buff[6] => SW14
//push_sw_buff[7] => SW16
//push_sw_buff[8] => SW15

unsigned char quit = 0;

void user_signal1(int sig) 
{
	quit = 1;
}

int main(void)
{
	
	int i;
	int dev;				//for switch device
	int dev_out[3];				//for output device
	int buff_size;
	int str_size;				//for dot
	int lcd_str_size;
	int fnd_ret = 0;			//for 7-seg
	unsigned char fnd_data[4]={0,0,0,0};	//for 7-seg
	unsigned char string[32];		//for lcd
	unsigned char f_sub_str[] = "Pusan Nat'i Univ";
	unsigned char s_sub_str[] = "CSE Jeong H.S";
	char check[3]={0,0,0};			//for switch
	unsigned char push_sw_buff[MAX_BUTTON];	//for switch
	//for current time//
	const time_t tim = time(NULL);
	struct tm *cur_time;
	cur_time = localtime(&tim);
	//board time check
	printf("current time %d:%d:%d\n",cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec);
	//device open	
	dev = open("/dev/fpga_push_switch", O_RDWR);//SWITCH DEVICE
	dev_out[0] = open("/dev/fpga_text_lcd", O_WRONLY);//LCD DEVICE
	dev_out[1] = open("/dev/fpga_fnd", O_RDWR);//7-SEG DEVICE
	dev_out[2] = open("/dev/fpga_dot", O_RDWR);//DOT DEVICE
	if ((dev<0)||(dev_out[0]<0)||(dev_out[1]<0)||(dev_out[2]<0)){
		printf("Device Open Error\n");
		close(dev);
		return -1;
	}

	(void)signal(SIGINT, user_signal1);

	buff_size=sizeof(push_sw_buff);
	str_size=sizeof(fpga_alphabet[DOT_OUT_A]);
	printf("Press sw15 to quit. \n");
	memset(string,0,sizeof(string));
	while(!quit){		//infinite loop
		usleep(250000);	//delay 250ms
		read(dev, &push_sw_buff, buff_size);	//button read
		//TO DO
		if(push_sw_buff[0]==1){
			//LCD output
			//TO DO
			if(check[0]==0){
			    lcd_str_size = strlen(f_sub_str);
			    strncat(string,f_sub_str,lcd_str_size);
			    memset(string+lcd_str_size,' ',16-lcd_str_size);
			    lcd_str_size = strlen(s_sub_str);
			    strncat(string,s_sub_str,lcd_str_size);
			    memset(string+16+lcd_str_size,' ',16-lcd_str_size);
			    write(dev_out[0],string,32);
			    check[0]=1;	
			}
			else{
			    //lcd reset
			    memset(string,' ',sizeof(string));
			    write(dev_out[0],string,sizeof(string));	
			    memset(string,0,sizeof(string));
			    check[0]=0;
			}	
		}
		if(push_sw_buff[1]==1){
			cur_time = localtime(&tim);
			//7-seg output
			//TO DO
			fnd_data[0]=(cur_time->tm_hour/10);
			fnd_data[1]=(cur_time->tm_hour%10);
			fnd_data[2]=(cur_time->tm_min/10);
			fnd_data[3]=(cur_time->tm_min%10);		
			if(check[1]==0){
			    //write
			    write(dev_out[1],&fnd_data,4);
			    check[1]=1;
			}
			else{
			    //7-seg reset
			    fnd_data[0]=0;
			    fnd_data[1]=0;
			    fnd_data[2]=0;
			    fnd_data[3]=0;
			    write(dev_out[1],&fnd_data,4); 
			    check[1]=0;
			}
		}
		if(push_sw_buff[2]==1){
			cur_time = localtime(&tim);
			//dot-mat clock out
			//TO DO
			//DOT_OUT_A->0
			//DOT_OUT_P->1
			if(check[2]==0){
			    if(cur_time->tm_hour>=12){
				//P out	
				write(dev_out[2],fpga_alphabet[DOT_OUT_P],str_size);
			    }
			    else{
				//A out
				write(dev_out[2],fpga_alphabet[DOT_OUT_A],str_size);
			    }
			    //write
			    check[2]=1;
			}
			else{
			    //dot reset
			    write(dev_out[2],fpga_set_blank,str_size);
			    check[2]=0;
			}
		}
		if(push_sw_buff[8]==1){
			//off all module
			//TO DO
			fnd_data[0]=0;
			fnd_data[1]=0;
			fnd_data[2]=0;
			fnd_data[3]=0;
			//reset lcd
			memset(string,' ',sizeof(string));
			write(dev_out[0],string,sizeof(string));	
			write(dev_out[1],&fnd_data,4);//reset 7-seg
			write(dev_out[2],fpga_set_blank,str_size);//reset dot
			memset(string,0,sizeof(string));
			break;	
		}
		//for(i=0;i<MAX_BUTTON;i++) {
		//	printf("[%d] ",push_sw_buff[i]);
		//}
		//printf("\n");
	}
	close(dev);
	close(dev_out[0]);
	close(dev_out[1]);
	close(dev_out[2]);
}
