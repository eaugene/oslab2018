#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	int n,skip,count;
	char ea[128];
	int i;
	scanf("%d%d%d",&n,&skip,&count);
	int f1=open("testq.txt",O_RDWR);
	if(f1>0)
	{
		int f2=read(f1,ea,count);
		if(f2>0)
		{
			printf("\n****%s***\n",ea);
			for(i=1;i<n;i++)
			{
				int f4=lseek(f1,skip,SEEK_CUR);
				if(f4>0)
				{
					f2=read(f1,ea,count);
					if(f2>0)
					{
						printf("\n***%s***\n",ea);
					}
				}
				else
				{
					printf("\nEnd of file or can't lseek file");
				}
			}
		}
		else
		{
			printf("\nError in reading file");
		}
	}
	else
	{
		printf("\nError in opeing file");
	}
	return 0;
}
