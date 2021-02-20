// Type in and try example3.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int x = 1;
    
    pid = fork();

    if (pid==0){
        printf("Running child process forever. PID= %d\n",getpid());
        while(1){
        }
    } else {
        printf("Terminating parent process. PID= %d\n",getpid());
        exit(0);
    }
    return 0;

}
