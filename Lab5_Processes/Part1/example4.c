// Type in and try example4.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    
    int child_status;

    // Store the pid with fork
    if (fork()==0){
        printf("Child runs!\n");
        exit(0);
    } else {
        printf("Hello from parent\n");
        wait(&child_status);
    }
}
