#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./fpga_dot_font.h"

int main(void)
{
	int fd;
	int dev[2];
	int retn;
	int i = 0;
	char buf[10] = {0};	
	int loop = 0;
	//int str_size;
	//unsigned char fnd_data[4]={0,0,0,0};	
	fd = open("/dev/us", O_RDWR);
	//str_size = sizeof(fpga_number[0]);
	dev[0] = open("/dev/fpga_fnd", O_RDWR);	//7-seg x 4
	dev[1] = open("/dev/fpga_dot", O_RDWR);	//dot
	printf("fd = %d, fnd = %d, dot = %d\n", fd, dev[0], dev[1]);
	if((dev[0]<0)||(dev[1]<0)){
		printf("device Open Error\n");
		close(dev[0]);
		close(dev[1]);
		exit(-1);	
	}
	if(fd<0){
		perror("/dev/us error");
		exit(-1);
	}else{
		printf("< us device has been detected >\n");
	}

	while(1){
		read(fd,buf,2);	//problem : read null value
		//=> interrupt execution varify
		retn = atoi(buf);    			
		if(retn<0);
		else{
		    if(retn<10){
			printf("Distance are less than 10cm!\n");
			printf("Distance: %dcm\n",retn);		
			/*
			write(dev[1],fpga_number[retn],str_size);
			fnd_data[2]=0;
			fnd_data[3]=0;
			*/
			}
		    else if(retn<300){
			printf("Distance: %dcm\n",retn);
			/*
			write(dev[1],fpga_set_blank,str_size);
			fnd_data[3]=retn%10;
			fnd_data[2]=retn/10%10;
			*/	
			}
		    else{
			if(retn>2000)
			    printf("Distance is Too CLOSE!\n");
			else
			    printf("Distance is Too FAR!\n");
			/*
			write(dev[1],fpga_set_blank,str_size);
			fnd_data[0]=0;
			fnd_data[1]=0;
			fnd_data[2]=0;
			fnd_data[3]=0;
			*/	
			}
		    //write(dev[0],&fnd_data,4);
			
		}
		sleep(1);
		//buf -> atoi -> value
		//if value < 10 => dot
		//else (value >=10) => 7-seg
		for(i=0;i<10;i++){
		    buf[i]=0;	
		}
	}

	close(fd);
	close(dev[0]);
	close(dev[1]);

	return 0;
	
}
