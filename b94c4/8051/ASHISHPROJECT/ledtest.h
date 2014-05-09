#include<reg51.h>

sbit led1=P0^0;        sbit led5=P0^4;
sbit led2=P0^1;        sbit led6=P0^5;
sbit led3=P0^2;        sbit led7=P0^6;
sbit led4=P0^3;        sbit led8=P0^7;
void led_test()
    {
     unsigned char x,z;
    print("YOU ARE IN LED TEST...\n\r");
    print("connect port P0.0-P0.3 to active High LEDs\n\r");
	print("connect port P0.4-P0.7 to active Low LEDs\n\r");
    P0=0xF0;
CHK:print("Enter any key to test LEDs...\n\r");
    uart_rx();
    P0=0x0F;
    print("check all the Leds glowing or not?enter(Y)for Yes(N)for No\n\r");
    x=uart_rx();
    if(x=='Y'||x=='y')
    {
     print("ALL LEDs are fine\n\r");
	 P0=0xF0;
   	 return;
    }
    else if(x=='N'||x=='n')
     {
ERROR:print("connect port P0.0-P0.3 to active High LEDs\n\r");
      print("connect port P0.4-P0.7 to active Low LEDs\n\r");
      print("Error posibilities...\n\r");
      print("Enter key to check error\n\r");
      print("(1)LED Damaged\n\r");
      print("(2)connection Problem\n\r");
      z=uart_rx();
      if(z=='1')
       {
        print("Sorry!LED Damaged\n\r");
        return;
        }
       else if(z=='2')
        {
          print("Connection ploblem. Connect acccording to above instruction\n\r");
          return;
        }
       else
         {
          print("Invalid choice.Enter (1)or(2)for error check\n\r");
           goto ERROR;
         }
            
     }
     else
        {
         print("invalid choice.Enter (Y)for Yes or(N)for No\n\r");
         goto CHK;    
         }    
    }
