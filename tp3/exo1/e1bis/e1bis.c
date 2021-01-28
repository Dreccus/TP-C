#include <stdio.h>

int puissancerec(int n0, int n, int p, int cnt){
	int res;
	if(p == 0){
		res = 1;
		return res;
	}
	else if(p < 0){
		return -1;
	}
	else {
		res = n;
		if(cnt != p){
			n = n*n0;
			puissancerec( n0, n, p, cnt+1);
		}
		else{
			return res;
		}
	}
}

int realPuissance_rec(int n, int p){
	int n0 = n;
	int count = 1;
	return puissancerec(n0, n, p, count);
}

int main(int argc, char* argv[]){

	printf("4 puissance 2  : %d\n", realPuissance_rec(4,2));
	printf("20 puissance 5 : %d\n", realPuissance_rec(20,5));
	printf("1 puissance 56 : %d\n", realPuissance_rec(1,56));
	printf("0 puissance 30 : %d\n", realPuissance_rec(0,30));

	return 0;
}
