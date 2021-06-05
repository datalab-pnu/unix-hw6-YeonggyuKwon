CC = gcc
CFLAGS = -g -Wall
OBJS = print.o register.o search.o delete.o sort.o hw6Main.o
all : main
%.o : %.c
	gcc -c -o $@ $(CFLAGS) $<
main : $(OBJS)
	gcc -o main $(OBJS)
clean:
	rm -f main $(OBJS)
