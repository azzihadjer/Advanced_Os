Multiple Producers and Consumers
This project is an implementation of the Multiple Producers and Consumers Problem using shared memory and synchronization mechanisms. The goal is to design a system where multiple producer and consumer processes communicate via a shared buffer in a thread-safe manner.

Table of Contents
Problem Description
Files Overview
Shared Memory Design
Implementation
Synchronization Mechanisms
How to Compile and Run
Requirements
Problem Description
The Multiple Producers and Consumers Problem involves two types of processes: producers, which create data, and consumers, which retrieve data. Both processes share a common buffer, and we need to ensure that producers don't overwrite data before consumers can process it, and consumers don't read data that hasn't yet been produced.

The key challenges are:

Thread-safe access: Both producers and consumers must safely access the shared buffer to avoid race conditions.
Synchronization: The processes must be coordinated to avoid deadlocks and ensure that buffer operations are handled correctly.
Files Overview
shared.h
This file contains the declarations of shared memory structures and function prototypes for handling shared resources.

shared.c
This file defines the shared memory structure and implements functions for setting up and accessing shared resources, such as initializing semaphores and mutexes.

producers.c
This file implements the producer processes. Each producer generates data and places it into the shared buffer, ensuring thread-safe access using synchronization mechanisms.

consumers.c
This file implements the consumer processes. Each consumer retrieves data from the shared buffer, ensuring that data is consumed in the correct order and that buffer access is thread-safe.

Shared Memory Design
The shared memory structure is used to facilitate communication between the producers and consumers. It includes:

A buffer that holds the produced items.
Counters to track the number of items in the buffer, the positions of producers and consumers in the buffer.
Semaphores and mutexes to handle synchronization and ensure mutually exclusive access to the buffer.
Key Components:
Buffer: A fixed-size array that stores items produced by producers and consumed by consumers.
Count Variables:
in: Tracks the position where the next produced item will be inserted.
out: Tracks the position where the next consumed item will be retrieved.
count: Tracks the current number of items in the buffer.
Mutex: Used to ensure that only one process (producer or consumer) accesses the buffer at a time.
Semaphores:
empty: Tracks the number of empty slots in the buffer.
full: Tracks the number of filled slots in the buffer.
Implementation
Producers
Each producer follows these steps:

Wait for an empty slot in the buffer (sem_wait(empty)).
Lock the buffer using the mutex (pthread_mutex_lock(&mutex)).
Insert the produced item into the buffer.
Unlock the buffer (pthread_mutex_unlock(&mutex)).
Signal that the buffer has a new filled slot (sem_post(full)).
Consumers
Each consumer follows these steps:

Wait for a filled slot in the buffer (sem_wait(full)).
Lock the buffer using the mutex (pthread_mutex_lock(&mutex)).
Remove an item from the buffer.
Unlock the buffer (pthread_mutex_unlock(&mutex)).
Signal that the buffer has a new empty slot (sem_post(empty)).
Synchronization Mechanisms
This project employs the following synchronization mechanisms:

Semaphores: Used to track the availability of resources (empty and full buffer slots).
Mutex: Used to ensure mutually exclusive access to the critical section, i.e., the buffer.
The semaphores ensure that the producers wait when the buffer is full, and the consumers wait when the buffer is empty. The mutex ensures that no two processes (producers or consumers) can access the shared buffer at the same time, preventing race conditions.

How to Compile and Run
Compilation
To compile the project, use the following command in the terminal:

bash
Copy code
gcc -pthread -o producers producers.c shared.c -lrt
gcc -pthread -o consumers consumers.c shared.c -lrt
Running the Program
Start the consumers:

bash
Copy code
./consumers
Start the producers:

bash
Copy code
./producers
Requirements
GCC (or any other C compiler)
POSIX threads (pthread)
POSIX semaphores (<semaphore.h>)
Linux/Unix environment
License
This project is licensed under the MIT License - see the LICENSE file for details.
