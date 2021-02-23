// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char* argv1[16]; // Store up to 16 arguments
    char* argv2[16];
    char* argv3[16];

    argv1[0] = "/bin/ls"; // First argument
    argv1[1] = NULL;

    argv2[0] = "/bin/echo"; // Second argument (pt 1)
    argv2[1] = "'testing'"; // Second argument (pt 2)
    argv2[2] = NULL;

    argv3[0] = "/bin/nl"; // Third argument (pt 1)
    argv3[1] = "example1.c"; // Third argument (pt 2)
    argv3[2] = NULL; // Terminate args
    
    char** commands[] = {argv1, argv2, argv3};

    for (int i=0; i<3; i++){
        if (fork()==0){
            printf("Running Command # %d\n", i);
            execve(commands[i][0], commands[i], NULL);
            exit(1);
        } else {
        wait(NULL); // Wait for the child process to finish before exiting parent
        }
    }
    printf("Program Finished\n");

    return 0;

}
