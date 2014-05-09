#include<stdio.h>
main()
{
int a,b,c=1;
printf("enter the a and b:");
scanf("%d%d",&a,&b);
while(b>0)
{
c=c*a;
b--;
}
printf("%d\n",c);
}

