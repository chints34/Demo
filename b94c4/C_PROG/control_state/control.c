#include<stdio.h>
main()
{
     int a=0,b;
     printf("a=%d\n",a);
     b=7;
test:
     printf("%d",((a>>b)&1?1:0));
     printf("\n");
     b--;
     if(b>=0&&b<=7)
     {
         goto test;
     }
    a++;
    if(a<=255)
    goto test;
}
