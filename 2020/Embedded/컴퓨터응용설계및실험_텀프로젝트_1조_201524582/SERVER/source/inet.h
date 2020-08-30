#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include <malloc.h>

#define SERV_TCP_PORT 25555
#define SERV_HOST_ADDR "127.0.0.1"
//configuration
#define VALUE_OF_DISTANCE 90 
#define VALUE_MARGIN 9 

char *pname;
