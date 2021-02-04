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

void print_test(queue_t* testQ_p, 
		unsigned int expectCap,
		unsigned int expectBack,
		unsigned int expectFront,
		unsigned int expectSize){
	//Print out data on a queue for testing.
	printf("\n\nNew Test:\n");
	printf("capacity: %d. Should be %d\n", testQ_p->capacity, expectCap);
	printf("back: %d. Should be %d\n", testQ_p->back, expectBack);
	printf("front: %d. Should be %d\n", testQ_p->front, expectFront);
	printf("size: %d. Should be %d\n", testQ_p->size, expectSize);
}

void unitTest2(){
	//Test the create_queue function
	queue_t* test2 = create_queue(5);
	print_test(test2, 5, 4, 0, 0); 
	free_queue(test2);
}

void unitTest3(queue_t* test3){
	//test enqueue
	queue_enqueue(test3, 0);
	queue_enqueue(test3, 1);
	print_test(test3, 5, 1, 0, 2);
	queue_enqueue(test3, 2);
	queue_enqueue(test3, 3);
	queue_enqueue(test3, 4);
	print_test(test3, 5, 4, 0, 5);
	printf("Show that data is not overwritten and full is 1\n");
	queue_enqueue(test3, 5);
	print_queue(test3);
	
}

void unitTest4(queue_t* test4){
	//test dequeue
	print_dequeue(test4);
	print_dequeue(test4);
	print_dequeue(test4);
	print_test(test4, 5, 4, 3, 2);
	print_dequeue(test4);
	print_dequeue(test4);
	print_test(test4, 5, 4, 0, 0);
	
	// Re-enable line below to ensure program exits
	//print_dequeue(test4);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	queue_t* newQ = create_queue(5);
	unitTest1();
	unitTest2();	
	unitTest3(newQ);
	unitTest4(newQ);
	
	//Use valgrind to check for leaks
	free_queue(newQ);
	return 0;
}







