/**** sum of integr****/
#include<stdio.h>
#include<string.h>
main(int argc,char **p)
{
      int a,i,sum=0;
for(i=0;i<argc;i++)
{
a=atoi(p[i]);
sum=sum+a;
}
printf("sum:%d\n",sum);
}
