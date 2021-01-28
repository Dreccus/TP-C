#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void triBulle(int t[]){
	int i;
	int j;
	int tampon;
	for(i = SIZE; i >= 1; i--){
		for(j = 0; j <= i-1; j++){
			if(t[j] > t[j+1]){
				tampon = t[j];
				t[j] = t[j+1];
				t[j+1] = tampon;
			}
		}
	}
}


void fillArray(int t[]){
	int i = 0;
	for(i = 0; i <= SIZE; i++){
		t[i] = rand() % 100;
	}
}
/*Ici choix entre multiplier les printf ou remplir une chaîne au fur et à mesure*/
void printIntArray(int t[]){
	printf("{");
	int i;
	for(i = 0; i < SIZE-1; i++){
		printf(" %d,", t[i]);
	}
	printf(" %d}\n", t[SIZE]);
}
/* choix de multiplier les printf mais dans une fonction pour la lisbilité du main*/

void printTest(int n, int t[]){
	printf("t%i avant tri :", n); 
	printIntArray(t);
	triBulle(t);
	printf("t%i après tri :", n);
	printIntArray(t);
	printf("\n");
}

int main(int argc, char* argv[]){

	srand(time(NULL));
				/*Remplissage des tableaux*/
	int t1[SIZE];
	fillArray(t1);

	int t2[SIZE];
	fillArray(t2);

	int t3[SIZE];
	fillArray(t3);

	int t4[SIZE];
	fillArray(t4);

	int t5[SIZE];
	fillArray(t5);

				/*Affichage avant/après du tri des tableaux*/
	printTest(1, t1);
	printTest(2, t2);
	printTest(3, t3);
	printTest(4, t4);
	printTest(5, t5);

	/*printf("t1 avant tri :"); 
	printIntArray(t1);
	triBulle(t1);
	printf("t1 après tri :");
	printIntArray(t1);
	printf("\n");

	printf("t2 avant tri :"); 
	printIntArray(t2);
	triBulle(t2);
	printf("t2 après tri :");
	printIntArray(t2);
	printf("\n");

	printf("t3 avant tri :"); 
	printIntArray(t3);
	triBulle(t3);
	printf("t3 après tri :");
	printIntArray(t3);
	printf("\n");

	printf("t4 avant tri :"); 
	printIntArray(t4);
	triBulle(t4);
	printf("t4 après tri :");
	printIntArray(t4);
	printf("\n");

	printf("t5 avant tri :"); 
	printIntArray(t5);
	triBulle(t5);
	printf("t5 après tri :");
	printIntArray(t5);
*/
	return 0;
}