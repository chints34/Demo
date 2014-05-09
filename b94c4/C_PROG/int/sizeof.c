#include<stdio.h>
char ch;
main()
{
int a=1,b=20;
ch='C';
printf("%d\n",sizeof(a));
printf("%d\n",sizeof(b));
printf("%d\n",sizeof(char));
printf("%d\n",sizeof('DC'));
printf("%d\n",sizeof("hello.12"));
printf("%d\n",sizeof("12.678"));
}
