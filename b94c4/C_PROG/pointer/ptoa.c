#include<stdio.h>
#include<string.h>
main()
{
unsigned int a[][3]={{10,20,30},{40,50,60}};
unsigned int (*p)[3];
p=&a;
int i;
for(i=0;i<6;i++)
printf("%u\n",p[0][i]);
//printf("%u\n",*p+1);
//printf("%u\n",*p[1]);


}
