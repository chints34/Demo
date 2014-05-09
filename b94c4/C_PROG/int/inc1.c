#include<stdio.h>
main()
{
int a=1,b=1,c=1,d=1,i;
b=(a++)+(++a)+(a++)+(++a);
printf("%d %d %d %d\n",a,b,c,d);
c=a++ + ++a + ++b + ++d;
printf("%d %d %d %d\n",a,b,c,d);
d=b++ + ++b + b++ + ++b;
printf("%d %d %d %d\n",a,b,c,d);
i=1;
printf("%d %d %d %d\n",i,i++,++i,i++);
}
