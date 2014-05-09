#include<stdio.h>
main()
{
int a=5,b=-2,c=1;
int d;
d=(a=c)||(b=c)&&(c=b);
printf("%d %d %d %d\n",a,b,c,d);
}
