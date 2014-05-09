#include<stdio.h>
main()
{
int a=1,b=1,c=1,d=1;
a=b++ + c++;
printf("%d %d %d %d\n",a,b,c,d);
b=++c + ++d + a++;
printf("%d %d %d %d\n",a,b,c,d);
c=++a + ++d + b++;
printf("%d %d %d %d\n",a,b,c,d);
d=a++ + ++b + ++c;
printf("%d %d %d %d\n",a,b,c,d);
}
