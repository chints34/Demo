#include<stdio.h>
main()
{
int i,j,a[5][3],sum,max=0,pos;
srand(getpid());
for(i=0;i<5;i++,printf("\n"))
for(j=0;j<3;j++)
{
a[i][j]=rand()%30;
printf("a[%d][%d]=%d\n",i,j,a[i][j]);
}
for(i=0;i<5;i++)
{
sum=0;
for(j=0;j<3;j++)
{
sum=sum+a[i][j];
if(sum>max)
{max=sum;
pos=i;
}}}
printf("max is %d at %d\n",max,pos);
}
