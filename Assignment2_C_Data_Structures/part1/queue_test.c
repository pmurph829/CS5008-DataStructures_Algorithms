// Compile this assignment with:
// gcc queue_test.c -o queue_test
//
// Run with: ./queue_test
//
// This is a way to test your code.
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
int unitTest1(int status){
    printf("========queue unitTest1========\n");
    queue_t* test1 = create_queue(1);
    queue_enqueue(test1,1);
    queue_dequeue(test1);

    free_queue(test1);
    return 1;
}

// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
int unitTest2(int status){
    printf("========queue unitTest2========\n");
    queue_t* test2 = create_queue(10);
    queue_enqueue(test2,1);
    queue_enqueue(test2,2);
    queue_enqueue(test2,3);
    queue_enqueue(test2,4);
    queue_enqueue(test2,5);
    queue_enqueue(test2,6);
    queue_enqueue(test2,7);
    queue_enqueue(test2,8);
    queue_enqueue(test2,9);
    queue_enqueue(test2,10);

    free_queue(test2);

    return 1;
}

int unitTest3(int status){
    printf("========queue unitTest3========\n");
    queue_t* test3 = create_queue(32);
    int i =0;
    for(i=0; i < 32; i++){
        queue_enqueue(test3,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(test3);
    }

    free_queue(test3);

    return 1;
}

int unitTest4(int status){
    printf("========queue unitTest4========\n");
    queue_t* test4 = create_queue(32);
    int i =0;
    for(i=0; i < 32; i++){
        queue_enqueue(test4,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(test4);
    }
    for(i=0; i < 32; i++){
        queue_enqueue(test4,1);
    }
    for(i=0; i < 32; i++){
        queue_dequeue(test4);
    }
    free_queue(test4);

    return 1;
}

int unitTest5(int status){
    printf("========queue unitTest5========\n");

    queue_t* test5 = create_queue(30);
    free_queue(test5);

    return 1;
}

// TODO: Add more tests here
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    NULL
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter]!=NULL){
        unitTests[counter](1);
        counter++;
    }

    return 0;
}
