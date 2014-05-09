#include<stdio.h>
char* cmemset(char*,char,int)
{
int i;
char *p1,*p2;
p1=&s1;
p2=&s2;
p1[i]=p2[i];
return *p1;



}
main()
{
char s1[30]="chintan";
char s2[30]="patel";
cmemset(s1+2,'*',3);
printf("%s\n",s1);
}

