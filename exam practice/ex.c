#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	char *a[]={"./e1.sh","3","4",NULL};
	execvp(a[0],a);
	return 0;
}
