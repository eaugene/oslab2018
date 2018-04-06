#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	char ep[128];
	scanf("%[^\n]s",ep);
	printf("%d",sizeof(ep));

	int f1=open("abc1.txt",O_RDWR|O_APPEND);
	if(f1>0)
	{
		int r=write(f1,ep,128);
		if(r>0)
			printf("\ndata written succesfully");
		else
			printf("\ndata writting failed");
	}
	else
	{
		printf("\nError in opening file"); 
	}

	return 0;
}
