#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
int fd=0;
char *myfifo="/tmp/i3";
mkfifo(myfifo,0666);
char a1[80],a2[80]="hi";
int i=0;
printf("%d",(int)strlen(a2));
while(i<1)
{
fd=open(myfifo,O_WRONLY);
//scanf("%s",a2);
printf("%s",a2);
write(fd,a2,(int)(strlen(a2)));
printf("1");
close(fd);
fd=open(myfifo,O_RDONLY);
read(fd,a1,sizeof(a1));
printf("%s",a1);
close(fd);
i++;
}
return 0;
}
