// Compile with: gcc -g csort.c -o csort
// Run with: time ./csort

// C-Standard Libraries
#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions 

// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//          
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}



// Name:    printIntArray
// Desc:    Prints out an integer array
// param(1):A pointer to an array (i.e. the array 
//          itself points to the first index)
// param(2) The size of the array (Because we do 
//          not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
    // Note: 'unsigned int' is a datatype for storing positive integers.
    unsigned int i;
    for(i = 0; i < size; i=i+1){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(){
  

    // Generate a big random data set
    const int numbers = 10000;
    // Generate a random seed
    time_t t;
    srand((unsigned)time(&t));
    // Allocate memory
    int* random = (int*)malloc(sizeof(int)*numbers);

    // Populate our test data set
    for(int i=0; i < numbers;i++){
        // Generate random values from 0 to 99
        random[i] = rand()%numbers; 
    }

// You can uncomment if you'd like to see the numbers sorted
//    Before the sort
//    printIntArray(random,numbers);
//    printf("\n");
    // Perform the sort
    qsort(random,numbers,sizeof(int),compare);
    // Confirm the sort worked
//    printIntArray(random,numbers);
//    printf("\n");

  
    // Free our random array
    free(random);

    return 0;
}
