#include"headers.h"
main()
{
struct timeb t1,t2;
int i,j;
while(1)
  {
    ftime(&t1);
printf("%u %u\n",t1.time,t1.millitm);
sleep(1);
system("clear");

}

}
