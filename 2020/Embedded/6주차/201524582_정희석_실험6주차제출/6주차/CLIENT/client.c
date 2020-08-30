#include "inet.h"
#define MAXLINE 512

int writen(register int fd, register char *ptr, register int nbytes);
int readline(register int fd, register char *ptr, register int maxlen);
void str_cli(register FILE *fp, register int sockfd);

int main(int argc,char *argv[]){
	int sockfd;
	struct sockaddr_in serv_addr;
	pname = argv[0];
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
	serv_addr.sin_port = htons(SERV_TCP_PORT);
	//printf("open socket...\n");
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	    printf("client : can't open stream socket\n");
	//printf("complete! connect...\n");	
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
//	    printf("client : can't connect to server\n");
//	    exit(0);
	
	printf("complete!\n");
	str_cli(stdin,sockfd);
	
	close(sockfd);
	exit(0);	
}
/////////////////////////////////
void str_cli(register FILE *fp,register int sockfd){
	int n;
	char sendline[MAXLINE], recvline[MAXLINE + 1];
	while(fgets(sendline, MAXLINE, fp) != NULL) {
	    n = strlen(sendline);
	    if(writen(sockfd, sendline, n) != n)
		printf("str_cli : written error on socket\n");
	    n = readline(sockfd, recvline, MAXLINE);
	    if(n < 0)
	 	printf("str_cli : reading error\n");
	    recvline[n] = 0;
	    fputs(recvline, stdout);
	    if(!strcmp(recvline,"QUIT\n"))
	    	break;
	}
	if(ferror(fp))
	    printf("str_cli : error reading file\n");
}
//////////////////////////////////////////////
int writen(register int fd, register char *ptr, register int nbytes){
	int nleft, nwritten;
	nleft = nbytes;
	while(nleft > 0) {
	    nwritten = write(fd, ptr, nleft);
	    if(nwritten <- 0)
		return nwritten;
	    nleft -= nwritten;
	    ptr += nwritten;
	}
	return nbytes-nleft; 
}
//////////////////////////////////////////////
int readline(register int fd, register char *ptr, register int maxlen){
	int n, rc;
	char c;
	for(n=1; n < maxlen; n++){
	    if((rc = read(fd, &c, 1)) == 1){
		*ptr++ = c;
		if(c== '\n') break;
	    }
	    else if(rc == 0){
		if(n == 1) return 0;	
	  	else break;
	    }
	    else
		return -1;
	}
	*ptr = 0;
	return n;
}
