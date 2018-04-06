#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
int main()
{
	key_t key=ftok("sharea",65);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *s=(char *)shmat(shmid,(void *)0,0);
	gets(s);
	shmdt(s);
	return 0;
}
