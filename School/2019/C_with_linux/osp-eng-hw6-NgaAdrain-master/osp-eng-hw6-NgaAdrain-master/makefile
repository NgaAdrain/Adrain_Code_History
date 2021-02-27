CC=gcc
CFLAGS = -Wall -g -c
INCLUDE = -I.

OBJS = phoneBookMain.o register.o print.o search.o delete.o
all = phonebook
%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $<
phonebook: $(OBJS)
	$(CC) -o phonebook $^
fdebug: $(OBJS)
	$(CC) -g -o phonebook_g $^
clean:
	rm -f phonebook $(OBJS)
