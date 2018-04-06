#include<stdio.h>
#include<pthread.h>
void *tf(void * args)
{
int i=0;
while(i<2)
{
printf("Inside thread");
}
}
int main()
{
pthread_t id;
int ret;
int k=0;
ret=pthread_create(&id,NULL,&tf,NULL);
if(ret==0)
printf("thread create successfully");
else
{
printf("thread not created");
return 0;
}
while(k<4)
{
printf("in main");
k++;
}
return 0;
}
