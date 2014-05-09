#include<reg51.h>

void uart_init(void)
 {
  SCON=0x50;
  TMOD=0x20;
  TH1=TL1=253;
  TR1=1;
  }
void uart_tx(unsigned char dat)
  {
     SBUF=dat;
	 while(!TI);
	   TI=0;
   }
unsigned char uart_rx(void)
  {
   while(!RI);
     RI=0;
   return SBUF;
  }
void print(unsigned char *s)
  {
   while(*s)
	{
	 uart_tx(*s++);
	}
  }
      
   
	
   




   //void sevseg_test()
    //{
     
