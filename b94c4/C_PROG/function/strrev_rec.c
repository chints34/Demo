#include<stdio.h>
char *strev(char *p,int i)
{
static int i;
if(p[i])
{
strev(p,i+1);
}
t=p[i];
p[i]=p[j];
p[j]=t;
j++;
}
main()
{
char str[50];
gets(str);
strev(str);
puts(str);
