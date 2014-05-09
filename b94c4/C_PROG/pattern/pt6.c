/******pyramid using if else*****/
#include<stdio.h>
main()
{
int i,j,n,k;
printf("enter n:");
scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
for(j=1;j<=n;j++)
{
if(j<=n-i)
printf(" ");
else
printf("* ");
}
}
}

