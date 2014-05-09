#include<stdio.h>
main()
{
 int n,temp;
short int *p;
printf("enter the n:\n");
scanf("%d",&n);
p=&n;
printf("%d\n",*p);
if(*p==n)
 {
printf("little endian\n");
temp=*p;
*p=*(p+1);
*(p+1)=temp;
printf("%d",*p);
}
}
