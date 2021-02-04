// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}

void print_queue(queue_t* q){
	printf("empty: %d\n",queue_empty(q));
        printf("full: %d\n",queue_full(q));
        printf("size: %d\n",queue_size(q));

	int i = 0;
	for (i; i < q->capacity; i++){
		printf("%d\n", q->data[i]);
	}
}

void print_dequeue(queue_t* q){
	printf("Dequeued: %d\n",queue_dequeue(q));
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	//unitTest1();
	queue_t* newQ = create_queue(5);
	queue_t* qTwo = create_queue(1);
	print_queue(qTwo);	
	queue_enqueue(newQ, 0);
        queue_enqueue(newQ, 1);
	//print_queue(newQ);
	print_dequeue(newQ);
	//print_queue(newQ);
	queue_enqueue(newQ, 2);
	queue_enqueue(newQ, 3);
	queue_enqueue(newQ, 4);
	//queue_enqueue(newQ, 5);
	
	//print_queue(newQ);

	print_dequeue(newQ);
	print_dequeue(newQ);
	print_dequeue(newQ);
	print_dequeue(newQ);
        queue_enqueue(newQ, 5);
        queue_enqueue(newQ, 6);
        queue_enqueue(newQ, 7);
	queue_enqueue(newQ, 8);
	print_dequeue(newQ);
	print_queue(newQ);
	
	free_queue(newQ);
	free_queue(qTwo);	
	return 0;
}







