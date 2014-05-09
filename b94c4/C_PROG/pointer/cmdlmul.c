/**** multiplication of integr****/
#include<stdio.h>
#include<string.h>
main(int argc,char **p)
{
      int a,i,mul=1;
for(i=1;i<argc;i++)
{
a=atoi(p[i]);
mul=mul*a;
}
printf("multiplication:%d\n",mul);
}
