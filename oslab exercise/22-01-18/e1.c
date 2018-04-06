#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
char *args[]={"./e11",NULL};
execvp(args[0],args);
printf("end");
return 0;
}
