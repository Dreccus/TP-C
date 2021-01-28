#include <stdio.h>
#include <stdlib.h>
#include "permutations.h"

void print_array(int* array, int size){
	int i;
	
	if(size == 1){
		printf("[%d]\n", array[0]);
	}
	else{
	printf("[");
	for(i = 0; i < size-1; i++){
		printf(" %d,", array[i]);
	}
	printf(" %d]\n", array[size-1]);
	}
}

void permutations(int buffer[], int current, int max){
	int i;
	if(current > max){
		print_array(buffer, max);
	} 
	for(i = 0; i < max; i++){
		if(buffer[i] == 0){
			buffer[i] = current;
			permutations(buffer, current+1, max);
			buffer[i] = 0;
		}
	}
}