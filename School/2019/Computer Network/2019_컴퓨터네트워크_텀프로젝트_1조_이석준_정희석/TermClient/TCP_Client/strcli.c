#include "strcli.h"
#include "writen.h"
#include "readline.h"
void str_cli(fp, sockfd)
register FILE *fp;
register int sockfd;
{
	int n, sendCount = 0;
	clock_t sendTime = 0, receiveTime = 0;
	char sendline[MAXLINE], recvline[MAXLINE + 1];
	clock_t send_start, send_end,receive_end ;
	int sendThousand = 0;
	fgets(sendline, MAXLINE, fp);
	if (ferror(fp))
		err_sys("str_cli : error reading file");
	n = strlen(sendline);
	for (sendThousand; sendThousand < 1000 ; sendThousand++){
		send_start = clock();//
		if (writen(sockfd, sendline, n) != n )
			err_sys("str_cli : written error on socket");
		send_end = clock();//
		n = readline(sockfd, recvline, MAXLINE);
		if (n < 0)
			err_dump("str_cli : reading error");
		receive_end = clock();//
		recvline[n] = 0;
		sendTime += (send_end - send_start);
		receiveTime += (receive_end - send_end);
		//fputs(recvline,stdout);
		sendCount++;
	}
	sendTime = sendTime/1000.0;
	receiveTime = receiveTime/1000.0;
	printf("Average Send time is : %fms\n",(double)(sendTime/1000.0));
	printf("Average receive time is : %fms\n",(double)(receiveTime/1000.0));
	printf("sendCount : %d \n",sendCount);	
}
