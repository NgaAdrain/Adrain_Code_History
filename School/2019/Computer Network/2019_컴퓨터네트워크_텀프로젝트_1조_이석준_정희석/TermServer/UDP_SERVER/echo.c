#include "echo.h"

void dg_echo(sockfd, pcli_addr, maxclilen)
	int sockfd;
	struct sockaddr * pcli_addr;
	int maxclilen;
{
	int n, clilen;
	int count = 0;
	char mesg[MAXMESG];
	clock_t receive_time, send_time;
	printf("echo function\n");
	for(;;){
		clilen = maxclilen;
		printf("waiting...\n");
		n = recvfrom(sockfd, mesg, MAXMESG, 0, pcli_addr, &clilen);
		receive_time = clock();
		if(n<0){printf("dg_echo : recvfrom error\n");exit(-1);}
		send_time = clock();		
		if(sendto(sockfd, mesg, n, 0, pcli_addr,clilen) != n){
			printf("dg_echo : sendto error\n");
			exit(-1);
		}
		//printf("Receive %d Bytes \n > %s \n",n,mesg);
		printf("%d)Processing Time : %f \n",++count,(double)(send_time-receive_time));
		printf("%d Byte received\n",n);	
	}	
}


