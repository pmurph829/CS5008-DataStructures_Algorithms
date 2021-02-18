// gcc readline.c -o readline
// 
// This example program demonstrates
// how to read a line in C and
// use the string compare function.
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 80

int main(){
    // A buffer to hold 80 characters at most
    char line[MAX_BUFFER_SIZE];

    // A loop that runs forever.
    while(1){
        // Read in 1 line of text
        // The line is coming from 'stdin' standard input
        fgets(line,MAX_BUFFER_SIZE,stdin);
        // We write out to standard output
        printf("Here is what you typed: %s\n",line);

        // Let's see what happens when comparing a string.
        // Think about this behavior.
        if(strcmp(line,"help")==0){
            printf("You typed in help\n");
        }
        if(strcmp(line,"help\n")==0){
            printf("You typed in help with an endline\n");
        }
    }

    return 0;
}
