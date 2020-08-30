#include "inet.h"
#define MAXLINE 512

//prototype declaration//
int readline(register int fd, register char *ptr, register int maxlen);
void str_echo(int sockfd);

//main function//
int main(int argc,char *argv[]){
	int sockfd, newsockfd, clilen, childpid;
	struct sockaddr_in cli_addr, serv_addr;
	pname = argv[0];
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0)
	    printf("server : can't open stream socket\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERV_TCP_PORT);

	if(bind(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
	    printf("server : can't bind local address\n");
	    exit(-1);
	}
	printf("waiting...\n");	
	listen(sockfd, 5);
	for(;;){
	    clilen = sizeof(cli_addr);
	    printf("open client socket\n");
	    newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen);
	    if(newsockfd<0){
		printf("server : accept error\n");
		exit(-1);
	    }
	    if((childpid = fork()) <0){
		printf("server : fork error\n");
		exit(-1);
	    }
	    else if(childpid == 0){
		close(sockfd);
		str_echo(newsockfd);
	        close(newsockfd);
		exit(0);
	    }
	}		
}
////////////////////////////////////////////////////
//string echo function//
void str_echo(int sockfd){
	int n;
	char line[MAXLINE];
////////////////////////////////////////////////////////
	int i;
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
	//unsigned char push_sw_buff[MAX_BUTTON];	//for switch
	//for current time//
	const time_t tim = time(NULL);
	struct tm *cur_time;
	cur_time = localtime(&tim);
	//board time check
	printf("current time %d:%d:%d\n",cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec);
	//device open	
	//dev = open("/dev/fpga_push_switch", O_RDWR);//SWITCH DEVICE
	dev_out[0] = open("/dev/fpga_text_lcd", O_WRONLY);//LCD DEVICE
	dev_out[1] = open("/dev/fpga_fnd", O_RDWR);//7-SEG DEVICE
	dev_out[2] = open("/dev/fpga_dot", O_RDWR);//DOT DEVICE
	if ((dev_out[0]<0)||(dev_out[1]<0)||(dev_out[2]<0)){
		printf("Device Open Error\n");
		return ;
	}

	//buff_size=sizeof(push_sw_buff);
	str_size=sizeof(fpga_alphabet[DOT_OUT_A]);
	printf("GET COMMAND QUIT will off. \n");
	memset(string,0,sizeof(string));

////////////////////////////////////////////////////////
	for(;;){
	    n = readline(sockfd, line, MAXLINE);
	    if(n ==0)
	 	return;
	    else if(n<0)
		printf("str_echo : readline error\n");
	    if(write(sockfd, line, n) != n)
		printf("str_echo: writen error\n");
	    //TODO MAKE CONTROL PROGRAM
	    //COMMAND IS STORED IN line
	    //usleep(250000);	//delay 250ms
	    //read(dev, &push_sw_buff, buff_size);	//button read
	    //TO DO
	    printf("received : %s\n",line);
	    printf("%d\n",strlen(line));
	    if(!strcmp(line,"LCD\n")){
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
	    if(!strcmp(line,"SEG\n")){
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
	    if(!strcmp(line,"DOT\n")){
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
	    if(!strcmp(line,"QUIT\n")){
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
	    //printf("[%d] ",push_sw_buff[i]);
	    //}
	    //printf("\n");
	}
	close(dev_out[0]);
	close(dev_out[1]);
	close(dev_out[2]);
}	
/////////////////////////////////////////////////////
//string readline function//
int readline(register int fd, register char *ptr, register int maxlen){
	int n, rc;
	char c;
	for (n=1; n < maxlen; n++){
	    if((rc = read(fd, &c, 1)) == 1) {
		*ptr++ = c;
		if(c == '\n')break;
	    }
	    else if(rc == 0){
		if(n == 1)
		    return 0;
	    }
	    else
		return -1;
	}
	*ptr = 0;
	return n;
}
