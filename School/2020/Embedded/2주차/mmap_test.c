/****************************************************************************
 * FileName : mmap_test.c
 *
 * Abstract :
 * 	This file is a program for memory map test
 *
 * 201524582
 * switch-> 7seg,led,dot-matrix implement 
 * Modified :
 * 	Created : March 16, 2018 by Dongheon Han
 * 	Modified : April 08, 2020 by Heeseok Jeong
 *                 April 10, 2020 by Heeseok Jeong
 *     		   April 11, 2020 by Heeseok Jeong
****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>

#define FPGA_BASEADDRESS        0x08000000
//Dip switch = 0x08000000
#define SEG_7_OFFSET 0x04
#define STEP_MOTER_OFFSET 0x0C
#define LED_OFFSET	0x16
#define PUSH_SWI_OFFSET 0x50
#define BUZZER_OFFSET 0x70
#define LCD_OFFSET 0x90
#define DOT_MATX_OFFSET 0x0210
//push-switch map
/*
sw8 = LED 0F //down 4
sw13 = LED FO//up 4
sw9 = LED FF //all on
sw12 = LED 00 //all off
=========================
sw10 = 7seg 2020
sw11 = 7seg 0000
=========================
sw14 = dot ON
sw16 = dot OFF
========================
sw8 = 0x00
sw13 = 0x01
sw9 = 0x02
sw10 = 0x03
sw11 = 0x04
sw12 = 0x05
sw14 = 0x06
sw16 = 0x07
sw15 = 0x08
=============================
lcd : ASCII code
0~9 : 0x30~0x39
a~z : 0x61~0x7A
A~Z : 0x41~0x5A
*/
//

