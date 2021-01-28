stackOne : main.o stack.o
	gcc -o stackOne main.o stack.o -Wall -ansi

stack.o : stack.c stack.h
	gcc -c stack.c -Wall -ansi

main.o : main.c stack.h
	gcc -c main.c -Wall -ansi
