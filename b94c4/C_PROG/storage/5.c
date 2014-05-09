#include<stdio.h>
extern int g;
main()
{
printf("main:g=%d\n",g);
}
int g=10;
