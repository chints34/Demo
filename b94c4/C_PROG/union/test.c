#include<stdio.h>
union st
{
double d;
 long int a;
} ;

main()
{
int i=0;
union st v;
 v.d=10.0;

for(i=63;i>=0;i--)
{
	if((v.a>>i) & 1) 
	 printf("1");
	else 
		printf("0"); 
}
printf("\n");
}
