#include<stdio.h>
main()
{
int a=1,b=1,c=1,d=1;
b=a++ + a++;
printf("%d %d %d %d\n",a,b,c,d);
c=++d + ++d;
printf("%d %d %d %d\n",a,b,c,d);
c=++a + a++;
printf("%d %d %d %d\n",a,b,c,d);
c=b++ + a++;
printf("%d %d %d %d\n",a,b,c,d);
}
