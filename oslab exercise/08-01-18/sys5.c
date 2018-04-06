#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
char eapr[5];
int ep=open("abc2.txt",O_RDWR);
if(ep>0)
{
if(read(ep,eapr,5)>0)
{
printf("\n%s",eapr);
if(close(ep)==0)
{
printf("\nFile successfully closed\n");
}
else
{
printf("\nError in closeing the file\n");
}
}
}
else
{
printf("\nerror in opeing the file\n");
}
return 0;
}
