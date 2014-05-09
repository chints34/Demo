#include<stdio.h>
main()
{
int a=1,b=1;
printf("a=%d at &p\n",a,&a);
printf("enter data (int) for a:");
scanf("%d",&a);
printf("a=%d at %p\n",a,&a);
printf("enter data(int) for b:");
scanf("%d",&b);
printf("b=%d at &p\n",b,&b);
}
