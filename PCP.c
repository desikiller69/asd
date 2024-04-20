#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void *producer(void *arg) {
    int item;
    int num_items = *((int *)arg);
    for (int i = 0; i < num_items; ++i) {
        item = rand() % 100; // produce random item

        sem_wait(&empty); // Wait if buffer is full
        sem_wait(&mutex); // Acquire mutual exclusion

        buffer[in] = item;
        printf("Produced %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex); // Release mutual exclusion
        sem_post(&full); // Signal that the buffer is no longer empty
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    int num_items = *((int *)arg);
    for (int i = 0; i < num_items; ++i) {
        sem_wait(&full); // Wait if buffer is empty
        sem_wait(&mutex); // Acquire mutual exclusion

        item = buffer[out];
        printf("Consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex); // Release mutual exclusion
        sem_post(&empty); // Signal that the buffer is no longer full
    }
    pthread_exit(NULL);
}

int main() {
    int num_producers, num_consumers, num_items_per_producer;
    printf("Enter number of producers: ");
    scanf("%d", &num_producers);
    printf("Enter number of consumers: ");
    scanf("%d", &num_consumers);
    printf("Enter number of items per producer: ");
    scanf("%d", &num_items_per_producer);

    pthread_t producer_threads[num_producers];
    pthread_t consumer_threads[num_consumers];

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    srand(time(NULL));

    for (int i = 0; i < num_producers; ++i) {
        pthread_create(&producer_threads[i], NULL, producer, &num_items_per_producer);
    }

    for (int i = 0; i < num_consumers; ++i) {
        pthread_create(&consumer_threads[i], NULL, consumer, &num_items_per_producer);
    }

    for (int i = 0; i < num_producers; ++i) {
        pthread_join(producer_threads[i], NULL);
    }

    for (int i = 0; i < num_consumers; ++i) {
        pthread_join(consumer_threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
