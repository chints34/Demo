#include<stdio.h>
main()
{
int a,b;
printf("enter a and b:\n");
scanf("%d%d",&a,&b);
(a==b)?printf("equal"):(a>b)?printf("a is higher"):printf("b is higher");
}
