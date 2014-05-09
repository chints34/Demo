#include<stdio.h>
main()
{
int i,j,n;
printf("enter n:");
scanf("%d",&n);
for(i=1;i<=n;i++,printf("\n"))
{
for(j=n;j>=i;j++)
printf(" ");
for(j=1;j<=i;j++)
printf("* ");
}
for(j=n;j>=0;j--)
printf("* ");
printf("\n");
for(i=1;i<=n;i++,printf("\n"))
{
for(j=1;j<=i;j++)
printf(" ");
for(j=n;j>=i;j--)
printf("* ");
}
}
