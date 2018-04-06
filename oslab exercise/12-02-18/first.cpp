#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main()
{
char data[20];
int q[2],p[2],pid;
pipe(p);
pipe(q);
if((pid=fork())>0)
{
write(p[1],"parent to child",20);
read(q[0],data,20);
cout<<data<<endl;
}
else
{
write(q[1],"child to parent",20);
read(p[0],data,20);
cout<<data<<endl;
}
return 0;
}
