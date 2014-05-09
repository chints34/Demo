#include"delay.h"
#include<reg51.h.>
sbit led=P2^4;
main()
{
while(1)
{
led=~led;
delay_1ms(100);
}
}									   
