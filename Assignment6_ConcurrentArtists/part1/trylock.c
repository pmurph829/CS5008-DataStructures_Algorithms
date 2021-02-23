// compile with: gcc -o trylock trylock.c -lpthread
//
// In this example I launch 2 threads.
// One thread will hold the lock forever,
// and the other thread will give up and make
// progress elsewhere.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define NTHREADS 2

pthread_mutex_t mutex;

void* thread(void* args){

    if(pthread_mutex_trylock(&mutex)==0){
        printf("Aha, thread %u got the lock!\n", pthread_self());
        sleep(5);
        pthread_mutex_unlock(&mutex);
    }else{
        printf("thread %u did not get the lock, continuing elsewhere\n", pthread_self());
    }
}


int main(){
    // Initialize our mutex
    pthread_mutex_init(&mutex,NULL);

    // Store two thread ids
    pthread_t tids[NTHREADS];

    for(int steps =0; steps < 10; ++steps){
        for(int i = 0; i < NTHREADS; ++i){
            pthread_create(&tids[i],NULL,(void*)thread,NULL);
        }

        for(int i = 0; i < NTHREADS; ++i){
            pthread_join(tids[i],NULL);
        }
    }
    


    return 0;
}
