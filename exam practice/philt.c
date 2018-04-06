#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdio.h>

#define N 5
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N


int THINKING=2;
int HUNGRY=1;
int EATING=0;
int phil[N]={0,1,2,3,4};
int state[N];
sem_t mutex;
sem_t s[N];

void test(int phnum)
{
	if(state[phnum]==HUNGRY && state[ LEFT ]!=EATING && state[ RIGHT ]!=EATING)
	{
		state[phnum]=EATING;
		printf("philosopher %d is taking fork %d , %d\n",phnum+1,LEFT+1,phnum+1);
		printf("philosopher %d is eating\n",phnum+1);
	//	sleep(2);
		sem_post(&s[phnum]);
	}
}
void takefork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("philosopher %d is hungry\n",phnum+1);
	test(phnum);
	sem_post(&mutex);
	//sem_post(&s[phnum]);
	sem_wait(&s[phnum]);
	sleep(1);
}
void putfork(int phnum)
{       
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("philosopher %d is putting fork %d , %d down",phnum+1, LEFT +1,phnum+1);
	printf("philosopher %d is thinking\n",phnum+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *philosopher(void *n)
{
	while(1)
	{
		int *i=n;
		//takefork(*i);
		sleep(1);
		takefork(*i);
		sleep(0);
		putfork(*i);
	}
}
int main()
{
	pthread_t th[N];
	int i;
	sem_init(&mutex,0,1);
	for(i=0;i<N;i++)
		sem_init(&s[i],0,0);
	for(i=0;i<N;i++)
	{
		pthread_create(&th[i],NULL,philosopher,&phil[i]);
		printf("philosopher %d id thinking\n",i+1);
	}
	for(i=0;i<N;i++)
		pthread_join(th[i],NULL);
	return 0;
}
