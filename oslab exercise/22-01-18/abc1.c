#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
	int fd;
	char* mkfifo1 = "/tmp/mkfifo1";
	mkfifo(mkfifo1,0666);
	char a[80], b[80];
	while(1){
		fd = open(mkfifo1,O_WRONLY);
		fgets(b,80,stdin);
		write(fd,b,strlen(b) + 1);
		close(fd);
		fd= open(mkfifo1,O_RDONLY);
		read(fd,a,sizeof(a));
		printf("User2:%s\n",a);
		close(fd);
	}
}
