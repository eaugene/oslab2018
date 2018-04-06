#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
struct messagea{long type;char ar[100];}message;
int main(){
	key_t key;int msgid;
	key=ftok("progfile",65);
	msgid=msgget(key,0666|IPC_CREAT);
	message.type=1;
	//scanf("%s[^\n]",message.ar);
	gets(message.ar);
	msgsnd(msgid,&message,sizeof(message),0);

return 0;
}
