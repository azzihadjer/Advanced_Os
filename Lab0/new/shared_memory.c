#include "shared_memory.h"


void create_producer_threads(pthread_t *prod_threads, struct shared_memory *shm, int *producer_ids) {
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&prod_threads[i], NULL, producer, (void *)&producer_ids[i]);
    }
}


void create_consumer_threads(pthread_t *cons_threads, struct shared_memory *shm, int *consumer_ids) {
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&cons_threads[i], NULL, consumer, (void *)&consumer_ids[i]);
    }
}


void join_producer_threads(pthread_t *prod_threads) {
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(prod_threads[i], NULL);
    }
}


void join_consumer_threads(pthread_t *cons_threads) {
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(cons_threads[i], NULL);
    }
}
