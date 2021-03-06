
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 80

// Built in command names
char* builtInCmds[] = {"cd", "help", "exit", "game"};

// Code for a guessing game - custom command. Note, this is from A1.
int mini_guess(char** args){
    int guess;
    int numGames=0;
    int guesses[5];
    int keepGuessing=1;
    int answer;
    int i = 0;
    int j = 0;
    srand(time(NULL));
    printf("==========================\n");
    printf("    MINI GUESSING GAME    \n");
    printf("==========================\n");
    for (numGames; numGames<5; numGames++){
        printf("==========================\n");
        printf("         ROUND %d\n", numGames);
        printf("==========================\n");
        // Determine the range for the number depending on user input.
        if (args[1] == NULL || strcmp(args[1],"medium")==0){
            printf("Medium difficulty: Guess between 1 and 10!\n");
            answer = 1 + rand() % 10;
        } else if (strcmp(args[1],"easy")==0){
            printf("Easy difficulty: Guess between 1 and 5!\n");
            answer = 1 + rand() % 5;
        } else if (strcmp(args[1], "hard")==0){
            printf("Hard difficulty: Guess between 1 and 20!\n");
            answer = 1 + rand() % 20;
        }
        while(keepGuessing){
            i++;
            printf("Guess #%d: ", i);
            scanf("%d", &guess);
            if (guess == answer) {
                printf("You mini-guessed it!\n");
                guesses[numGames] = i;
                i = 0;
                keepGuessing = 0;
            } else if (guess < answer) {
                printf("Too mini! (guess higher)\n");
            } else {
                printf("Not mini enough! (guess lower)\n");
            }
        }
        keepGuessing = 1;
    }
    printf("==========================\n");
    printf("        GAME  OVER        \n");
    printf("==========================\n");
    for (; j<5; j++){
        if (guesses[j] == 1){
            printf("Round %d took %d guess\n", j, guesses[j]);
        } else {
            printf("Round %d took %d gueses\n", j, guesses[j]);
        }
    }
    return 1;
}

// Code for the cd command
int mini_cd(char** args){
    if (args[1] == NULL){
        printf("No argument passed to cd.\n");
    // Use chdir to change directory to the specified location
    // If this fails, print an error message.
    } else if (chdir(args[1]) != 0){
        printf("error with cd\n");
    }
    return 1;
}

// Code for the help command
int mini_help(char** args){
    printf("\n-- help for mini-shell --\n\n");
    
    if (args[1] == NULL || strcmp(args[1],"help")==0){
        printf("For help with a specific command use: help [CMD]\n");
        printf("(replace [CMD] with the desired command name)\n");
        printf("Available commands:\n");
        int i = 0;
        for (; i<(sizeof(builtInCmds)/sizeof(char*)); i++){
            printf("\t%s\n", builtInCmds[i]);
        }
        printf("for help with other commands, use the man command\n");
    } else if (strcmp(args[1],"cd")==0){
        printf("Help for the cd commnad:\n");
        printf("\tcd stands for 'change directory'.\n");
        printf("\tto change the current directory, enter cd [path/to/dir]\n");
        printf("\tReplace [path/to/dir] with the desired directory.\n");
    } else if (strcmp(args[1],"exit")==0){
        printf("Help for the exit command:\n");
        printf("\tUse exit to terminate the shell.\n");
        printf("\tIf running a shell within a shell,\n");
        printf("\tthe exit command will terminate the most recent shell.\n");
    } else if (strcmp(args[1],"game")==0){
        printf("Help for the guessing game:\n");
        printf("\tPlays 5 rounds of a guessing game.\n");
        printf("\tEach round, a number is randomly generated.\n");
        printf("\t >> Easy difficulty range is 1 - 5\n");
        printf("\t >> Medium (default) difficulty range is 1 - 10\n");
        printf("\t >> Hard difficulty range is 1 - 20\n");
        printf("\tThe player will guess numbers until they get the correct answer.\n");
        printf("\tFeedback is given to guide the player to the correct answer.\n");
        printf("\tAfter 5 rounds, the number of guesses for each round is displayed.\n");
        printf("\tEnter 'easy', 'medium' or 'hard' after the game command\n");
        printf("\tto change the difficulty. Default is medium.\n");
    } else {
        printf("error: %s option not found for help command\n", args[1]);
    }
    printf("\n");
    return 1;
}

// Code for the exit command - returns zero to exit mainLoop() function
int mini_exit(char** args){
    return 0;
}

// Array of funciton pointers that contains all built-in commands
int (*builtInFunctions[]) (char**) = {
    &mini_cd,
    &mini_help,
    &mini_exit,
    &mini_guess
};

// Signal handler to print out message when Ctrl+C is pressed.
void sigintHandler(int sig){
    write(1, "\nmini-shell terminated!\n\n", 26);
    exit(0);
}

// This function scans for input to the mini-shell and returns
// The string that the user enters to be parsed into commands.
char* getInput(){
    char* line = malloc(BUFFER_SIZE * (sizeof(char)) +1 );
    
    fgets(line, BUFFER_SIZE, stdin);
    // Remove '\n' added to end of line to avoid issues with parsing
    char *newLine = strchr(line, '\n');
    if (newLine){
        *newLine = '\0';
    }
    return line;
}

// This function takes the input from the user and splits it into useable
// arguments.
char** parseInput(char* input){
    // allocate memory for the args array.
    // Use BUFFER_SIZE, since the number of args will never exceed this value.
    char** args = malloc(BUFFER_SIZE * sizeof(char*));
    
    // Tokenize the input. Uses tabs or spaces as delimiter.
    char* arg = strtok(input, " \t");

    // Get the rest of the args until strtok returns NULL
    int i =0;
    while(arg) {
        args[i] = arg;
        arg = strtok(NULL, " \t");
        i++;
    }
    // Terminate the list of args with NULL
    args[i] = NULL;
    return args;
}

// Function that is used to run external (not built-in) commands on mini-shell.
int runExternalCmd(char** args){
    int i = 0;
    char* a = args[i];

    pid_t pid = fork();
    if (pid==0){
        if (execvp(args[0], args)==-1){
            printf("Command not found!\n");
        }
        exit(1);
    } else {
        wait(NULL);
    }
    return 1;
}

// Function that handles executing the command that the user gave.
// First determines if the command is built in or not.
// If built in -> runs the built in function.
// runs the command externally otherwise.
int executeCommand(char** args){
    // Empty command entered- continue with mainLoop
    if (args[0] == NULL){
        return 1;
    }
    
    // Iterate over the list of built-in command names to check if the user entered one
    int i=0;
    for (; i< (sizeof(builtInCmds) / sizeof(char*)); i++){
        if (strcmp(args[0], builtInCmds[i])==0){
            return (builtInFunctions[i])(args);
        }
    }
    
    // If a built-in command was not entered, run the command externally.
    return runExternalCmd(args);
}

// Infinite loop that runs the mini-shell. The loop will run until executeCommand
// returns 0 (exit commmand entered).
void mainLoop(){
    char* input;
    char** args;
    int success= 1;
    
    while(success){
        printf("mini-shell> ");
        // Get input from the user
        input = getInput();
        // Parse the input into arguments
        args = parseInput(input);
        // Pass the arguments to the execute command function
        success = executeCommand(args);
        
        // Free allocated memory
        free(input);
        free(args);
    }
}

int main(){
    // Register the signal handler
    signal(SIGINT, sigintHandler);
    printf("\nActivating mini-shell (Terminate with Ctrl+C)\n");
    // Run mini-shell
    mainLoop();

    return 0;
}



