#include<stdio.h>
int a,b,c;
main()
{
printf("enter a and b and c");
scanf("%d%d%d",&a,&b,&c);
if(a<b&&a<c)
printf("a is smaller");
if(b<a&&b<c)
printf("b is smaller");
else
printf("c is smaller");
}
