/*****print alphabet in loop*****/
#include<stdio.h>
main()
{
int i,j,n;
printf("enter n:");
scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
for(j=1;j<=n-i;j++)
{
printf(" ");
}
for(j=65;j<i+65;j++)
{
printf("%c ",j);
}
}
}
