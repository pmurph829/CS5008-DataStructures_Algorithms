/* Peter Murphy
 * CS 5008
 * Assignment 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int guess;
	int numGames;
	int guesses[5];
	int keepGuessing = 1;
	int i = 0;

	// Generate a random number n with: 1<=n<= 10
	srand(time(NULL));	

	for(numGames = 0; numGames < 5; numGames++){
		printf("================================\n");
		printf("New Game! Pick a number (1 - 10)\n");
		printf("================================\n");
		int answer = 1 + rand() % 10;
		// REMOVE THIS!!!!!!!!!!!!!
		printf("Answer: %d\n", answer);
		
		while(keepGuessing == 1){
			i++;
			printf("Guess #%d: ", i);
			scanf("%d", &guess);
			if(guess == answer){
				printf("You got it!!\n");
				guesses[numGames] = i;
				keepGuessing = 0;
			} else if(guess < answer){
				printf("Nope, too low!\n");
			}
			else {
				printf("Nope, too high!\n");
			}

		}
		keepGuessing = 1;
			
	}
		
	return 0;
}

