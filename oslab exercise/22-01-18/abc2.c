#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
	int fda;
	char *f = "/tmp/mkfifo1";
	mkfifo(f,0666);
	char a[80], b[80];
	while(1){
		fda = open(f,O_RDONLY);
		read(fda,a,80);
		printf("User 1:%s\n",a);
		close(fda);
		fda = open(f,O_WRONLY);
		fgets(b,80,stdin);
		write(fda, a, strlen(a) + 1);
		close(fda);
	}
}

