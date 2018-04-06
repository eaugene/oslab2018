#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char **argv)
{
int i=fork();
if(i==0)
{
printf("child=%d,parent=%d",(int)getpid(),(int)getppid());
execv(argv[1],argv+1);
}
else
{
wait(NULL);
exit(1);
}
return 0;
}
