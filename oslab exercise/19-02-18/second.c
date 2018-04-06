#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t semP, semC;
int count = 0;
int max=5;
void *producer(void *arg) {
	int i, sum=0;
	for (i = 0; i < 10; i++) {

		while(max == count){
			printf("stock overflow &  production waits..\n");
			sem_wait(&semC);
			printf("production operation continues..\n");
		}
		sleep(1);
		count++;
		printf("Producer : stock-count : %d\n",count);
		sem_post(&semP);
		printf("Producer : after production\n");
	}
}
void *consumer(void *arg) {
	int i, sum=0;
	for (i = 0; i < 10; i++) {
		while(0 ==count){
			printf("stock empty, consumer waits\n");
			sem_wait(&semP);
			printf("consumer operation continues\n");
		}
		sleep(2);
		count--;
		printf("Consumer : stock-count : %d\n", count);
		sem_post(&semC);
		printf("Consumer : after consumption\n");
	}
}
int main(void) {
	pthread_t tid0,tid1;
	sem_init(&semP, 0, 0);
	sem_init(&semC, 0, 0);
	pthread_create(&tid0, NULL, consumer, NULL);
	pthread_create(&tid1, NULL, producer, NULL);
	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);
	sem_destroy(&semC);
	sem_destroy(&semP);
	return 0;
}


