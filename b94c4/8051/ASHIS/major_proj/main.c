#include<reg51.h>
//#include<keypad.h>
unsigned int ch,s;
unsigned int i;
#define leds P0;
sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;
sbit led5=P0^4;
sbit led6=P0^5;
sbit led7=P0^6;
sbit led8=P0^7;
sbit sw1=P2^0;
sbit sw2=P2^1;
sbit sw3=P2^2;
sbit sw4=P2^3;
sbit sw5=P2^4;
sbit sw6=P2^5;
sbit sw7=P2^6;
sbit sw8=P2^7;


void uart_init()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=TL1=-3;
	TR1=1;
}
void uart_tx(unsigned char c)
{
	uart_init();
	SBUF=c;
	while(!TI);
	TI=0;
}
unsigned char uart_rx()
{
	while(!RI);
	RI=0;
	return SBUF;
}
void uart_str(unsigned char *p)
{
	while(*p)
	{
		uart_tx(*p++);
	}
}
main()
{
while(1)
{
	uart_str("8051 TEST KIT PROGRAM\n\r");
	uart_str("PRESS KEY TO START TESTING....\n\r");
	uart_str("1>LED testing\n\r");
	uart_str("2>SWITCH testing\n\r");
	uart_str("3>KEYPAD testing\n\r");
	uart_str("4>7_SEGMENT testing\n\r");
	uart_str("5>LCD testing\n\r");
	uart_str("6>UART testing\n\r");
	uart_str("7>I2C testing\n\r");
	uart_str("8>SPI testing\n\r");
	uart_str("9>IR testing\n\r");

	ch=uart_rx();


if(ch=='1')
{
uart_str("connect active leds to p0.0 to p0.3\n");
uart_str("connect active high leds to p0.4 to p0.7\n");
P0=0x0F;
uart_str("is leds is working\n");
uart_str("press 'y' for yes or 'n' for no\n");
ch=uart_rx();
if(ch=='n')
{
uart_str("check the connection\n");

}
else
uart_str("leds working properly\n");

}
if(ch=='2')
{
P0=0x0f;
uart_str("make following connection\n");
uart_str("sw1 to sw4 connect to p0.0 to p0.3\n");
uart_str("sw5 to sw8 connect to p0.4 to p0.7\n");
while(1)
 { 
    if(sw1==0) 
     {
      P0=0x0e;
      uart_str("switch 1 is pressed\n");
      break;
     }
   if(sw2==0)
    {
     P0=0x0d;
      uart_str("switch 2 is pressed\n");     
     break;
     }
   if(sw3==0)
    {
      P0=0x0b;
      uart_str("switch 3 is pressed\n");     
      break;
    }
  if(sw4==0)
    { 
      P0=0x07;
      uart_str("switch 4 is pressed\n");     
      break;
    }
   if(sw5==0)
    {
     P0=0x1f;
     uart_str("switch 5 is pressed\n");
     break;
    }
   if(sw6==0)
   {
    P0=0x2f;
    uart_str("switch 6 is pressed\n");
    break;
   }
  if(sw7==0)
   {
    P0=0x4f;
    uart_str("switch 7 is pressed\n");
    break;
    }
   if(sw8==0)
    {
     P0=0x8f;
     uart_str("switch 8 is pressed\n");
     break;
    }
}
  uart_str("switch is working???\n"); 
  uart_str("presee 'n' for not\n");
  ch=uart_rx();
 if(ch=='n')
     {
        uart_str("CHECK HARDWARE CONNECTION PROPER OR NOT\n");

     }
    else
        uart_str("SWTCH WORKING PROPERLY..\n");
/*if(ch=='3')
  {
   uart_str("PRESS THE KEY FROM KEYPAD\n");
  while(1)
    {
     leds=~keyscan();
     break;
    }
   uart_str("KEYPAD IS WORKING OR NOT??\n");
	uart_str("PRESS N FOR NOT WORKING\n");   
ch=uart_rx()
   if(ch=='n')
   {
    uart_str("CHECK THE CONNECTION MADE PROPERLY OR NOT\n");
   }
  else
   { 
	uart_str("KEYPAD WORKING PROPERLY\n");*/
  }
}
}

//}

//}

