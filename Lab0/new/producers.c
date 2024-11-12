#include "shared_memory.h"
#include <pthread.h>

void *producer(void *arg) {
    struct shared_memory *shm = (struct shared_memory *)arg;
    int item;
    int producer_id = *((int *)arg); 

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

int main() {
    pthread_t prod_threads[NUM_PRODUCERS];
    struct shared_memory shm;
    shm.in = 0;
    shm.out = 0;

   
    sem_init(&shm.empty, 0, BUFFER_SIZE);
    sem_init(&shm.full, 0, 0);
    pthread_mutex_init(&shm.mutex, NULL);

   
    int producer_ids[NUM_PRODUCERS] = {1, 2,3};

    create_producer_threads(prod_threads, &shm, producer_ids);

    join_producer_threads(prod_threads);

   
    sem_destroy(&shm.empty);
    sem_destroy(&shm.full);
    pthread_mutex_destroy(&shm.mutex);

    return 0;
}
