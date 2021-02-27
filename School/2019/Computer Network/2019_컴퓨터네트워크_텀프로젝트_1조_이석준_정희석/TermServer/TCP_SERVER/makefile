CC=gcc
INCLUDE = -I.
OBJS=TCP_Server.o echo.o readline.o
LIB= -Lsocket -Lnsl
all : server

*.o : *.c
	$(CC) $(INCLUDE) -g -c $<

server : $(OBJS)
	$(CC) -g -o TCPSERVER.exe $(OBJS)
clean : 
	rm -f *.o TCPSERVER.exe
	
