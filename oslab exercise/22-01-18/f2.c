#include<stdio.h>
#include<sys/types.h>
void main()
{
int i,l;
scanf("%d%d",&i,&l);
if(fork()==0)
printf("\nadd=%d",i+l);
else
{
printf("\nsub=%d",i-l);
}
}
