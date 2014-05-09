/*******xchange nibble of int*********/
#include<stdio.h>
main()
{
int num,b,c;
printf("enter the number\n");
scanf("%d",&num);
b=num>>8;
c=num<<8;
num=b|c;
printf("%d",num);
}

