# _*_ Makefile _*_

all: stack

stack: stack.o main.o
	gcc stack.o main.o -o stack

stack.o: stack.c stack.h
	gcc -c stack.c stack.h -o stack.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm *.o stack

