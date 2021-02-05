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
        printf("Capacity: %d\nCount: %d\n", s->capacity, s->count);
	printf("Empty: %d Full: %d\n\n", stack_empty(s), stack_full(s));
        node_t* itr = s->head;
        while(itr != NULL){
                printf("%d ", itr->data);
                itr = itr->next;
        }
        printf("\n\n");
}


void print_push(stack_t* s, int item){
        int success = stack_enqueue(s, item);
        printf("Attempted push: %d\n", item);
        printf("success: %d\n", success);
}

void print_pop(stack_t* s){
        int item = stack_dequeue(s);
        printf("Attempted pop: %d\n", item);
}


void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	print_stack(test1);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);
	print_stack(test1);
	printf("Attempting to push 2, 3, 4, 5\n");
	stack_enqueue(test1, 2);
	stack_enqueue(test1, 3);
	stack_enqueue(test1, 4);
	stack_enqueue(test1, 5);
	print_stack(test1);	
	printf("Removing: %d\n",stack_dequeue(test1));	
	print_stack(test1);
	free_stack(test1);
}

void unitTest2(stack_t* s){
	print_push(s, 0);
        print_push(s, 1);
        print_push(s, 2);
        // Add to full stack
        print_push(s, 3);
        print_push(s, 4);
        print_stack(s);
}

void unitTest3(stack_t* s){
	print_pop(s);
        print_pop(s);
        print_pop(s);
        print_stack(s);
        //print_pop(s);
}

void unitTest4(stack_t* s){
	int i = 0;
	for(i; i < 3; i++){
		print_push(s, i);
	}
	i = 0;
	for(i; i < 3; i++){
		print_pop(s);
	}
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	stack_t* s = create_stack(3);
	
	//unitTest1();
	//unitTest2(s);
	//unitTest3(s);
	unitTest4(s);
	free_stack(s);
	return 0;
}








