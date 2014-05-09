#include<stdio.h>
main()
{
char s1[40],s2[20];
int pos;
puts("enter s1:");
gets(s1);
puts("enter s2:");
gets(s2);
printf("enter pos:");
scanf("%d",&pos);
strcpy(temp,s1+pos);
strcpy(s1+pos,s2);
strcat(s1,temp);
printf("string:s1=%s\n",s1);
printf("s2

}
