CC = gcc
LIB = -lsocket -lnsl

all : client
	
*.o : *.c
	$(CC) -I. -g -c $<

client : 
	$(CC) -g -o CLI client.o
clean :
	rm -f *.o CLI
