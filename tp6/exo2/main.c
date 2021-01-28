#include <stdio.h>
#include <stdlib.h>
#include "permutations.h"

#define n 3

int main(int argc, char* argv[]){

	int buffer[] = { 0,0,0,0,0};
	permutations(buffer, 1, n);
	return 0;
}