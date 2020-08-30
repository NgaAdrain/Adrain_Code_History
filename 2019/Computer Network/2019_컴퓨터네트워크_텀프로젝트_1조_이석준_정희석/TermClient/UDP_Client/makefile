CC=gcc
LIB=-Lsocket -Lnsl
all : client
*.o : *.c
	$(CC) -I. -c $<

client : UDPclient.o dgcli.o
	$(CC) -g -o echocli UDPclient.o dgcli.o $(LIB)

clean :
	rm -f *.o echoserv echocli core
