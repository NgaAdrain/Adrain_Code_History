CC=gcc
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = hw9Main.o register.o print.o search.o delete.o sort.o
all = phonebook
%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $<
phonebook: $(OBJS)
	$(CC) -g -o phonebook $^
clean:
	rm -f phonebook $(OBJS)
