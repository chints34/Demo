#include<reg51.h>
unsigned int ch,s;
unsigned int i;
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
		uart_str("make following connection\n\r");
		uart_str("ACTIVE LOW:P0.0 TO P0.3\n\r");
		uart_str("ACTIVE HIGH:P0.4 TO P0.7\n\r");
		P0=0xf0;
		uart_str("is leds working fine?\n\r");
		uart_str("press:Y/N(yes or no)\n\r");
		ch=uart_rx();
		if(ch=='n')
		{
			uart_str("please check for proper connection or check any programming mistake\n\r");
		}
		else
			uart_str("LEDS working...");
	}
	if(ch=='2')
	{
		uart_str("make following connection\n\r");
		uart_str("leds:ACTIVE LOW:P0.0 TO P0.3\n\r");
		uart_str("     ACTIVE HIGH:P0.4 TO P0.7\n\r");
		uart_str("switch:ACTIVE LOW:P2.0 TO P2.3\n\r");
		uart_str("       ACTIVE HIGH:P2.4 TO P2.7\n\r");
		//P0=0x0f;
		//while(1)
		
		//	uart_str("press switch 1 to 8\n\r");
		
	
		//uart_str("press switch 1\n\r");
		if(sw1==0)
		{
			P2=0xfe;
			P0=P2;
           uart_str("active low switch 1 is pressed....");
			led1=0;
			break;
		}
		else
			uart_str("switch is not working.....");
		
	//	led2=1;
		
		uart_str("press switch 2\n\r");
		if(sw2==0)
		{
			uart_str("active low switch 2 is pressed....");
			led2=0;
			break;
		}
		else
			uart_str("switch is not working.....");
		
	//	led3=1;
		
		uart_str("press switch 3\n\r");
		if(sw3==0)
		{
			uart_str("active low switch 3 is pressed....");
			led3=0;
			break;
		}
		else
			uart_str("switch is not working.....");
		
	//	led4=1;
		
		uart_str("press switch 4\n\r");
		if(sw4==0)
		{
			uart_str("active low switch 4 is pressed....");
			led4=0;
			break;
		}
		else
			uart_str("switch is not working.....");
		
///////////////active high///////////////
		
	//	led5=0;
		
		uart_str("ACTIVE HIGH SWITCHES....\n\r");
		uart_str("press switch 5\n\r");
		if(sw5==0)
		{
			uart_str("active high switch 5 is pressed....");
			led5=1;
			break;
		}
		else
			uart_str("switch is not working.....");
		
	//	led6=0;
		
		uart_str("press switch 1\n\r");
		if(sw6==0)
		{
			uart_str("active high switch 6 is pressed....");
			led6=1;
			break;
		}
		else
			uart_str("switch is not working.....");
	
	//	led7=0;
		
		uart_str("press switch 7\n\r");
		if(sw7==0)
		{
			uart_str("active high switch 7 is pressed....");
			led7=1;
			break;
		}
		else
			uart_str("switch is not working.....");
		
	//	led8=0;
		
		uart_str("press switch 8\n\r");
		if(sw8==0)
		{
			uart_str("active high switch 8 is pressed....");
			led8=1;
			break;
		}
		else
			uart_str("switch is not working.....");
		}
	
	
}
}

