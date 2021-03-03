// Implement your part 2 solution here
// gcc -pthread threads.c -o threads
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>

#define NTHREADS 64

char colors[64][64*3];

void save(){
    FILE* fp;
    fp = fopen("threads.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    int i = 0;
    for(; i<64; i++){
        int j = 0;
        for(; j<64*3; j++){
            fprintf(fp, "%d", colors[i][j]);
            fputs(" ", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);
    return;
}

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *argp){
    pthread_mutex_lock(&mutex1);
    counter = counter +1;
    int i =0;
    for (; i<64*3; i++){
        colors[counter][i] = counter;
    }
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main(){
    pthread_t tids[NTHREADS];
    printf("Counter starts at: %d\n", counter);

    int j = 0;
    for(; j<NTHREADS; j++){
        pthread_t newThread;
        tids[j] = newThread;
        pthread_create(&newThread, NULL, thread, NULL);
    }

    int i = 0;
    for(; i<NTHREADS; i++){
        pthread_join(tids[i], NULL);
    }
    printf("Final Counter value: %d\n", counter);
    save();
    return 0;
}
