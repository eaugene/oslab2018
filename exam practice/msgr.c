#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
struct dassas
{
	long i;
	char wr[200];
}message;
int main()
{
	key_t key=ftok("progfile",65);
	int msgid=msgget(key,0666 | IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("%s",message.wr);
        //gets(message.wr);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}


