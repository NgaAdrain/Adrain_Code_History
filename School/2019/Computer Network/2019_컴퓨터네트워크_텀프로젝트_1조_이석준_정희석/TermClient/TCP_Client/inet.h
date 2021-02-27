#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERV_UDP_PORT 25555
#define SERV_TCP_PORT 25555
#define SERV_HOST_ADDR "36.38.143.54"
char *pname;


void err_sys(const char *x);
void err_dump(const char *x);
