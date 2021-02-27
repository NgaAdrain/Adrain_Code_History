#include <time.h>
#include "echo.h"
#include "readline.h"
void str_echo(sockfd)
	int sockfd;
{
	clock_t receive_timing, send_timing;
	int n;
	int count=0;
	char line[MAXLINE];
	
	for(;;){
		n = readline(sockfd, line, MAXLINE);
		receive_timing = clock();
		if(n == 0)
			return;
		else if(n<0)
			printf("str_echo : readline error");
		send_timing = clock();
		if(write(sockfd, line, n) != n)
			printf("str_echo: writen error");
		printf("%d) Processing Time : %f \n",++count,(double) (send_timing - receive_timing));	
		printf("RECEIVE : %d bytes \n ",n);//%ld \n %s \n",n,CLOCKS_PER_SEC,line);	
	}
}
