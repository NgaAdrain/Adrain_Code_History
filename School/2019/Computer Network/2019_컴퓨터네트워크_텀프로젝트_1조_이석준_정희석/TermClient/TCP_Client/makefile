CC=gcc
LIB=-Lsocket -Lnsl
all : client
*.o : *.c
	$(CC) -I. -c $<

client : TCPclient.o writen.o readline.o strcli.o
	$(CC) -g -o echocli TCPclient.o writen.o readline.o strcli.o $(LIB)

clean :
	rm -f *.o echoserv echocli core
