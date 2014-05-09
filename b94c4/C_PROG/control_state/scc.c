#include<stdio.h>
main()
{
int a,b,c,d;
printf("enter a and b:\n");
scanf("%d%d",&a,&b);
printf("menu\n");
printf("enter 1 for set bit\n");
printf("enter 2 for clear bit\n");
printf("enter 3 for complement bit\n");
scanf("%d",&c);
printf("enter choise=%d\n",c);
d=7;
while(d>=0)
{  
printf("%d",(a>>d)&1);
d--;
}
printf("\n");
if(c==1)
a|=(1<<b);
if(c==2)
a&=~(1<<b);
if(c==3)
a^=(1<<b);

d=7;
while(d>=0)
{
printf("%d",(a>>d)&1);
d--;
}
printf("\n");
}
