#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 10

void *threadFunc(void *arg) {
	printf("\tHello from thread number %d\n", *(int *) arg);
	pthread_exit(0);
	return 0;
}

int main() {
	pthread_t threads[THREAD_COUNT];

	for (int i = 0; i < THREAD_COUNT; i++)  {
        int num = i + 1;
		printf("Thread %d create\n", num);
		pthread_create(&threads[i], NULL, threadFunc, &num);
		pthread_join(threads[i], NULL);
		printf("Thread %d finish\n\n", num);
	}

	return 0;
}
