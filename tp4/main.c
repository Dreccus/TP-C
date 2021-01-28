#include "stack.h"
#include "stdio.h"

/* Function to display the current state of the */
void stack_state(){
	printf("Current state of the stack : ");
	stack_display();
	printf("\n");
}

int main(int argc, char *argv[]){
	struct stack st1;

	/*Intialization of the stack */
	stack_init();

	printf("******************* TESTS ON AN EMPTY STACK ******************* \n\n");

	/* Checking if the stack is empty*/
	printf("Checking if the stack is empty, should display 1 : %d \n\n", stack_is_empty());

	/* Double check with a display of stack.size */
	printf("Double checking by printing the current size of the stack, should display 0 : %d \n\n", stack_size());
	
	/* Checking that the top of the stack is currently not set */
	printf("top of the stack : %d \n\n", stack_top());

	/* Testing the stack_display() fuction*/
	stack_state();
	/*printf("Displaying the stack, should print empty brackets: \n");
	stack_display();*/

	/*Testing stack_pop() on empty stack*/
	printf("Pop top of the stack. if stack is empty, should display -1 : %d \n\n", stack_pop());

	stack_state();

	printf("******************* TESTS ON A NON EMPTY STACK ******************* \n\n");

	int i;
	for(i=2; i<9; i+=2){
		stack_push(i);
	}
	printf("Pushed 2,4,6,8 on top of the stack \n\n");
	stack_state();

	/* Checking if the stack is empty.*/
	printf("Checking if the stack is EMPTY, should display 0 : %d \n\n", stack_is_empty());

	/* Checking the size of the stack after adding 4 elements.*/
	printf("Checking the SIZE of the stack, should display 4 : %d \n\n", stack_size());

	/* Checking the top of the stack.*/
	printf("Checking the TOP of the stack, should display 8 : %d \n\n", stack_top());

	/*Testing stack_pop() on non empty stack.*/
	printf("Popped the top of the stack, should display 8 : %d \n\n", stack_pop());

	stack_state();

	printf("Testing stack_get_element() with 2 as index, should display 6 : %d \n\n", stack_get_element(2));

	printf("The state of the stack shouldn't have changed.\n\n");
	stack_state();

	printf("New SIZE of the stack : %d \n\n", stack_size());

	printf("******************* TESTS ON A FULL STACK ******************* \n\n");

	printf("Resetting the stack to an EMPTY stack\n");
	stack_init();
	/* Checking if the stack is empty*/
	printf("Checking if the stack is EMPTY, should display 1 : %d \n\n", stack_is_empty());

	for(i=11; i<26; i++){
		stack_push(i);
	}
	printf("Pushed 15 integers on top of the stack, from 11 to 25. \n\n");
	stack_state();

	/* Checking the size of the stack after adding 15 elements.*/
	printf("Checking the SIZE of the stack, should display 15 : %d \n\n", stack_size());

	printf("Pushing 26 on top of the stack, should display a WARNING \n");
	stack_push(26);

	/* Checking the top of the stack.*/
	printf("Checking the TOP of the stack, should display 25 : %d \n\n", stack_top());

	/*Testing stack_pop() on non empty stack.*/
	printf("Popped the top of the stack, should display 25 : %d \n\n", stack_pop());

	stack_state();

	/* Checking the top of the stack after popping it.*/
	printf("Checking the TOP of the stack, should display 24 : %d \n\n", stack_top());

	/* Checking the size of the stack after popping the top.*/
	printf("Checking the SIZE of the stack, should display 14 : %d \n\n", stack_size());

	printf("Pushing 25 back on top of the stack.\n\n");
	stack_push(25);
	stack_state();

	printf("Testing stack_get_element() with 10 as index, should display 21 : %d \n\n", stack_get_element(10));

	printf("The state of the stack shouldn't have changed.\n\n");
	stack_state();

	return 0;
}