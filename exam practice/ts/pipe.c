#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
int fd[2];
void *first(void *n)
{
	//printf("fic");
	//char s[10];
	char *s=((char *)n);
	//while(1)
	//{
	printf("%s",s);
	close(fd[0]);
        //scanf("%s",s);
	write(fd[1],s,strlen(s));
	//sleep(2);
	//}
	//printf("fir");
//return NULL;

}
void *second()
{
	//printf("sec");
	char e[10];
	//while(1)
	//{
	close(fd[1]);
	read(fd[0],e,10);
	printf("%s\n",e);
	//printf("sec");
	//sleep(2);
	//}

}
int main()
{
	//int fd[2];
	char s[10];
	char e[10];
	char x[10];
	gets(x);
	int r=pipe(fd);
	pthread_t t,t2;
	pthread_create(&t,NULL,first,(void *)x);
	int k=pthread_create(&t2,NULL,second,NULL);
	//int r=pipe(fd);
	printf("%d",k);
	
	pthread_join(t,NULL);
	//read(fd[0],e,10);
	//printf("%s\n",e);

	pthread_join(t2,NULL);
	return 0;
}
