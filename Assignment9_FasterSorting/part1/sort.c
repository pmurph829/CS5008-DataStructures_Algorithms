// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
// Name: merge
// Inputs: (1) arr[] is the array to be sorted.
//         (2) l is the leftmost index of the first subarray.
//         (3) m is the midpoint between the two subarrays.
//              m is also the last index of the first subarray.
//         (4) r is the last index of the second subarray.
//Returns: Nothing is returned, but the section of arr from index = l to index = r
//should be sorted after this function is called.
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    // length1 is the length of the first (right) array
    int length1 = m - l + 1;
    // length2 is the length of the second (left) array
    int length2 = r - m;

    int L[length1];
    int R[length2];
    
    // fill in the left subarray 
    for (i = 0; i < length1; i++) {
        L[i] = arr[l + i];
    }
    // fill in the right subarray
    for (j = 0; j < length2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    // traverse each subarray and compare elements to build the sorted array.
    while (i < length1 && j < length2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // If the right subarray is empty, add the rest of the left subarray
    // to the sorted array.
    while (i < length1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // If the left subarray is empty, add the rest of the right subarray
    // to the sorted array.
    while (j < length2) {
        arr[k] = R[j];
        j++;
        k++;
    }
 }


// Implement your mergeSort function here
// Name: mergeSort
// Inputs: (1) array[] is a pointer to the array to be sorted.
//         (2) l is the leftmost index of the array to be sorted.
//         (3) r is the rightmost index of the array to be sorted.
// Returns: Nothing is returned from this function, but array should be sorted
// after the function is called. 
void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        
        merge(array, l, m, r);
    }
}

// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
    mergeSort(array, 0, size-1);
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
