#include<stdio.h>
main()
{
int a=0,b=1,sum=0,n;
printf("enter the value of n:");
scanf("%d",&n);
while(sum<n)
{
a=b;
b=sum;
sum=a+b;
printf("%3d",b);
}
printf("\n");
}
