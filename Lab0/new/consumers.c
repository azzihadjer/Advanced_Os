#include "shared.h"
#include <pthread.h>

void *consumer(void *arg) {
    struct consumer_args *args = (struct consumer_args *)arg;
    struct shared_memory *shm = args->shm;
    int consumer_id = args->consumer_id;
    free(args); 

    int item;

    while (1) {
        sem_wait(&shm->full);  
        pthread_mutex_lock(&shm->mutex);  

        item = shm->buffer[shm->out];
        printf("[ Consumer %d ]: consumed item %d from index %d\n", consumer_id, item, shm->out);
        shm->out = (shm->out + 1) % BUFFER_SIZE; 

        pthread_mutex_unlock(&shm->mutex);  
        sem_post(&shm->empty);  

        sleep(rand() % 3);  
    }

    return NULL;
}
