#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
char ep[128];
scanf("%[^\n]s",ep);
//printf("%d",(int)strlen(ep));
int f1=open("abc2.txt",O_RDWR|O_APPEND);
if(f1>0)
{
int r=write(f1,ep,(int)strlen(ep));
if(r>0)
printf("\nwrite successful");
else
printf("\nwrite failed");
}
else
{
printf("\nerror in opening file");
}
return 0;
}
