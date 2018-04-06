#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *tst2(int *er)
{
printf("sum=%d",er[0]+er[1]);
}
int main()
{
pthread_t t;
int er[2];
scanf("%d%d",&er[0],&er[1]);
pthread_create(&t,NULL,tst2,er);
pthread_join(t,NULL);
return 0;
}
