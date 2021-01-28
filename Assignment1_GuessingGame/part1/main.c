/* Peter Murphy
 * CS 5008
 * Assignment 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int guess;
	// READ INSTRUCTIONS ON WHAT TO DO WITH THIS ARRAY.
	int guesses[5];

	// Generate a random number n with: 1<=n<= 10
	srand(time(NULL));
	int answer = 1 + rand() % 10;
	// REMOVE THIS PRINT IN FINAL	
	printf("Answer: %d\n", answer);
	
	for(int i = 0; i <= 5; i++){
		printf("Make guess (#%d): ", i);
		scanf("%d", &guess);
		guesses[i] = guess;
	}
	
	return 0;
}
