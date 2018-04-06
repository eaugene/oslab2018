#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main()
{
int ret;
int fd[2];
char buff[100]="";
char s1[100]="";
cout<<"Enter the message";
cin>>s1;
ret=pipe(fd);
if(ret!=0)
{
cout<<"\nInvalid to create pipe";
exit(1);
}
if(fork()==0)
{
close(fd[0]);
ret=write(fd[1],s1,strlen(s1));
if(ret!=strlen(s1))
{
cout<<"write did not happen";
exit(2);
}
}
else
{
close(fd[1]);
ret=read(fd[0],buff,strlen(s1));
if(ret!=strlen(s1))
{
cout<<"read did not happen";
exit(3);
}
cout<<"\nparent read "<<buff<<" from child";
}
exit(0);
}
