#include<stdio.h>
#include<string.h>
main(int n,char **p)
{
      float a,b,c;
if(n>3)
{
printf("eror:invalid data\n");
return;
}
else
{
a=atof(p[1]);
b=atof(p[2]);
c=a+b;
printf("%f+%f=%f\n",a,b,c);
}
}
