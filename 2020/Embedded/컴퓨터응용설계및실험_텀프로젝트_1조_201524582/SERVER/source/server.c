#include "inet.h"

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"

#include "v4l_wrapper.h"
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
	//for camera//
	fsl_v4l_cap mycamera;
	fsl_v4l_out mydisplay;
	int ret;
	char *buffer;
	int width = 640;
	int height = 480;
	IplImage *image;
////////////////////////////////////////////////////////
	int i;
	int dev_1;
	int dev_2;
	char buf[10] = {0};
	char buf_pir[10] = {0};
	int retn;
	//for current time//
	const time_t tim = time(NULL);
	struct tm *cur_time;
	cur_time = localtime(&tim);
	//board time check
	printf("current time %d:%d:%d\n",cur_time->tm_hour,cur_time->tm_min,cur_time->tm_sec);
	//device open	
	dev_1 = open("/dev/us", O_RDWR);	//ULTRASOONIC DEVICE
	dev_2 = open("/dev/pir", O_RDWR);	//PIR SENSOR
	if (dev_1<0||dev_2<0){
		printf("Device Open Error\n");
		close(dev_1);
		close(dev_2);
		return ;
	}

	printf("GET COMMAND QUIT will off. \n");
////////////////////////////////////////////////////////
	//camera setting//
	printf ("\n\nInitialzing Camera Device: Video0 (640x480)...");
	
	ret = V4LWrapper_CreateCameraCapture (&mycamera, "/dev/video0", width, height);
	
	if (ret == V4LWrapper_SUCCESS)
	{
		printf ("OK\n");
	}
	
	else
	{
		printf ("\nDevice not found, make sure the driver are properly installed:");
		printf ("\nov5642_camera.ko, ov5640_camera_mipi.ko and mxc_v4l2_capture.ko\n");
		exit (0);
	}

	printf ("\nInitialzing Display Device: video17, fb0 (640x480)...");
	ret = V4LWrapper_CreateOutputDisplay (&mydisplay, "/dev/fb0", NULL, width, height);
	if (ret == V4LWrapper_SUCCESS)
		printf ("OK\n");
	else
	{
		V4LWrapper_CloseCameraCapture (&mycamera);
		exit (0);
	}
	
	printf ("\nAllocating data buffer...");
	buffer = (char *) malloc (mycamera.g_frame_size);
	
	if (buffer)
		printf ("OK\n");
	else
	{
		V4LWrapper_CloseCameraCapture (&mycamera);
		V4LWrapper_CloseOutputDisplay (&mydisplay);
		exit (0);
	}

	
	image = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U, 3);
	IplImage *gray = cvCreateImage (cvSize (width, height), IPL_DEPTH_8U, 1);

////////////////////////////////////////////////////////
	for(i=0;i<1000000;i++){
	    memset(buf,0,sizeof(buf));
	    read(dev_1,buf,3);
	    //TEST
	    retn = atoi(buf);
	    if(retn <0)// -value is error bit -> skip
		retn = VALUE_OF_DISTANCE;
	    //printf("ultra sensor: %d\n",retn);
	    //ADD PIR Sensor
	    if((retn<(VALUE_OF_DISTANCE-VALUE_MARGIN))||
		((VALUE_OF_DISTANCE+VALUE_MARGIN)<retn)){
	    //ULTRASENSOR VALUE HAS DIFFERENCE
	    //AND PIR Sensor Active=> OR connect
		V4LWrapper_QueryFrame (&mycamera,buffer);
		V4LWrapper_CvtColor (buffer, image->imageData, width, height, YUV422toRGB888);
		V4LWrapper_OutputDisplay (&mydisplay, buffer);
		read(dev_2,buf_pir,10);
		//printf("pir sensor: %s\n",buf_pir);	
		if(buf_pir[0] == '1'){//=> send_alart
		    printf("INVADED\n");
	            if(write(sockfd,"SOMEONE INVADED\n",16)!= 16)
		    	printf("str_echo: writen error\n");
		}
		else{ //-> ultrasensor value back to normal -> escape
		    printf("NO_MOVING,BUT SOMETHING WEIRD\n");	
	            if(write(sockfd,"MOVING STOPPED\n",15)!= 15)
		    	printf("str_echo: writen error\n");
		} 
	    } 
	//    else{
		//V4LWrapper_CloseCameraCapture (&mycamera);
		//V4LWrapper_CloseOutputDisplay (&mydisplay);
	//    }
	//  if(write(sockfd,buf, 3) != 3)
	//	printf("str_echo: writen error\n");
	//  write(sockfd,"\n",1);
	    //TO DO CONTROL PROGRAMS END SEQUENCE
	    /*
	    if(!strcmp(line,"QUIT\n")){
		//off all module
		//TO DO
		break;
	    }	
	    */
	    usleep(20000);
	}
	close(dev_1);
	close(dev_2);
	V4LWrapper_CloseCameraCapture (&mycamera);
	V4LWrapper_CloseOutputDisplay (&mydisplay);
	free(buffer);
	cvReleaseImage(&image);
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
