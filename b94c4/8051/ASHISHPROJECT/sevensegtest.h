#include<reg51.h>
#define segs_4_mux P0

sbit sel1=P2^0;        sbit sel3=P2^2;
sbit sel2=P2^1;        sbit sel4=P2^3;
//unsigned char dp1=0x80,dp2=0x80,dp3=0x80,dp4=0x80;
void sevseg_test()
  {
    unsigned char d,s,z;
    print("you are in SEVENSEG TEST\n\r");
    print("Connect a-dp pin of seven segment display to P0 and sel1-sel4 P2.0-P2.3\n\r");
TES: print("Enter any key to test SEVEN SEGMENT...\n\r");
    uart_rx();
	P2=0xF0;
    P0=0x00;
    
	
    print("Check all the segment is working or not\n\r");
    print("enter 'y' for yes and 'n' for no\n\r");
    d=uart_rx();
    if(d=='y')
     {
     P2=0x0F;
     RES: print("all the segment are working. do u want to continue?\n\r");
	  s=uart_rx();
	  if(s=='y'||s=='Y')
	    {
		 goto TES;
		 }
	   else if(s=='n'||s=='N')
	     return;
		else
		 {
		  print("invalid choice.try again!\n\r");
		  goto RES; 
		 }
	   }
	   else if(d=='n'||d=='N')
	      {
		   print("problem in displaying seven segment.Error posibility\n\r");
        ERR:print("(1)SEVEN SEGMENT Damaged\n\r");
           print("(2)connection Problem\n\r");
           z=uart_rx();
           if(z=='1')
           {
            print("Sorry!SEVEN SEGMENT Damaged\n\r");
            return;
           }
          else if(z=='2')
          {
          print("Connection ploblem. Connect acccording to above instruction\n\r");
          print("Connect a-dp pin of seven segment display to P0 and sel1-sel4 P2.0-P2.3\n\r");
          goto TES;
          }
       else
         {
          print("Invalid choice.Enter (1)or(2)for error check\n\r");
           goto ERR;
         }
		  
}
}
		 
          
