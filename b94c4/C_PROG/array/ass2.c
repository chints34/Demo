#include<stdio.h>
main()
{
char c[10];
int i,b=0,n=0,d=0,m=0;
for(i=0;i<10;i++)
{
printf("c[%d]\n",i);
scanf(" %c",&c[i]);
if(c[i]>=48&&c[i]<=57)
b++;
if(c[i]>=65&&c[i]<=90)
n++;
if(c[i]>=97&c[i]<=122)
d++;
}
printf("number of digit=%d\n",b);
printf("number of upper case=%d\n",n);
printf("number of lower case=%d\n",d);
printf("number of special character=%d\n",10-b-n-d);
}
