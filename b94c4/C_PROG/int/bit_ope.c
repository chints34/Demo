/*......swapping.....*/
#include<stdio.h>
int a,b;
main()
{
a=10000000,b=209889898989;
a^=b^=a^=b;
printf("%d %d\n",a,b);
}
