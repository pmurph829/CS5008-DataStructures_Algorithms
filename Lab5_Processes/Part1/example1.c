// Type in and try example1.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    
    // Variable to store process ID
    pid_t pid;

    // Variable x allocated on the stack
    int x = 1;

    // pid returns parent process ID:
    //  0 if the process is the child
    //  >0 is the process ID of the child (returned in parent)
    pid = fork();

    // Child process executing
    if (pid==0){
        printf("child: x = %d\n", ++x);
        return 0;
    }

    // Parent process executing
    printf("Parent: x = %d\n", ++x);
}
