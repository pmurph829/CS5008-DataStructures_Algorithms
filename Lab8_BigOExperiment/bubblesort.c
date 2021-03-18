// Compile with: gcc -g bubblesort.c -o bubblesort
// Run with: time ./bubblesort

// C-Standard Libraries
#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions 

// Name:    swap
// Desc:    Swaps two numbers in an array
// Input:   The 'address of' an index into an 
//          array for positions in an array.
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address. 
//           This is the start of some 'contiguous block of memory' 
//           that we will sort.
// param(2)  'size' tells us how big the array of 
//           data is we are sorting.
// Output:   No value is returned, but 'array' should 
//           be modified to store a sorted array of numbers.
void bubblesort(int* array, unsigned int size){
    for(int i=0; i < size-1; i++){
        for(int j=0; j < size-i-1; j++){
            // Compare adjacent items
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
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
    bubblesort(random,numbers);
    // Confirm the sort worked
//    printIntArray(random,numbers);
//    printf("\n");

  
    // Free our random array
    free(random);

    return 0;
}
