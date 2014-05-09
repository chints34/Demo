#include<stdio.h>
main()
{
char s[10],c;
int i,j=0;
printf("enter a string\n");
scanf("%s",s);
printf("enter charactor\n");
scanf(" %c",&c);
for(i=0;s[i];i++)
{
if(s[i]==c)
j++;
}
printf("occurrence of %c is %d timme\n",c,j);
}
