#include<fcntl.h>
#include<stdio.h>
int main()
{
int f1=open("abc4.txt",O_CREAT|O_RDONLY|O_WRONLY,0777);
int f2=open("abc5.txt",O_CREAT|O_RDONLY|O_WRONLY,0777);
printf("The file descriptors are %d & %d \n",f1,f2);
return 0;
}
