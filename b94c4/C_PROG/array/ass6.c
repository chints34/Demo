#include<stdio.h>
main()
{
char s1[10],s2[10],s3[10],s4[100];
printf("enter s1:\n");
scanf("%s",s1);
printf("enter s2:\n");
scanf("%s",s2);
printf("enter s3\n");
scanf("%s",s3);
strcpy(s4,s1);
strcat(s4," ");
strcat(s4,s2);
strcat(s4," ");
strcat(s4,s3);
printf("strings4:%s\n",s4);
}
