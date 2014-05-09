#include<stdio.h>
main()
{
int n,sum=0;
printf("enterthe n:");
scanf("%d",&n);
while(n>10)
{
n%10;
sum=sum+(n%10);
n=n/10;
}
printf("%d\n",sum+n);
}
