#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
	key_t key=ftok("sharea",65);
	int id=shmget(key,1024,0666|IPC_CREAT);
	char *s=(char *)shmat(id,(void *)0,0);
	
	puts(s);
	shmdt(s);
	shmctl(id,IPC_RMID,NULL);
	return 0;
}
