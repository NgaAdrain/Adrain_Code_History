#include "inet.h"
#include "echo.h"

int main(argc,argv) 
	int argc;
	char *argv[];
{
	int socketFD;
	struct sockaddr_in serv_addr, cli_addr;

	pname = argv[0];
	if((socketFD = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		printf("server : can't open datagram socket\n");
		exit(-1);
		}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERV_UDP_PORT);
	printf("Server opened\n");
	if(bind(socketFD, (struct sockaddr *) &serv_addr,sizeof(serv_addr))<0){
		printf("server : can't bind local address\n");
		exit(-1);	
		}
	printf("Server Bind address successfully\n");	
	dg_echo(socketFD, (struct sockaddr *) &cli_addr, sizeof(cli_addr));
}

		

