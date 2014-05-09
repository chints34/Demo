#include<stdio.h>
main()
{
static int a;
int b;
b=a;
a++;
if(a<5)
main();
printf("a=%d b=%d\n",a,b);
}
