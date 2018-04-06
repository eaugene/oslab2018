#include<stdio.h>
#include<sys/types.h>
void main()
{
fork();
printf("\nabc\n");
fork();
printf("\nxyz\n");
fork();
printf("\nhi\n");
}
