#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_UDP_PORT 25555
#define SERV_TCP_PORT 25555
#define SERV_HOST_ADDR "127.0.0.1"
char *pname;
