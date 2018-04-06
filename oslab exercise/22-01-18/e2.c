#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char **argv[])
{
pid_t i=fork();
if(i==0)
{
execv("./f1",(char*[]){"./f1",argv[1],NULL});
exit(1);
}
else if(i>0)
{
execv("./f2",(char*[]){"./f2",argv[0],NULL});
exit(2);
}
else
{
perror("fork in exec failed");
exit(3);
}
return 0;
}
