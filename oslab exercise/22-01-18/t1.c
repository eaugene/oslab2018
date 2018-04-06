#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *tst1()
{
printf("\nInside thread function");
return NULL;
}
int main()
{
pthread_t tid;
printf("before threading");
pthread_create(&tid,NULL,tst1,NULL);
pthread_join(tid,NULL);
printf("after threading");
return 0;
}
