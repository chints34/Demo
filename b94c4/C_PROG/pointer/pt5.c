/*****generatic pointer*****/
#include<stdio.h>
main()
{
float f=1.0,f1;
int i=12345,i1;
char c='A',c1;
void *p;
p=&f;
f1=*(float*)p;
p=&i;
i1=*(int*)p;
p=&c;
c1=*(char*)p;
printf("%d %f %c\n",i1,f1,c1);
}
