#include<reg51.h>
#include"uart_mo(per).h"

main()
{
init_uart();
while(1)
{
P1=uart_rx_read74hc165();

}


}
