/* Peter Murphy
 * CS 5008
 * Assignment 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printResults(int gameNum, int guesses){
	if(guesses == 1){
        	printf("Game %d took you %d guess\n", gameNum, guesses);
     	} else {
                printf("Game %d took you %d guesses\n", gameNum, guesses);
        }
}

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
		
		while(keepGuessing == 1){
			i++;
			printf("Guess #%d: ", i);
			scanf("%d", &guess);
			if(guess == answer){
				printf("You got it!!\n");
				guesses[numGames] = i;
				i = 0;
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

	printf("================================\n");
        printf("Game Over! Here are the results:\n");
        printf("================================\n");

	for(int j = 0; j < 5; j++){
		printResults(j, guesses[j]);
	}	
	return 0;
}

