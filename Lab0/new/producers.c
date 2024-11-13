#include "shared.h"
#include <pthread.h>

void *producer(void *arg) {
    struct producer_args *args = (struct producer_args *)arg;
    struct shared_memory *shm = args->shm;
    int producer_id = args->producer_id;
    free(args); 
    int item;

    while (1) {
        item = rand() % 100;  

        sem_wait(&shm->empty);  
        pthread_mutex_lock(&shm->mutex);  

        shm->buffer[shm->in] = item;
        printf("[ Producer %d ]: produced item %d at index %d\n", producer_id, item, shm->in);
        shm->in = (shm->in + 1) % BUFFER_SIZE;  

        pthread_mutex_unlock(&shm->mutex);  
        sem_post(&shm->full);  

        sleep(rand() % 3);
    }

    return NULL;
}
