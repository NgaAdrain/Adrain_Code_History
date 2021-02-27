CC=gcc
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = empMain.o register.o print.o search.o save.o
all = employee 
%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $<
employee: $(OBJS)
	$(CC) -g -o employee $^
clean:
	rm -f employee $(OBJS)
