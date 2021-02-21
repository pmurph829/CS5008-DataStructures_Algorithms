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

    argv3[3] = "/bin/nl"; // Third argument (pt 1)
    argv3[4] = "example1.c"; // Third argument (pt 2)
    argv3[5] = NULL; // Terminate args

    if (fork()==0){
        execve(argv1[0], argv1, NULL); // Execute first arg
        execve(argv2[0], argv2, NULL); // Execute second arg
        execve(argv3[0], argv3, NULL); // Execute third arg

        exit(1);
    } else {
       wait(NULL); // Wait for the child process to finish before exiting parent
       printf("Program finished\n");
    }

    return 0;

}
