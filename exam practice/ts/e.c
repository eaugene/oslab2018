#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int f1=open("abc.txt",O_RDWR|O_CREAT,0666);
	printf("%d",f1);
	char v[2];
	int w1=open("new.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	int f2=read(f1,v,1);
	while(f2>0)
	{
		printf("%c",v[0]);
		write(w1,v,1);
		f2=read(f1,v,1);
	}
	close(f1);
	f1=open("abc1.txt",O_RDWR|O_CREAT,0666);
	f2=read(f1,v,1);
	while(f2>0)
	{
		printf("%c",v[0]);
		write(w1,v,1);
		f2=read(f1,v,1);
	}
	close(f1);
	close(w1);
	return 0;
}
