#include"utility.h"
sbit P1=P3^2;
void init_uart()
{

//uart mode 0/ren=1
scon=0x10;

}
unsigned char uart_rx_read74hc165()
{

pl=0;
pl=1;
while(!R1);
R1=0;
rev_bits(SBUF);
return x;
}
