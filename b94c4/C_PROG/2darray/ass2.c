#include<stdio.h>
#include<stdlib.h>
main()
{
int a[5],i,pos,max,cnt,min;
srand(getpid());
for(i=0;i<5;i++)
{
a[i]=rand()%30;
printf("a[%d]=%d\n",i,a[i]);
}
max=0;
for(i=0;i<5;i++)
{
if(a[i]>max)
{
max=a[i];
pos=i;
}
if(i==0)
min=a[0];
if(a[i]<min)
{
min=a[i];
cnt=i;

}

}
printf("max is %d at %d\n",max,pos);
printf("min is %d at %d\n",min,cnt);
}
