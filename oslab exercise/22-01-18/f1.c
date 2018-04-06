#include<stdio.h>
#include<sys/types.h>
void main()
{
int i;
i=fork();
if(i==0)
{
printf("inside child process\n");
}
else  if(i<0)
printf("creatrion failed\n");
else
printf("inside parent process\n");
}
