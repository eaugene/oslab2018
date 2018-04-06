#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{

int f1=open("abc5.txt",O_RDWR);
printf("\n%d",f1);
int f2=chmod("abc5.txt",0777);
printf("\n%d",f2);
return 0;
}
