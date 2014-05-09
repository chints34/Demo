#include<stdio.h>
#include<string.h>
main()
{
char s[30],ch=' ';
int i;
puts("enter s:");
gets(s);

for(i=0;s[i];i++)
{
if(ch==s[i])
strcpy(s+i,s+i+1);
}
printf("string:%s\n",s);

}

