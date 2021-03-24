// Compile with: clang radio.c -o radio
// Run with: ./radio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// @Name    loadMusicFile
// @Brief   Load the music database
//          'size' is the size of the database.
char** loadMusicFile(const char* fileName, int size){
  FILE *myFile = fopen(fileName,"r");
  
  // Allocate memory for each character-string pointer
  char** database = malloc(sizeof(char*)*size);
 
  unsigned int song=0;
  for(song =0; song < size; song++){
      // Allocate memory for each individual character string
      database[song] = malloc(sizeof(char)*80);
      // Copy over string
      database[song] = fgets(database[song],sizeof(char)*80,myFile);
  }
  
  // Import to always remember to close any file we open.
  fclose(myFile);
  // Return the pointer to our database
  return database;
}


// @Name    printArrayOfCharStrings
// @Brief   Prints an array of C-style strings
void printArrayOfCharStrings(char** array, unsigned int start, unsigned int end){
  int i;
  for(i = start; i < end; i++){
    printf("[%d] %s",i,array[i]);
  }
}

// @Name    swapStrings
// @Brief   Swaps two strings.
//          The lower string is put first
void swapStrings(char** s1, char** s2){
  if( strcmp(*s1,*s2)==0 ){
    // Strings are identical, do nothing
    return;
  }else if( strcmp(*s1,*s2) < 0 ){
    // Do nothing--we are already sorted
    return;
  }else{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
  }
}

// @Name    bruteForceSort
// @Brief   A simple O(N*N) sorting algorithm.
void bruteForceSort(char** array, unsigned int start, unsigned int end){
    int i,j;
    for(i =start; i < end-1; i++){
        for(j =start; j < end-1; j++){
            // Note the swap here.
            swapStrings(&array[j],&array[j+1]);
        }
    }

}

// @Name    partition
// @Brief   Helper funcion for quicksort
int partition(char** array, unsigned int low, unsigned int high){
    // TODO:
}

void quicksort(char** array, unsigned int low, unsigned int high){
    // TODO:
}


int main(){
  // Load our unsorted music file
  // We load two copies, as we will compare two sorting algorithms.
  char** musicDatabase1 = loadMusicFile("./musicdatabase.txt",13594);
  char** musicDatabase2 = loadMusicFile("./musicdatabase.txt",13594);
  // Print out a portion of the music database.
  printf("The first 10 entries of 13594 unsorted are...\n"); 
  printArrayOfCharStrings(musicDatabase1,0,10);
  printf("\n");
  
  // ===========================================
  // ===== Experiment 1 - Using Brute Force Sort ====
  // Create a clock to measure the elapsed time
  clock_t start1,end1;
  start1 = clock();
  // perform bruteForceSort after starting your timer
  bruteForceSort(musicDatabase1,0,13594);
  end1 = clock(); 
  double experiment1 = ((double)(end1-start1)/CLOCKS_PER_SEC);
   // ===========================================
   
  // ===========================================
  // ===== Experiment 2 - Using Quick Sort ====
  //printArrayOfCharStrings(musicDatabase2,0,994);
  // Create a clock to measure the elapsed time
  clock_t start2,end2;
  start2 = clock();
  // perform quicksort after starting your timer
  quicksort(musicDatabase2,0,13594);  
  end2 = clock();
  double experiment2 = ((double)(end2-start2)/CLOCKS_PER_SEC);
  // ===========================================
 
  // check correctness
  // by printing out the first few items
  const int items = 20; // change this to up to 13594
  printf("O(N*N) sort produces\n"); 
  printArrayOfCharStrings(musicDatabase1,0,items);
  printf("\n quick sort produces\n"); 
  printArrayOfCharStrings(musicDatabase2,0,items);  
  // ============ Results ============== 
  printf("\nResults of sorting:\n");
  printf("%f time taking for brute force\n", experiment1);
  printf("%f time taking for quick sort\n", experiment2);
  
  return 0;
}
