CC=gcc
INCLUDE = -I.
OBJS=UDP_Server.o echo.o
LIB = -Lsocket -Lnsl
all : server

*.o : *.c
	$(CC) $(INCLUDE) -g -c $<

server : $(OBJS)
	$(CC) -g -o UDPSERVER.exe $(OBJS) $(LIB)
clean : 
	rm -f *.o UDPSERVER.exe
	
