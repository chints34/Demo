#include<stdio.h>
main()
{
double f;
char *cp,n,b;
int i;
printf("enter the float:");
scanf("%lf",&f);
cp=&f;
for(i=7;i>=0;i--)
{n=*(cp+i);
for(b=7;b>=0;b--)
{
printf("%d",(n>>b)&1);
}
printf(" ");
}
}
