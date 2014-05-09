#include<stdio.h>
int a,b,c;
main()
{
a=10,b=20;
printf("%d %d\n",a,b);
c=a;
a=b;
b=c;
printf("%d %d\n",a,b);
}
