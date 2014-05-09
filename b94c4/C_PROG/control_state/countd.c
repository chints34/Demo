/*******count the digit********/
#include<stdio.h>
main()
{
int a,b,c,i=0;
printf("enter the digit\n");
scanf("%d",&a);
test:  b=a%10;
       a=a/10;
       i++;
   if(a!=0)
{
goto test;
}
printf("%d\n",i);
}
