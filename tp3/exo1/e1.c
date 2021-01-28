#include <stdio.h>

int  puissance(int n, int p){
	int res;
	if(p == 0){
		res = 1;
		return res;
	}
	else if(p < 0){
		return -1;
	}
	else{
		int i;
		res = n;
		for(i = 1; i < p; i++){
			res = res * n;
		}
		return res;
	}
}

int main(int argc, char* argv[]){
	int p0 = puissance(2,0);
	int pMoinsUn = puissance(2, -1);
	int pSeize = puissance(4,2);
	printf("Doit retourner un 1 :%d \n ", p0);

	printf("Doit retourner un message d'erreur : %d \n", pMoinsUn);

	printf("Doit retourner le résultat de 4 puissance 2 : %d \n", pSeize);

	return 0;

}
