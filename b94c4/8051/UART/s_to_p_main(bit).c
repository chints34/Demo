//using bit banging method
#include<reg51.h>
#include"delay.h"
#include"74hc595.h"
main()
{
 unsigned int i;
for(i=0;i<255;i++)
{
 write_74hc595(i);
 delay_1ms(1000);
}
while(1);
}
