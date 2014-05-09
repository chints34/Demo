#include<stdio.h>
main()
{
int i=0x12345678;
char *cp,ch;
cp=&i;
printf("%x",*(int*)cp);

}
