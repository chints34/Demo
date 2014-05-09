#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main(int argc,char **p)
{
int i;
for(i=1;i<argc;i++)
{
system(p[i]);
}
}

