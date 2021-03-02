// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

char colors[64][64*3];

void save(){
    FILE* fp;
    fp = fopen("vfork.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    int i = 0;
    for (; i<64; i++){
        int j = 0;
        for (; j<64*3; j++){
            fprintf(fp, "%d", colors[i][j]);
            fputs(" ", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);
    return;
}

void paint(int workID){
    printf("Artist %d is painting\n", workID);
    int i = 0;
    for (; i<64*3; i++){
        int colorInfo = rand() % 255;
        colors[workID][i] = colorInfo;
    }
    printf("\n");
}

int main(int argc, char** arcv){
    int numberOfArtists = 64;
    int* integers = malloc(sizeof(int)*8000);
    srand(time(NULL));
    pid_t pid;
    int i = 0;
    for (; i<numberOfArtists; i++){
        pid = vfork();
        if (pid == 0){
            paint(i);
            exit(0);
        } else {
            pid_t wpid;
            int status = 0;
            while((wpid = wait(&status)) > 0);
            //printf("Parent is exiting\n");
        }
    }
    save();
    free(integers);
    return 0;
}
