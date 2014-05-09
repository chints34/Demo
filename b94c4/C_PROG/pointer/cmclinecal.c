#include<stdio.h>
#include<stdlib.h>
main(int n,char **p)
{
int a,b,i;
float c,d;
for(i=0;i<n;i++)
{
a=atoi(p[1]);
b=atoi(p[3]);
}
if(p[2][0]=='+')
printf("sum:%d+%d=%d\n",a,b,a+b);
else if(p[2][0]=='*')
printf("mul:%d*%d=%d\n",a,b,a*b);
else if(p[2][0]=='-')
printf("sub:%d-%d=%d\n",a,b,a-b);
else if(p[2][0]=='/')
{
c=(float)a;
d=(float)b;
printf("div:%f/%f=%f\n",c,d,c/d);
}
}
