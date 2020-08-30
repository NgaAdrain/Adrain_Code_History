#include "inet.h"
#include "dgcli.h"
void err_sys(const char *x){
	perror(x);
	exit(0);
}
void err_dump(const char *x){
	printf("%s",x);
	exit(-1);
}
int main(argc,argv)
int argc;
char *argv[];
{
	int sockfd;
	struct sockaddr_in serv_addr, cli_addr;
	pname = argv[0];
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
	serv_addr.sin_port = htons(SERV_TCP_PORT);
	printf("open datagram socket\n");
	if ((sockfd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
		err_sys("client : can't open datagram socket");
	printf("datagram socket opened\n");
	dg_cli(stdin, sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr));
	close(sockfd);
	exit(0);
}
