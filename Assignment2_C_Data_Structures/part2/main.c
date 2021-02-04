// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void print_stack(stack_t* s){
        printf("Size = %d\n", stack_size(s));
        node_t* itr = s->head;
        while(itr != NULL){
                printf("%d\n", itr->data);
                itr = itr->next;
        }
}


void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	print_stack(test1);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);
	print_stack(test1);
	printf("Attempting to push 2, 3, 4, 5");
	stack_enqueue(test1, 2);
	stack_enqueue(test1, 3);
	stack_enqueue(test1, 4);
	stack_enqueue(test1, 5);
	print_stack(test1);	
	printf("Removing: %d\n",stack_dequeue(test1));	
	print_stack(test1);
	free_stack(test1);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();

	return 0;
}
