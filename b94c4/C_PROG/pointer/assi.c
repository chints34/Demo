#include<stdio.h>
main()
{
float f;
int *ip,n,b;
int i;
printf("enter the float:");
scanf("%f",&f);
ip=&f;
n=*ip;
for(b=5;b>=0;b--)
{
printf("%d",(n>>b)&1);
}
}
