#include<stdio.h>:
void print(int b)
{
printf("b=%d\n",b);
}
main()
{
static int a=5;
print(a);
}
