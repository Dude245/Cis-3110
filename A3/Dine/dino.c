void* philoDiner(void *arg);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t chops [1000];
int phioFed = 0;
int numPhilo = 0;
int numNom = 0;

int main(int argc, char *argv[]) {
    pthread_t thread[1000];

    int thread_id[1000];
    int id = 0;
    int result;
    int isLocked = 0;

    //Get number of philo and number of times to eat
    numPhilo = atoi(argv[1]);
    numNom = atoi(argv[2]);

    //Create mutex/execute function
    for (int i = 0; i < numPhilo; i++) {
        thread_id[i] = i;
        result = pthread_create(&(thread[i]), NULL, &philoDiner, &(thread_id[i]));
        pthread_mutex_init(&chops[i], NULL);
    }


    //Join the threads
    for (int c = 0; c < numPhilo; c++) {
        result = pthread_join(thread[c], NULL);
    }
    //Kill the threads
    for (int c = 0; c < numPhilo; c++) {
        result = pthread_mutex_destroy(&chops[c]);
    }


    return 0;
}

void* philoDiner(void *arg) {
    int minId = 0;
    int fatty = 0;
    int id = *((int*) arg);
    minId = id - 1;
    //Wrap around for begining and end
    if (minId == -1)
        minId = numPhilo - 1;

    //For as many times as they have to eat
    while (fatty < numNom) {
        //Lock 1 and 2
        printf("Philosopher %d Waiting...\n", id + 1);
        pthread_mutex_lock(&chops[id]);
        pthread_mutex_lock(&chops[minId]);
        fatty++;
        sleep(1);
        //Unlock 1 and 2
        printf("Philosopher %d Eating....\n", id + 1);
        pthread_mutex_unlock(&chops[id]);
        pthread_mutex_unlock(&chops[minId]);
        printf("Philosopher %d has eaten!\n", id + 1);

    }
    phioFed++;
}