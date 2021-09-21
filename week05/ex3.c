#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFERSIZE 5

int count = 0;

void* produce(void *arg) {
    while (1) {
        if (count >= BUFFERSIZE) {
            printf("producer sleep\n");
            sleep(1);
            continue;

        }
        count++;
        printf("produced %d\n", count);
    }

}

void* consume(void *arg){
    int item;
    while(1){
        if (count <= 0){
            printf("consumer sleep\n");
            sleep(1);
            continue;
        }
        count--;
        printf("consumed %d\n", count);
    }
}

int main(){
    pthread_t producer, consumer;

    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
}
