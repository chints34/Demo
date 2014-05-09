#include<stdio.h>
main()
{
float f;
char *cp,ch;
int i;
printf("enter the float:");
scanf("%f",&f);
cp=&f;
for(i=0;i<=3;i++,printf("\n"))
{
ch=*(cp+i);
printf("%d\n",ch);
}
}