int main(void)
{
  	int i = 1;
  	int j = 0;
	short count[4] = {0,0,0,0};	
	int fd;
	unsigned short *addr_fpga;
	unsigned short *addr_seg;
	unsigned short *addr_dot;	
	unsigned short *addr_sw;	
	unsigned short *addr_led;
	unsigned short *addr_lcd;
	if ((fd=open("/dev/mem",O_RDWR|O_SYNC)) < 0) {
		perror("mem open fail\n");
		exit(1);
	}

	addr_fpga= (unsigned short *)mmap(NULL, 4096, PROT_WRITE|PROT_READ, MAP_SHARED, fd, FPGA_BASEADDRESS);
	addr_led = addr_fpga + LED_OFFSET / sizeof(unsigned short);
	addr_seg = addr_fpga + SEG_7_OFFSET / sizeof(unsigned short);
	addr_dot = addr_fpga + DOT_MATX_OFFSET / sizeof(unsigned short);
	addr_sw = addr_fpga + PUSH_SWI_OFFSET / sizeof(unsigned short); 
	addr_lcd = addr_fpga + LCD_OFFSET / sizeof(unsigned short);	
	if( *addr_led == (unsigned short)-1 ) {
		printf("mmap error\n");
		exit(1);
	}
  *addr_lcd = 0x1212;
  for(i=0;i<15;i++){
     addr_lcd += 1;
     *addr_lcd = 0x1212;	
  }
  addr_lcd -= 15;
  *addr_led = 0x0;
  *addr_seg = 0x0;
  *addr_dot = 0x0;
  i=1;
  while(i){
      if(*addr_sw){	//led 0f sw8
	if(count[0]%4 == 0){	
	  *addr_led = 0x0F;//down 4 first
	  count[0] = 1;
	}	
	else if(count[0]%4 == 1){
 	  *addr_led = 0xF0;//up 4   second
	  count[0] = 2;
	}
	else if(count[0]%4 == 2){
          *addr_led = 0xFF;//all    third
	  count[0] = 3;	
	}
	else{
	  *addr_led = 0x00;//off    forth
	  count[0] = 0;
	}
	usleep(250000);
      }
      if(*(addr_sw+3)){//7seg 2020 sw10
	if(count[1] == 0){	
	  *addr_seg = 0x2020;//on   first
	  count[1] = 1;
	}
	else{
	  *addr_seg = 0x0000;//off  second
	  count[1] = 0;
	}
	usleep(250000);
      }
      if(*(addr_sw+6)){//dot on   sw14
	if(count[2]==0){
	  *addr_dot = 0x7F;
  	  addr_dot += 1;
 	  *addr_dot = 0x7F;
  	  addr_dot += 1;
  	  *addr_dot = 0x03;
  	  addr_dot += 1;
  	  *addr_dot = 0x03;
  	  addr_dot += 1;
  	  *addr_dot = 0x7F;
  	  addr_dot += 1;
  	  *addr_dot = 0x7F;
  	  addr_dot += 1;
  	  *addr_dot = 0x60;
  	  addr_dot += 1; 
  	  *addr_dot = 0x60;
  	  addr_dot += 1;
  	  *addr_dot = 0x7F;
  	  addr_dot += 1;
  	  *addr_dot = 0x7F;
  	  addr_dot -= 9;
	  count[2] = 1;
	}
	else{		  //dot off
	  *addr_dot = 0x00;
	  for(j=0;j<9;j++){
            addr_dot += 1;
	    *addr_dot = 0x00;	
	  }
	  addr_dot -= 9;	  
 	  count[2] = 0;
        }
	usleep(250000);
      }
      if(*(addr_sw+2)){//lcd sw9
	if(count[3] == 0){//lcd on
	  *addr_lcd = 0x3230;
	  addr_lcd += 1;
	  *addr_lcd = 0x3230;
	  addr_lcd += 1;
	  *addr_lcd = 0x2F30;
	  addr_lcd += 1; 
	  *addr_lcd = 0x342F;
	  addr_lcd += 1;
	  *addr_lcd = 0x3131;
	  addr_lcd += 4;
	  *addr_lcd = 0x3230;
	  addr_lcd += 1;
	  *addr_lcd = 0x3135;
	  addr_lcd += 1;
	  *addr_lcd = 0x3234;
	  addr_lcd += 1;
	  *addr_lcd = 0x3538;
	  addr_lcd += 1;
	  *addr_lcd = 0x3220;
	  addr_lcd -= 12;
	  count[3] = 1;
	}
	else{		  //lcd off	
	  *addr_lcd = 0x1212;
  	    for(i=0;i<15;i++){
     	      addr_lcd += 1;
              *addr_lcd = 0x1212;	
  	    }
	  addr_lcd -= 15;
	  count[3] = 0;
	}
	usleep(250000);
      } 
      if(*(addr_sw+8)){//all off & break; //sw15
        *addr_seg = 0x0;
	*addr_led = 0x0;
	*addr_dot = 0x00;	
	for(j=0; j<9;j++){
	  addr_dot += 1;
	  *addr_dot = 0x00;
	}
	addr_dot -= 9;
	*addr_lcd = 0x1212;
  	  for(i=0;i<15;i++){
     	    addr_lcd += 1;
            *addr_lcd = 0x1212;	
  	  }
	addr_lcd -= 15;
	i = 0;
	}
  }

 /* 
  for( i = 0; i < 7; i++) {
    *addr_led = 0x0F;//low4
    *addr_seg = 0x202;
    sleep(1);
    *addr_led = 0xF0;//high4
    *addr_seg = 0x404;
    sleep(1);   
  }

//number 2 in dot
  *addr_dot = 0x7F;
  addr_dot += 1;
  *addr_dot = 0x7F;
  addr_dot += 1;
  *addr_dot = 0x03;
  addr_dot += 1;
  *addr_dot = 0x03;
  addr_dot += 1;
  *addr_dot = 0x7F;
  addr_dot += 1;
  *addr_dot = 0x7F;
  addr_dot += 1;
  *addr_dot = 0x60;
  addr_dot += 1; 
  *addr_dot = 0x60;
  addr_dot += 1;
  *addr_dot = 0x7F;
  addr_dot += 1;
  *addr_dot = 0x7F;
  addr_dot -= 8;  
  *addr_seg = 0x00;
  *addr_led = 0x00;
  *addr_dot = 0x00;
*/ 
	munmap(addr_fpga,4096);
	close(fd);
	return 0;
}
