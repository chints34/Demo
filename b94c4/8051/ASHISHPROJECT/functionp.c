#include"functionp.c"
sbit led1=P0^0;       sbit led5=P0^4;
sbit led2=P0^1;        sbit led6=P0^5;
sbit led3=P0^2;        sbit led7=P0^6;
sbit led4=P0^3;        sbit led8=P0^7;
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
   void led_test()
    {
     unsigned char x,z;
    print("YOU ARE IN LED TEST\n\r");
    print("connect port P0.0-P0.3 to active Low LEDs\nconnect port P0.4-P0.7 to active High LEDs\n\r");
    P0=0x0F;
    CHK:print("Enter any key to test...\n");
    uart_rx();
    P0=0x0F0;
    print("check all the Leds glowing or not?\nenter(Y)for Yes(N)for No\n\r");
    x=uart_rx();
    if(x=='Y'||x=='y')
    {
     print("Yes,All the LEDs are glowing\n");
   	 P0=0x0F;
     return;
    }
    else if(x=='N'||x=='n')
     {
      print("connect port P0.0-P0.3 to active Low LEDs\nconnect port P0.4-P0.7 to active High LEDs\n\r");
      print("Error posibilities...\n");
ERROR:print("Enter key to check error\n\r");
      print("(1)LED Damaged\n");
      print("(2)connection Problem\n");
      z=uart_rx();
      if(z==1)
       {
        print("LED Damaged\n");
        return;
        }
       else if(z==2)
        {
          print("Connection ploblem. Connect acccording to above instruction\n");
          return;
        }
       else
         {
          print("Invalid choice.Enter (1)or(2)for error check\n");
           goto ERROR;
         }
            
     }
     else
        {
         print("invalid choice.Enter (Y)for Yes or(N)for No\n\r");
         goto CHK;    
         }    
    }