#include <stdio.h>
#include <stdlib.h>

/*
* Returns 1 if character c is lowercase, returns 0 otherwise.
*/
int is_lowercase(char c){
    if(c >= 'a' && c <= 'z'){
        return 1;
    }
    return 0;
}

/*
* Returns 1 if a word is only made from lower case letters, returns 0 otherwise.
*/
int is_word_lowercase(char* c){
    int i;
    int res = 1;
    for(i = 0; c[i]!='\0'; i++){
        if(is_lowercase(c[i]) == 0){
            res = 0;
        }
    }
    return res;
}


/*
* Returns 1 if the string is made only from numeric values.
*/
int is_positive_numeric(char* str){
     int i;
     for(i = 0; str[i]!='\0'; i++){
         if(str[i] > '9' || str[i] < '0'){
             return 0;
         }
    }
    return 1;
}


/*
* Converts a character to base 10 version.
*/
int char_to_10(char c){
    int i;
    i = c - 'a';
    return i;
}

/*
* Converts an entire string to base 10.
*/
void string_to_10(char* c){
    int i;
    for(i = 0; c[i]!='\0'; i++){
        printf("%d", char_to_10(c[i]));
    }
    putchar('\n');
}

/*
* Converts an int to base 26.
*/
void int_to_26(int i){
    while(i >= 26){
        printf("%d", i/26);
        i = i/26;
    }
}




int main(int argc, char* argv[]){

    if(is_word_lowercase(argv[1])){
        string_to_10(argv[1]);
    }
    else if(is_positive_numeric(argv[1])){
        int_to_26(atoi(argv[1]));
    }
    else{
        printf("Erreur ! Ni un entier positif, ni un mot en minuscule.\n");
    }

    return 0;
}