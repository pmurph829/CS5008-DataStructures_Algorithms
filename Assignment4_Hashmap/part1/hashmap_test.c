// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall hashmap_test.c -o hashmap_test
//
// Run with: ./hashmap_test
//
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <string.h> // for string comparison
// Our library that we have written.
// Also, by a really smart engineer!
#include "my_hashmap.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample collection of tests for your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.


// Tests creation and deletion of the hashmap
// Ideally does not cause any segfaults, and this
// is considered passing.
int unitTest1(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);    
    hashmap_delete(test);
    passed = 1;
    return passed;
}

// Tests has_key for a missing key
int unitTest2(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    
    if(hashmap_hasKey(test, "cow")==0){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}


// Tests insert and has_key
int unitTest3(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    
    if(hashmap_hasKey(test, "cow")==1){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

// Tests insert and has_key and remove key
int unitTest4(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_removeKey(test, "cow");
    
    if(hashmap_hasKey(test, "cow")==0){
      passed = 1;
    }
    
    hashmap_delete(test);

    return passed;
}

// Tests update_key
int unitTest5(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_update(test, "cow", "A common farm animal in Ohio.");
    
    if(hashmap_hasKey(test, "cow")==1){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

int unitTest6(int status){
    int passed = 1;
    hashmap_t* test = hashmap_create(3);
    hashmap_insert(test, "A", "bucket 1");
    hashmap_insert(test, "AA","bucket 2");
    hashmap_insert(test, "AAA", "bucket 0");
    hashmap_insert(test, "AAAA", "bucket 1, node 2");
    hashmap_insert(test, "AAAAA", "bucket 2, node 2");
    hashmap_insert(test, "AAAAAAA", "bucket 1, node 3");
    //print hashmap for comparison
    printf("Before Changes:\n");
    hashmap_printKeyValues(test);

    if (strcmp(hashmap_getValue(test, "AA"), "bucket 2")!=0){
        return 0;
    }
    if (strcmp(hashmap_getValue(test, "AAAA"), "bucket 1, node 2")!=0){
        return 0;
    }

    hashmap_update(test, "AA", "new bucket 2");
    hashmap_update(test, "AAAA", "bucket 1, new node 2");
    printf("\nAfter Update:\n");
    hashmap_printKeyValues(test);

    if (strcmp(hashmap_getValue(test, "AA"), "new bucket 2")!=0){
        return 0;
    }
    if (strcmp(hashmap_getValue(test, "AAAA"), "bucket 1, new node 2")!=0){
        return 0;
    }
    // Test remove key 
    hashmap_removeKey(test, "AAAA"); // remove middle list
    hashmap_removeKey(test, "AAA"); // remove only in list
    hashmap_removeKey(test, "A"); // remove first in list
    hashmap_removeKey(test, "AAAAA"); // remove end of list
    printf("\nAfter Remove:\n");
    hashmap_printKeyValues(test); // Ensure the hashmap can still be printed
    
    if (hashmap_hasKey(test, "A")==1){
        return 0;
    }
    if (hashmap_hasKey(test, "AAA")==1){
        return 0;
    }
    if (hashmap_hasKey(test, "AAAA")==1){
        return 0;
    }
    if (hashmap_hasKey(test, "AAAAA")==1){
        return 0;
    }

    hashmap_delete(test);
    return passed;
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
