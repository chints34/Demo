#include<stdio.h>
main()
{
char str[3][10];
int i,j;
for(i=0;i<3;i++)
{
printf("enter string str[%d]",i);
gets(str[i]);
}
for(j=0;j<3;j++)
{
printf("%s\n",str[j]);
}
}

