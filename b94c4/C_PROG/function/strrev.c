#include<stdio.h>
#include<string.h>
char *strrev(char *p)
{
int i,j,n,temp;
n=strlen(p);
for(i=0,j=n-1;i<j;i++,j--)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
return p;

}
main()
{
char str[100];
gets(str);
strrev(str);
puts(str);
}
