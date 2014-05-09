#include<stdio.h>
main()
{
int i,j,n,k;
printf("enter n:");
scanf("%d",&n);
for(i=-n;i<=n;i++,printf("\n"))
{k=i;
if(k<0)
 k=-k;
for(j=1;j<=n+1;j++)
{
if(j<=k)
printf(" ");
else
printf("* ");
}
}
}
