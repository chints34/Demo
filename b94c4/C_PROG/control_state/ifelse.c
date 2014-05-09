#include<stdio.h>
main()
{
int m;
printf("enter the marks m:\n");
scanf("%d",&m);
if(m<=40)
printf("fail\n");
if(m>=41&&m<=50)
printf("3rd class\n");
if(m>=51&&m<=60)
printf("2nd class\n");
if(m>=61&&m<=75)
printf("1st class\n");
if(m>=76&&m<=100)
printf("distiction\n");
if(m>100)
printf("invalid input\n");
}
