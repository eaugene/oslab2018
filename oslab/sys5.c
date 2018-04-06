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
				printf("\nFile closed");
			}
			else
			{
			    printf("\nError in closing file");
			}
		}
	}
	else
	{
		printf("\nError in opening file");
	}
	return 0;
}
