#include<stdio.h>
#include<unistd.h>
int main()
{
	int i;
	i=fork();
	if(i==0)
	{	
		printf("\n");
		char *p[]={"./child.sh",NULL};
		execvp("./child.sh",p);
	}
	else
	{
		printf("\n");
		char *p[]={"./parent.sh",NULL};
		execvp("./parent.sh",p);
	}
	return 0;
}
