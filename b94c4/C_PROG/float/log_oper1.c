#include<stdio.h>
int a=2,b=0,c=0;
int d;
main()
{
d=(a=b)||(b=c)||(c=a);
printf("%d %d %d %d\n",a,b,c,d);
}
