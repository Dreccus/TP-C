permutations : main.o permutations.o
	gcc -o permutations main.o permutations.o -Wall -ansi

permutations.o : permutations.c permutations.h
	gcc -c permutations.c -Wall -ansi

main.o : main.c permutations.h
	gcc -c main.c -Wall -ansi
