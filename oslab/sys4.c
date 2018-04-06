#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
	char eapr[10];
	int f1=open("abc2.txt",O_RDWR);
	if(f1>0)
	{
		if(read(f1,eapr,10)>0)
		{
			printf("\n%s",eapr);

			if(lseek(f1,10,SEEK_CUR)>0)
			{
				read(f1,eapr,10);
				printf("\n%s",eapr);
			}
			else
			{
				printf("\nerror in seek");
			}
		}
		else
		{
			printf("\nError in reading file");
		}
	}
	else
	{
		printf("\nError in opening file");
	}

	return 0;
}
