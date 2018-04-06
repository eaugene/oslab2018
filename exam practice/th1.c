#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int lo=1;
int sum=500;
void *abc()
{
	int i=0;
	while(1)
	{
		if(lo==0)
			continue;
		lo=0;
		sum=sum+50;
		printf("*****%d********",sum);
		i=i+1;
		printf("\n%d",i);
		lo=1;
		sleep(2);
	}
}
void *ab(void *n)
{
	int temp = *((int *)n);
	int t3= *((int *)n+1);
	while(1)
	{
		if(lo==0)
			continue;
		lo=0;
		sum=sum-30;
		printf("******%d*******",sum);
		printf("\n##%d",temp+t3);
		lo=1;
		sleep(1);
	}
}
int main()
{
	pthread_t t,t2;
	int *y=malloc(2*sizeof(int));
	scanf("%d%d",y,y+1);
//	printf("%d%d",*(y),*(y+1));
	pthread_create(&t,NULL,abc,NULL);
	pthread_create(&t2,NULL,ab,(void *)y);
	while(1)
	{
		printf("\nx");
		sleep(3);
	}
	pthread_join(t,NULL);
	pthread_join(t2,NULL);
	return 0;
}
