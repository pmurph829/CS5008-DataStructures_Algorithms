// Compile this assignment with: gcc main.c -o main
//
// This is a great assignment to practice debugging.
// First compile with debugging symbols
// Compile with: clang -g main.c my_bst.c -o main
// Run with: gdb ./main --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// You may add as many unit tests as you like here
// A few have been provided for your convenience.
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Function to create a filled bst
bst_t* fill_bst(){
    bst_t* testBST = bst_create();
    bst_add(testBST, 21);
    bst_add(testBST, 28);
    bst_add(testBST, 14);
    bst_add(testBST, 11);
    bst_add(testBST, 25);
    bst_add(testBST, 18);
    bst_add(testBST, 5);
    bst_add(testBST, 15);
    bst_add(testBST, 32);
    bst_add(testBST, 27);
    bst_add(testBST, 30);
    return testBST;
}

// Testing allocation
int unitTest1(){
    int result;
    bst_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}

// Add and find a node
int unitTest2(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST,78);
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Sums the nodes in a BST
int unitTest3(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==5){ 
        return 1;
    }
    return 0;
}

int unitTest4(){
    int size;
    bst_t* testBST = fill_bst();
    printf("Printing bst (ascending, descending)\n");
    bst_print(testBST, 0);
    bst_print(testBST, 1);
    size = bst_size(testBST);
    bst_free(testBST);

    if (size == 11) {
        return 1;
    }
    return 0;
}

int unitTest5() {
    int sum;
    bst_t* bst = fill_bst();
    sum = bst_sum(bst);
    bst_free(bst);
    if (sum == 226) {
        return 1;
    }
    return 0;
}

int unitTest6() {
    bst_t* bst = fill_bst();
    if (bst_find(bst, 21) != 1) {
        return 0;
    }
    if (bst_find(bst, 28) != 1) {
        return 0;
    }
    if (bst_find(bst, 18) != 1) {
        return 0;
    }
    if (bst_find(bst, 27) != 1) {
        return 0;
    }
    if (bst_find(bst, 45) != 0) {
        return 0;
    }
    bst_free(bst);
    return 1;
}


// TODO: Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
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
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}
