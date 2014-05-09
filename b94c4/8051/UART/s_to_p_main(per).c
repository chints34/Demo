#include<reg51.h>
#include"delay.h"
#include"uart)mo.h"
#include"utility.h"
main()
{

unsigned char i;
init_uart(1);
for(i=0;i<255;i++)
{
 rev_bits(i);
 uart_tx(x);//x is global var=rev(i)
delay_1ms(1000);

}
while(1);
}
