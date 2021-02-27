#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include "inet.h"

#define MAXMESG 4096

void dg_echo(int socketfd, struct sockaddr *pcli_addr, int maxclilen);
