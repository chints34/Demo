#include<reg51.h>

sbit sw1=P1^4;         sbit sw3=P1^6;
sbit sw2=P1^5;         sbit sw4=P1^7;

void switch_test()
	 {
        bit flag=0;
        unsigned int dly=100,i;
        unsigned char ch=0,g,m;
        print("You are in switch test...\n\r");
        print("Connect P1.4-P1.7 with sw1-sw4 of 8051 Development Board\n\r");
    TST:print("Enter any key to test Switchs...\n\r");
        uart_rx();  
        if(ch==4)
        {
			ch=0;
           print("all switches tested\n\r");
			print("Do You want to test once more?press(y)for Yes and (n)for exit\n\r");
       		g = uart_rx();
       		if(g=='y'||g=='Y')
        	{
				 print("test the switch\n\r");
         		ch=ch;
         		goto TST;
       		 }
       		else if(g=='n'||g=='N')
	     	{
		 	 return;
		 	}
			else
		   {
		    print("Invalid key you entered!try again\n\r");
			goto SWT;
		   }
					
           
        }
        print("press switch");
		
        ch=ch+1;
        uart_tx(ch+48);
        print(" within 100ms of time to test\n\r");
     for(i=2000;i>0;i--)
      {
       for(i=255;i>0;i--);
        
       	if(!(sw1&&sw2&&sw3&&sw4))
        {
          	flag=1;
			
			break;
        
        }
       }
        		
          
 	if(flag==1)
      {
       if(sw1==0)
         {
         ch=1;
         }
       else if(sw2==0)
         {
         ch=2;    
         }
       else if(sw3==0)
         {
          ch=3;
          }
       else if(sw4==0)
         {
          ch=4;
          }
       else
          {
           print("switch");
           uart_tx(ch+48);
           print("is not working\n\r");
		   goto TST;
          }
	   }
		  
	else
       {
       print("switch");
       uart_tx(ch+48);
   	   print("is not pressed within 100ms\n\r");
       ch=ch-1;
       goto TST;
       }
       print("sw");
       uart_tx(ch+48);
       print(" is succesfully pressed\n\r");
	   print("see the switch entered by you is equal to the switch display? \n\r");
  MET:  print("Enter (y)for yes and (n) for no\n\r");
       m=uart_rx();
       if(m=='n'||m=='n')
       {
         print("connection problem. rectify connection according to below specification\n\r");
         print("Connect P1.4-P1.7 with sw1-sw4 of 8051 Development Board\n\r");
         goto TST;
       }
       else if(m=='y'||m=='Y')
       {
       print("Do you want to continue to test next switch?\n\r");
   SWT:print("press(y)for Yes and (n)for exit\n\r");
       g = uart_rx();
       if(g=='y'||g=='Y')
        {
		 print("test Next switch\n\r");
         ch=ch;
         goto TST;
        }
       else if(g=='n'||g=='N')
	     {
		  return;
		 }
		else
		   {
		    print("Invalid key you entered!try again\n\r");
			goto SWT;
		   }
     }
    else
      {
       print("invalid key entered !try again\n\r");
       goto MET;
      }         
     
  }
