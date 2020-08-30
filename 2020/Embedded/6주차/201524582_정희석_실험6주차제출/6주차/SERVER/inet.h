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

#include "./fpga_dot_font.h"

#define SERV_TCP_PORT 25555
#define SERV_HOST_ADDR "127.0.0.1"

#define MAX_BUTTON 9
#define DOT_OUT_A 0
#define DOT_OUT_P 1

char *pname;
