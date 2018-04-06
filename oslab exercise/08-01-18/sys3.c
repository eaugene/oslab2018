#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
char ep[128];
int eapr=open("abc2.txt",O_RDWR);
if(eapr>0)
{
int r=read(eapr,ep,128);
printf("\n%d - %s \n",r,ep);
}
else
printf("\nerror in opeing file");
return 0;
}
