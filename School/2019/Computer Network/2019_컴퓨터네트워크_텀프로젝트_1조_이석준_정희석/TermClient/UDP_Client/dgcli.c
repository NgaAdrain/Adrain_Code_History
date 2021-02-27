#include "dgcli.h"

void dg_cli(fp, sockfd,pserv_addr,servlen)
FILE *fp;
int sockfd;
struct sockaddr *pserv_addr;
int servlen;
{	
	struct timeval timeout;
	int n,sendThousand = 0,sendCount = 0 ,timeouts, lost = 0;
	char sendline[MAXLINE], recvline[MAXLINE + 1];
	clock_t send_start, send_end, receive_end;
	clock_t sendTime, receiveTime;
	fgets(sendline, MAXLINE, fp);
	if (ferror(fp))
		err_sys("dg_cli : error reading file");
	n = strlen(sendline);
	fd_set rfds;
	for (sendThousand; sendThousand < 1000; sendThousand++){
		FD_ZERO(&rfds);
		FD_SET(sockfd,&rfds);
		timeout.tv_sec = 0;
		timeout.tv_usec = 76500;
		send_start = clock();
		if (sendto(sockfd, sendline, n,0, pserv_addr,servlen) != n )
			err_dump("dg_cli : sendto error on socket");
		send_end = clock();
		if (timeouts = select(sockfd+1,&rfds,NULL,NULL,&timeout) == 0){
			lost++;
			printf("%dlost!\n",sendThousand);
		}
		else {
			n = recvfrom(sockfd, recvline, MAXLINE, 0,
				(struct sockaddr *) 0,(int *)0);
			if (n < 0)
				err_dump("dg_cli : recvfrom error");
			receive_end = clock();
			recvline[n] = 0;
			//fputs(recvline,stdout);
			sendTime += send_end - send_start;
			receiveTime += receive_end - send_end;
			sendCount++;
		}
	}
	sendTime = sendTime/(double)1000;
	receiveTime = receiveTime/(double)sendCount;
	printf("Average Send time is : %fms\n",(double)(sendTime/1000.0));
	printf("Average receive time is : %fms\n",(double)(receiveTime/1000.0));
	printf("sendCount : %d \n",sendCount);
	printf("lost : %d \n",lost);
}
