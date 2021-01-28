#include <stdio.h>

int main(int argc, char* argv[]){
	FILE * f = fopen("e5.c","r");
	int ch;

	do{
	ch = fgetc(f);
	if(feof(f) ){
	  break;
	}
	printf("%c", ch);
	}while(1);

	fclose(f);
	return(0);

}
