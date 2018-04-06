#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<string.h>
int main()
{int r;
	char a[10],b[10];
	char *c="/tmp/fifo1";
	mkfifo(c,0666);
	while(1)
	{
		gets(a);
		r=open(c,O_WRONLY);
		write(r,a,strlen(a));
		close(r);
		printf("\nWriiten ");
                r=open(c,O_RDONLY);
		read(r,b,10);
		close(r);
		printf("%s is read from usr1",b);

	}
	return 0;
}
