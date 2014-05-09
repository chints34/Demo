#include<stdio.h>
main()
{
int i=1,j=1;
printf("before loop:i=%d j= %d\n",i,j);
while(i<=5)
{
   j=1;
   while(j<=i)
   {
   printf("inner loop:i=%d j=%d\n",i,j);
   j++; 
    
   }
   i++;
   }
  printf("after loop:i=%d j=%d\n",i,j);
}
                
