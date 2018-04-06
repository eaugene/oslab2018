#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int p[2];
	char s[100];
	cin>>s;
	char b[100];
	if(pipe(p)<0)
	{
		cout<<"unable to pipe";
		exit(1);
	}
	else
	{
		int f=fork();
		if(f<0)exit(1);
		if(f)
		{
			close(p[0]);
			int w=write(p[1],s,strlen(s));
			cout<<"\nIn parent, data written";
		}
		else
		{
			close(p[1]);
			int r=read(p[0],b,strlen(s));
			cout<<"in child"<<b;
		}
	}

	return 0;
}
