#include<stdio.h>
main()
{
char ch;
printf("enter charactr ch:\n");
scanf("%c",&ch);
if(ch>=48&&ch<=57)
{
printf("number is digit");
goto end;
}
if(ch>=65&&ch<=90)
{
printf("number is upper case\n");
goto end;
}
if(ch>=97&&ch<=122)
{
printf("number is lower case\n");
goto end;
}
printf("it is symbol\n");

end:
printf("\n");
}
