#include<stdio.h>
int cfact(int n)
{
if(n==1)
return 1;
return n*cfact(n-1);
}
main()
{
int n;
printf("enter n:");
scanf("%d",&n);
printf("vulue of fact is %d\n",cfact(n));
}
