#include<stdio.h>
main()
{
int (*p)[5],a;
p=&a;
printf("%u\n",p);
printf("%u\n",p+1);
printf("%u\n",*p);
printf("%u\n",*p+1);
}
