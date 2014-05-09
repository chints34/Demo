#include<stdio.h>
main()
{
int a[5]={2,45,34,12,43},n,i;
printf("%d\n",sizeof(a));
n=sizeof(a)/sizeof(a[0]);
printf("%d\n",n);
for(i=0;i<5;i++)
printf("a[%d]=%dat %u\n",a[i],&a[i]);
}
