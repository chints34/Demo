#include<reg51.h>
#include"74hc165.h"
main()
{

while(1)
{
P1=read_74hc165();
//P1=uart_rx_read74hc165()
}
}
