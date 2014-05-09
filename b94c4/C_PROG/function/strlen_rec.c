#include<stdio.h>
int cstrlen(const char *p)
{
int cnt=0;
if(*p)
{
cnt=1+cstrlen(p+1);
}
return cnt;
}
main()
{
int n;
char str[30]="chintan";
n=cstrlen(str);
printf("%d\n",n);
}
