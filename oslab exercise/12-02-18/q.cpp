#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
	int pid,p[2];
	pipe(p);
	char *a[] = { "/bin/ls",NULL};
	char inbuf[100];
	pid = fork();
	if(pid==0)
	{
		printf("in child\n");
		write(p[1],"pipe1.cpp",9);
	}
	else if(pid>0)
	{
		read(p[0],inbuf,9);
		inbuf[9] = '\0';
		printf("in parent\n");
		printf("message:\n %s",inbuf);
		int i = execlp("/bin/ls","/bin/ls",NULL);
	}

	return 0;
}
