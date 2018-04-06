#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
int main()
{
	char ea[128];
	//int f1=open("abc2.txt",O_RDWR);
	
	printf(" poda dei .. na than bestu ");

	 int r=read(2,ea,128);
         printf("\n%d - %s\n",r,ea);
	return 0;

}
