#include<stdio.h>
main()
{
double f;
int *ip,n,b;
int i;
printf("enter the float:");
scanf("%lf",&f);
ip=&f;
for(i=1;i>=0;i--)
{n=*(ip+i);
for(b=10;b>=0;b--)
{
printf("%d",(n>>b)&1);
}
printf(" ");
}
}
