// Compile with: clang fib.c -o fib
// Run with: ./fib
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The largest fibonacci number we will compute
// This will also be the size of our 'lookup table' of previously
// computed values.
#define LARGEST_FIB_NUMBER 50

// Implement the recursive version of fibonacci here.
long fibonacci(int n){
    // TODO:
    return 0;
}

// Store our previous 'memoized' values
// This table will be used for the 'dyn_fibonacci' function to store
// previously computed values.
long memo[LARGEST_FIB_NUMBER];

// For our initialize function, we use some 'NIL' value.
// In our case, we initailize all of the values in our table to 0.
void initialize(){
    int i;
    // Initialize our values to some negative
    // number to indicate they have not
    // previously been computed.
    for(i = 0; i < LARGEST_FIB_NUMBER; i++){
        memo[i] = -1;
    }
}


long dyn_fibonacci(int n){
   // TODO:
   return 0;
}


int main(){
 
  // The 'n'th fibonacci number that we want to compute
  const int fibNumber = 45;

  // ===========================================
  // ===== Experiment 1 - fibonacci ====
  // Create a clock to measure the elapsed time
  clock_t start1,end1;
  start1 = clock();
  // perform fibonacci after starting clock
  long fib1 = fibonacci(fibNumber);
  end1 = clock(); 
  double experiment1 = ((double)(end1-start1)/CLOCKS_PER_SEC);
   // ===========================================
   
  // ===========================================
  // ===== Experiment 2 - dyn_fibonacci ====
  // Create a clock to measure the elapsed time
  clock_t start2,end2;
  start2 = clock();
  // Call our initialization function
  // This function is part of the cost of 
  // dynamic programming so it should be included in our
  // experiment.
  initialize();  
  // perform fibonacci after starting clock
  long fib2 = dyn_fibonacci(fibNumber);
  end2 = clock();
  double experiment2 = ((double)(end2-start2)/CLOCKS_PER_SEC);
  // ===========================================
 
  // check correctness
  if(fib1 != fib2){
  	printf("Hmm, one implementation may be wrong\n");
    printf("\tfib1 = %lu \n\tfib2 = %lu \n",fib1,fib2); 
  }else{
    printf("\tfib1 = %lu \n\tfib2 = %lu \n",fib1,fib2); 
  }
  // ============ Results ============== 
  printf("\nAnalysis of Time:\n");
  printf("%f Non-Dynamic Programming Fibonacci\n", experiment1);
  printf("%f Dynamic Programming Fibonacci\n", experiment2);
  
  return 0;
}
