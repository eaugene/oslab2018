#define _POSIX_SOURCE
#include <fcntl.h>
#include<stdio.h>
#include <sys/stat.h>
int main()
{
int f=open("abzz.txt", O_CREAT|O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
int fe=open("absz.txt", O_CREAT|O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
printf("%d - %d\n",f,fe);
//printf("%d",chmod("abcz.txt", O_RDWR));
return 0;
}
