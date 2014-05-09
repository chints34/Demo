#include"headers.h"
main()
{
int i,j;
time_t t1,t2;
t1=time(0);
for(i=0;i<999999;i++);
   for(j=0;j<9999;j++);
t2=time(0);
printf("loop time:%d seconds\n",t2-t1);


}
