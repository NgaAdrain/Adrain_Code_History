CC = arm-none-linux-gnueabi-gcc 
LIB = -lsocket -lnsl

all : server 
	
*.o : *.c
	$(CC) -I. -g -c $<

server : 
	$(CC) -g -o SVR server.o 
clean :
	rm -f *.o SVR
