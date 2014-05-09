#include<stdio.h>
main()
{
int a[10],i,max=a[0],min,m=0,n=0;
for(i=0;i<10;i++)
{
printf("a[%d]\n",i);
scanf("%d",&a[i]);

if(a[i]>max)
{
max=a[i];
n=i+1;
}
if(i==0)
min=a[i];

if(a[i]<min)
{
min=a[i];
m=i;
}
}

printf("maximum=%d, position=%d\n",max,n);
printf("minimum=%d , position=%d\n",min,m+1);

}
