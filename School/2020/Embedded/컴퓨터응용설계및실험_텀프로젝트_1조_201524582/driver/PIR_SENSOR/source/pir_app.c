#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
        int fd;
        int retn;
        char buf[10] = {0};
        int loop = 0;

        fd = open("/dev/pir", O_RDWR);
        printf("fd = %d\n", fd);

        if(fd<0){
                perror("/dev/pir error");
                exit(-1);
        }else{
                printf("< pir device has been detected >\n");
        }

        while(1){
                read(fd,buf,10);
		printf("%s",buf);
		if(buf[0] == '1')
		{
			printf("< Detected >\n");
		} else if(buf[0] == '0') {
			printf("< Searching >\n");
		} 
                for(loop = 0; loop < 1000000; loop++) {};
        }

        close(fd);

        return 0;

}

