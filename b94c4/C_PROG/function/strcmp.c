#include<stdio.h>
int cstrcmp(char*,char*);
main()
{
char s1[30]="chintan";
char s2[30]="chintan";
if(cstrcmp(s1,s2)==0)
{
printf("equal\n");
}
else
printf("not equal\n");
}
int cstrcmp(char *p1,char *p2)
{
int i,j;
for(i=0;p1[i];i++)
{
if(p1[i]==p2[i])
{
return 0;
break;
}
return 1;
}
}

