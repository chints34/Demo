/****division of integr****/
#include<stdio.h>
#include<string.h>
main(int argc,char **p)
{
      int a,i,div;
for(i=1;i<argc;i++)
{
a=atoi(p[i]);
div=a/(a+i);
}
printf("division:%d\n",div);
}
