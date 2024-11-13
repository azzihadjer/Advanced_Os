# Single Producer and Consumer Problem **(IPC)** through shared memory

This project implements the **Single Producer and Single Consumer** problem using **C** and **Inter-Process Communication (IPC)** through shared memory. The producer and consumer run in different terminals, synchronizing their access to a shared buffer to avoid race conditions. The buffer has a fixed size, and both processes must ensure thread-safe access using appropriate synchronization mechanisms.

## Problem Statement

- **Producer** generates items and places them in a bounded buffer.
- **Consumer** takes items from the buffer and consumes them.
- Both processes access the shared buffer, and synchronization is required to prevent race conditions.

## Tasks

1. **Design the Data Structures**:
   - Create the shared buffer structure, and include necessary metadata (e.g., buffer size, indices for tracking the head and tail of the buffer).
   
2. **Implement the Producer and Consumer Functions**:
   - Ensure thread-safe access to the buffer using synchronization mechanisms like semaphores or mutexes.
   
3. **Test the Implementation**:
   - Test with different buffer sizes and numbers of items produced/consumed to verify correct operation.

## Project Structure

- **share.h**: Header file containing definitions for the shared buffer and related metadata.
- **producer.c**: Source file implementing the producer logic, generating items and placing them in the buffer.
- **consumer.c**: Source file implementing the consumer logic, removing items from the buffer and consuming them.

### Files in the Project

1. **share.h**:
   - Defines the structure of the shared memory and buffer. It includes buffer size, indices to track positions, and other relevant fields needed for synchronization.
   
2. **producer.c**:
   - Implements the producer functionality. The producer continuously generates items and attempts to place them into the shared buffer. The process blocks if the buffer is full and waits until the consumer removes an item.
   
3. **consumer.c**:
   - Implements the consumer functionality. The consumer takes items from the shared buffer. The process blocks if the buffer is empty and waits until the producer generates a new item.

## How It Works

### 1. **Shared Memory and Synchronization**:
   - **Shared Memory (IPC)** is used to allow communication between the producer and consumer processes. Both processes access the same buffer structure in shared memory.
   - **Synchronization** is achieved using semaphores (or mutexes) to ensure that the producer and consumer do not access the buffer concurrently, preventing race conditions.

### 2. **Producer Logic**:
   - The producer generates an item and checks if there is space in the buffer. If the buffer is full, it waits until the consumer removes an item.
   - After producing an item, it increments the buffer's position and signals the consumer.

### 3. **Consumer Logic**:
   - The consumer checks if the buffer has an item available. If the buffer is empty, it waits until the producer generates an item.
   - After consuming an item, it decrements the buffer's position and signals the producer.

## Build and Run Instructions

1.**Compile the Producer and Consumer:**

  You can compile both the producer and consumer using gcc:
  
  
                  
                gcc -o producer producer.c -lpthread
                gcc -o consumer consumer.c -lpthread


2.**Run the Producer and Consumer:**

Open two separate terminal windows to run the producer and consumer:

  In the first terminal, run the producer:
            
              ./producer
  
   In the second terminal, run the consumer:
    
       
              ./consumer
    

  
  ## Example Output
The output will show the producer adding items to the buffer and the consumer removing and consuming them.

Producer Terminal Output:
  
    
            [Producer] Trying to produce item 1
            [Producer] Found empty slot for item 1
            [Producer] Writing item 1 to buffer position 0
            [Producer] Item 1 produced and mutex released
            [Producer] Signaled full slot for item 1
            [Producer] Trying to produce item 2
            [Producer] Found empty slot for item 2
            [Producer] Writing item 2 to buffer position 1
            [Producer] Item 2 produced and mutex released
            [Producer] Signaled full slot for item 2
            ...
            [Producer] Production complete
            


Consumer Terminal Output:

             [Consumer] Waiting for full slot
            [Consumer] Found full slot
            [Consumer] Consumed item 1 from position 0
            [Consumer] Signaled empty slot for item 1
            [Consumer] Waiting for full slot
            [Consumer] Found full slot
            [Consumer] Consumed item 2 from position 1
            [Consumer] Signaled empty slot for item 2
            ...
            [Consumer] Consumption complete
    


Termination
The program will continue running, with the producer generating items and the consumer consuming them, until terminated manually.

## Future Improvements
Add support for multiple producers and consumers.
Implement dynamic buffer resizing.
Introduce configurable buffer size and item count through command-line arguments.
## License
This project is licensed under the MIT License. See the LICENSE file for details.

    This `README.md` file provides an overview of the **Single Producer and Consumer

