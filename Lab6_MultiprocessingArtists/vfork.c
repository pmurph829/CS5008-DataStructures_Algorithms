// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void paint(int pid){
    printf("Artist %d is painting!\n", pid);
}

int main(int argc, char** arcv){
    int numberOfArtists = 8;
    int* integers = malloc(sizeof(int)*8000);
    pid_t pid;
    int i = 0;
    for (; i<numberOfArtists; i++){
        pid = fork();
        if (pid == 0){
            paint(getpid());
            exit(0);
        } else {
            wait(NULL);
            printf("Parent is exiting\n");
        }
    }
    free(integers);
    return 0;
}
