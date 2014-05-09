
#include<reg51.h>
#include"uart.h"

sbit led1=P0^0;        sbit led5=P0^4;
sbit led2=P0^1;        sbit led6=P0^5;
sbit led3=P0^2;        sbit led7=P0^6;
sbit led4=P0^3;        sbit led8=P0^7;

//LED TEST    
void led_test()
    {
    unsigned char x,z;
    print("YOU ARE IN LED TESTING MODULE\n\r");
    
	//[ACTIVE HIGH LEDs AT P0.0 TO P0.3 | ACTIVE LOW LEDs AT P0.4 TO P0.7]
	print("connect port P0.0-P0.3 to active Low LEDs\tconnect port P0.4-P0.7 to active High LEDs\n\r");
    P0=0x0F; //OFF ALL LEDs
    
	//TESTING
	print("TESTING..\n\r");
	CHK:print("Enter any key to test...\n\r");
    uart_rx();
    P0=0xF0; //ON ALL LEDS  OR 0x0F0
    print("check all the Leds glowing or not?\nenter(Y)for Yes(N)for No\n\r");
    x=uart_rx();
    if(x=='Y'||x=='y')
    {
     print("Yes,All the LEDs are glowing\n\r");
   	 P0=0x0F; //OFF ALL LEDs
     return;
    }
    else if(x=='N'||x=='n')
     {
      print("connect port P0.0-P0.3 to active Low LEDs\nconnect port P0.4-P0.7 to active High LEDs\n\r");
 ERROR:     print("Error posibilities...\n\r");

	  print("check whether ANY LED IS DAMAGED...\n\r");
      print("TYPE (1) IF LED Damaged\n");

	  print("check IF any CONNECTION IS WRONG...\n\r"); 
      print("TYPE (2) IF connection Problem\n\r");
      z=uart_rx();
      if(z=='1')
       {
        print("Sorry!LED Damaged\n\r");
        return;
        }
       else if(z=='2')
        {
          print("Connection pRoblem. Connect acccording to above instruction\n\r");
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

}//end of led_test fn
