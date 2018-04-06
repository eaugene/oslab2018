#include<stdio.h>
#include<unistd.h>
int main()
{
	char *a[]={"ls","-l",NULL};
	execvp(a[0],a);
	return 0;
}
