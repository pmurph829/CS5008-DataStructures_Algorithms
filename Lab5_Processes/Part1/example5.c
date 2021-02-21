// Type in and try example5.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char* myargv[16];
    myargv[0] = "/bin/ls";
    myargv[1] = "-F";
    myargv[2] = NULL;

    if (fork()==0){
        execve(myargv[0], myargv, NULL);
        printf("Child: Should never get here\n");
    } else {
        wait(NULL);
        printf("This always prints last\n");
    }
    return 0;
}
