#include<iostream>
#include<unistd.h>
int main()
{
char data[20];
int p[2];
std::cin>>data;
pipe(p);
int k=fork();
if(k>0)
{
read(p[0],data,20);
std::cout<<data<<std::endl;
}
else
write(p[1],data,20);
return 0;
}
