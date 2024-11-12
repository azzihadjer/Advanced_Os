#ifndef SHARED_H
#define SHARED_H

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 3

struct shared_memory {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t empty;  
    sem_t full;  
    pthread_mutex_t mutex;  
};


struct producer_args {
    struct shared_memory *shm;
    int producer_id;
};

struct consumer_args {
    struct shared_memory *shm;
    int consumer_id;
};

void *producer(void *arg);
void *consumer(void *arg);
void create_producer_threads(pthread_t *prod_threads, struct shared_memory *shm, int *producer_ids);
void create_consumer_threads(pthread_t *cons_threads, struct shared_memory *shm, int *consumer_ids);
void join_producer_threads(pthread_t *prod_threads);
void join_consumer_threads(pthread_t *cons_threads);

#endif 
