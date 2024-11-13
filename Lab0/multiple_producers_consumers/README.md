# Multiple Producers and Consumers Problem

This project is an implementation of the classic **Producer-Consumer** problem with multiple producers and multiple consumers using **C processes** and **shared memory**. It is designed for an **Advanced OS Architecture** course.

## Problem Statement

The system consists of multiple producers and multiple consumers that share a single, bounded buffer. The producers generate items and place them into the buffer, while the consumers take items from the buffer and consume them. The buffer has a fixed size, and access to it must be synchronized between the producers and consumers to avoid race conditions. The key challenge is to design and implement synchronization mechanisms to ensure thread-safe access to the shared buffer.

### Key Components:
1. **Shared Memory:** The buffer is implemented using shared memory so that it can be accessed by all producers and consumers.
2. **Producers and Consumers:** These are separate processes that interact with the shared memory.
3. **Synchronization:** To avoid race conditions, we use semaphores and mutexes to coordinate access to the shared buffer.

## Files in the Project

- **shared.h**: Header file defining the shared memory structure and function prototypes.
- **shared.c**: Source file that contains the implementation for managing the shared memory and synchronization mechanisms.
- **producers.c**: Source file implementing the producer process logic.
- **consumers.c**: Source file implementing the consumer process logic.

## How It Works

1. **Shared Memory Structure:**
   - A circular buffer is used to store items produced by the producers and consumed by the consumers.
   - A fixed buffer size is defined, and the shared memory structure contains buffer-related metadata like indices for tracking the front and rear of the buffer, as well as synchronization variables.

2. **Producers:**
   - Each producer generates an item and places it in the shared buffer.
   - Before adding an item, the producer checks if there is space available in the buffer (using semaphores and mutexes).
   - After adding an item, the producer signals that a new item is available.

3. **Consumers:**
   - Each consumer takes an item from the shared buffer.
   - Before consuming an item, the consumer checks if there is an item available in the buffer.
   - After consuming an item, the consumer signals that space is available in the buffer.

4. **Synchronization Mechanisms:**
   - **Semaphores** are used to control access to the buffer and to manage the count of available slots and items.
   - **Mutexes** ensure mutual exclusion when producers and consumers access the shared buffer concurrently.


## Build and Run Instructions

1. **Clone the Repository:**
   
   ```bash
   git clone https://github.com/azzihadjer/Advanced_Os.git
   cd Advanced_Os/Lab0/multiple_producers_consumers

2. **Compile the Project:**


     You can compile the project using `gcc`:
        
      ```bash
        gcc -o producers_consumers producers.c consumers.c shared.c -lpthread
    


3. **Run the Producers and Consumers:**
   
   In separate terminal windows, run the producer and consumer processes. For example:
   
     ```bash
          ./producers_consumers

4.**Termination:**

The program will continue running, with producers adding items to the buffer and consumers consuming them, until terminated manually.

## Example Output
   If you were running multiple producers and consumers, the output might look something like this:

 ---bash

               [ Producer 140444637327360]: produced item 5 to post: 3
               [ Producer 140444637420544]: produced item 7 to post: 4
               [ Consumer 140444638169856]: consumed item 5 from post: 3
               [ Consumer 140444638262144]: consumed item 7 from post: 4


## License
  This project is licensed under the MIT License. See the LICENSE file for details.
      
      
 ---bash
            
            This **README.md** provides a comprehensive overview of the project, detailing how to set up, compile, run, and the potential future improvements. It also includes a section for licensing information.







