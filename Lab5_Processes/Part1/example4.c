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

        if (WEXITSTATUS(child_status)>=0){
            printf("Child exited with the following child_status: %d\n",WEXITSTATUS(child_status));
        }
        printf("Child is always terminated by this point -- parent resuming\n");
    }
    printf("This always prints last\n");
    return 0;
}
