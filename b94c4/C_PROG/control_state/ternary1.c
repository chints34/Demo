/********highest from three int value****/
#include<stdio.h>
main()
{
int a,b,c;
printf("enter three value:");
scanf("%d%d%d",&a,&b,&c);
(a>b&&a>c)?printf("a is higher"):((b>a&&b>c)?printf("b is higher"):(c>a&&c>b)?printf("c is higher"):printf("invalid"));
}
