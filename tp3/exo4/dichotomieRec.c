#include <stdio.h>

int dichotomieRec(int t[], int lo, int hi, int elt){
	int mid = (hi +lo)/2;
	if(lo > hi || hi < lo){
		return -1;
	}
	else if(t[mid] > elt){
		return dichotomieRec(t, lo, mid-1, elt);
	}
	else if(t[mid] < elt){
		return dichotomieRec(t, mid+1, hi, elt);
	}
	else{
		return mid;
	}
}









int main(int argc, char* argv[]){
	int t1[] = {0,1,2,3,4,5,6,7,8,9};

	printf("L'index auquel on trouve 9 dans t est : %d\n", dichotomieRec(t1, 0, 9, 9));
	printf("L'index auquel on trouve 6 dans t est : %d\n", dichotomieRec(t1, 0, 9, 6));
	printf("L'index auquel on trouve 2 dans t est : %d\n", dichotomieRec(t1, 0, 9, 2));
	printf("L'index auquel on trouve 36 dans t est : %d\n", dichotomieRec(t1, 0, 9, 36));

	int t2[] = { 12, 13, 19, 26, 50, 61, 80, 91, 118, 218};

	
	printf("L'index auquel on trouve 9 dans t est : %d\n", dichotomieRec(t2, 0, 9, 12));
	printf("L'index auquel on trouve 6 dans t est : %d\n", dichotomieRec(t2, 0, 9, 50));
	printf("L'index auquel on trouve 2 dans t est : %d\n", dichotomieRec(t2, 0, 9, 118));
	printf("L'index auquel on trouve 36 dans t est : %d\n", dichotomieRec(t2, 0, 9, 20000));	

	return 0;
}