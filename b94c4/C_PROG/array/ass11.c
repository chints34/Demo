#include<stdio.h>
#include<string.h>
main()
{
char s1[40],s2[20],*ptr;
int cnt=0;
puts("enter s1:");
gets(s1);
puts("enter s2:");
gets(s2);
ptr=s1;
while(ptr=strstr(ptr,s2))
{
cnt++;
ptr++;
}
printf("%d\n",cnt);
}
