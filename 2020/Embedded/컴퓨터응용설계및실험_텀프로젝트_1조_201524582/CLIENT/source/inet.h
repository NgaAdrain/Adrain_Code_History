#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERV_TCP_PORT 25555
#define SERV_HOST_ADDR "192.168.10.125"

char *pname;
