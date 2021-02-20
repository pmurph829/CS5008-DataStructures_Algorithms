// Type in and try example2.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int x = 1;

    pid = fork();

    if (pid==0){
        printf("Terminating Child. PID= x%d\n", getpid());
        exit(0);
    } else {
        printf("Run the server forever (like a server): PID= %d\n", getpid());
        while(1){
        }
    }
    return 0;
}
