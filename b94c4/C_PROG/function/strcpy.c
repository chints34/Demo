#include<stdio.h>
char* cstrcpy(char*,char*);
main()
{
char s1[30]="chintan";
char s2[30]="patel";
cstrcpy(s1,s2);
printf("%s\n",s1);
printf("%s\n",s2);
}
char* cstrcpy(char *p1,char *p2)
{
int i;
for(i=0;p1[i];i++)
p1[i]=p2[i];
return *p1;
}
