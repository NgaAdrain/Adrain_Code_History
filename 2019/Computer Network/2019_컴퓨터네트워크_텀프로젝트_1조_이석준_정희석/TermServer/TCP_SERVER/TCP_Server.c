#include "inet.h"
#include "echo.h"

void main(argc, argv)
	int argc;
	char *argv[];
{
	int socketFD, newsocketFD, clilen, childpid;
	struct sockaddr_in cli_addr, serv_addr;
	pname = argv[0];
	if((socketFD = socket(AF_INET, SOCK_STREAM, 0)) <0){
		printf("server : can't open stream socket\n");
		exit(-1);
	}
	bzero((char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons (SERV_TCP_PORT);
	printf("Socket Opened\n");
	if(bind (socketFD, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0){
		printf("server : can't bind local address\n");
		exit(-1);
	}
	printf("waiting...\n");
	listen(socketFD, 5);
	for(;;){
		clilen = sizeof(cli_addr);
		printf("open client socket\n");	
		newsocketFD = accept(socketFD, (struct sockaddr *)&cli_addr, &clilen);
		if(newsocketFD <0){
			printf("server : accept error\n");
			exit(-1);
		}
		if((childpid=fork())<0){
			printf("server : fork error\n");
			exit(-1);
		}
		else if(childpid == 0){
			close (socketFD);
			str_echo(newsocketFD);
			printf("finish successfully\n");
			exit(0);
		}
		close(newsocketFD);
	}
}	

