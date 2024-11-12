#include "shared_memory.h"
#include <pthread.h>

void *consumer(void *arg) {
    struct shared_memory *shm = (struct shared_memory *)arg;
    int item;
    int consumer_id = *((int *)arg);  

    while (1) {
        sem_wait(&shm->full);  
        pthread_mutex_lock(&shm->mutex);  

        
        item = shm->buffer[shm->out];
        printf("[ Consumer %d ]: consumed item %d from index %d\n", consumer_id, item, shm->out);
        shm->out = (shm->out + 1) % BUFFER_SIZE; 

        pthread_mutex_unlock(&shm->mutex);  
        sem_post(&shm->empty);  Signal that the buffer has space

        sleep(rand() % 3);  
    }

    return NULL;
}

int main() {
    pthread_t cons_threads[NUM_CONSUMERS];
    struct shared_memory shm;
    shm.in = 0;
    shm.out = 0;

    
    sem_init(&shm.empty, 0, BUFFER_SIZE);
    sem_init(&shm.full, 0, 0);
    pthread_mutex_init(&shm.mutex, NULL);

    
    int consumer_ids[NUM_CONSUMERS] = {1, 2,3};

   
    create_consumer_threads(cons_threads, &shm, consumer_ids);

    join_consumer_threads(cons_threads);

  
    sem_destroy(&shm.empty);
    sem_destroy(&shm.full);
    pthread_mutex_destroy(&shm.mutex);

    return 0;
}
