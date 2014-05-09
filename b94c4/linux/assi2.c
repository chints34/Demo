#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main(int argc,char **p)
{
int i;
char str[100];
for(i=1;i<argc;i++)
{
system(p[i]);
}
}

