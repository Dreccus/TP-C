#include "stack.h"
#include "stdio.h"

/* This module proposes a single global and static stack */
static Stack stack;

/* Initialize correctly the stack */
void stack_init(void){
	stack.size = 0;
	int i;
	for(i=0; i<15; i++){
		stack.values[i]= '\0';
	}
}

/* Returns the current size of the stack. */
int stack_size(void){
	return stack.size;
}

/* Returns 1 if the stack is empty, returns 0 otherwise .*/
int stack_is_empty(void){
	return stack.size == 0;
}

/* Returns the element at the top of the stack. Returns -1 if the stack si empty **************PORTFOLIO******** */
int stack_top(void){
	if(stack_is_empty() == 1){
		return -1;
	}
	else{
		return stack.values[stack.size-1];
	}
}

/* Pops the element at the top of the stack and returns it. Returns -1 if stack is empty*/
int stack_pop(void){
	if(stack_is_empty() == 1){
		return -1;
	}
	int top = stack_top();
	stack.values[stack.size-1] = '\0';
	stack.size -= 1;
	return top;
	/*tester si stack.values[stack.size-1] passe au lieu de stack_top()*/
}

/* Push a given integer 'n' at the top of the stack. */
void stack_push(int n){/* ***********PORFOLIO******** initializes at 0 if pushed au dessus de l'index le plus bas*/
	if(stack.size >= 15){
		printf("STACK IS FULL. POP ELEMENT BEFORE PUSHING.\n");
	}
	else{
		stack.values[stack.size] = n;
		stack.size += 1;
	}
}

/* Displays the content of the stack on the standard output. */ /* ************PORTFOLIO************ added empty management */
void stack_display(void){
	if(stack_is_empty() == 1){
		printf("[ ]\n");
	}
	else{
		int i;
		printf("[ "); /* Prints a comma after each value*/
		for(i = 0; i < stack.size-1; i++){
			printf("%d, ", stack.values[i]);
		}

		printf("%d] \n", stack.values[stack.size-1]); /* Prints the last value without a comma and closes the brackets*/
	}
}

/* Returns the element at index 'index' inside the stack. The user is 
   responsible for the use of this function. The answers may not be 
   relevant if a call is done outside the currnet size of the 
   stack. */
int stack_get_element(int index){
	return stack.values[index];
}  
/* voir pour la refaire plus tard en faisant en sorte qu'elle mette une erreur ptet un truc comme ça*/
