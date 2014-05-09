#include<reg51.h>
#include"uart.h"
unsigned char row,col;
bit flag1=0;
/*
sbit r0=P2^4; 		sbit c0=P2^0;
sbit r1=P2^5; 		sbit c1=P2^1;
sbit r2=P2^6; 		sbit c2=P2^2;
sbit r3=P2^7; 		sbit c3=P2^3;
*/
sbit c0=P2^4; 		sbit r0=P2^0;
sbit c1=P2^5; 		sbit r1=P2^1;
sbit c2=P2^6; 		sbit r2=P2^2;
sbit c3=P2^7; 		sbit r3=P2^3;

code unsigned char keypad_lut[4][4]=
                              {
                                  1, 2, 3, 4,
                                  5, 6, 7, 8,
                                  9, 10,11,12,
                                  13,14,15,16
						      };
bit colscan()
 {
  return(c0&c1&c2&c3);
 }

void keypad_test()
{
	 
       unsigned char k,h,sw;
	   unsigned int i,j;
	
	r0=r1=r2=r3=0;
    c0=c1=c2=c3=1;
    flag1=0;
   
   print("You are in Keypad test...\n\r");
  // KEY:print("Connect R0-R3 to P2.4-P2.7 and C0-C3 to P2.0-P2.3\n\r");
  KEY:print("Connect C0-C3 to P2.4-P2.7 and R0-R3 to P2.0-P2.3\n\r");
    
k1: print("Enter any key to test keypad...\n\r");
    
    uart_rx();
      
	print("press keypad switch within 100ms time\n\r");
	  
     

	for(i=0;i<=2048;i++)
	{
	for(j=0;j<=1024;j++);
    if(!colscan())
	{
		flag1=1;
		break;
	}
    
	}	
   
     r0=0;
     r1=r2=r3=1;
      if(!colscan())
        {
         row=0;
		 goto colcheck;
	    }

     r1=0;
     r0=r2=r3=1;
      if(!colscan())
       {
        row=1;
		goto colcheck;
	   }
    
     r2=0;
     r0=r1=r3=1;
      if(!colscan())
       {
        row=2;
	    goto colcheck;
	   }

     r3=0;
     r0=r1=r2=1;
      if(!colscan())
       {
        row=3;
	   }

colcheck:
        if(c0==0)
          col=0;

        if(c1==0)
          col=1;

        if(c2==0)
          col=2;

        if(c3==0)
          col=3;

         if(flag1==1) // *
          {
			while(!colscan());
			k=keypad_lut[row][col];
            
			print("value of keyscan is\n\r");
            uart_tx(k+48);
          
		   if(k>=1&&k<=16)
           {
	           print("keypad scan success...\n\r");
			   print("Release pressed key...\n\r");
			   while(!colscan());
	     KIT:  print("Do You want to continue keypad test?\n\r");
	           print("Enter 'y'for contiue and 'n' for exit\n\r");
	           j=uart_rx();
	           if(j=='y'||j=='Y')
	             {
	              print("continue keypad test...\n\r");
				  
				  goto k1;
	             }
	           else if(j=='n'||j=='N')
	             {
	              print("exiting from keypad test\n\r");
	              return;
	             }
	           else
	              {
	              print("Invalid choice.Tryagain!\n\r");
	              goto KIT;         
	              }
            }       
        
		    else if(flag1==0)
            {
	         SCH: print("Did you Pressed the keypad switch?(y)for Yes and (n)for No\n\r");
            h=uart_rx();
             if(h=='y'||h=='Y')
              {
                print("keypad is not working\n\r");
            
		 	    print("keypad");
                sw=4*row+col;
                uart_tx(sw+48);
                print("is not working\n\r");
           
          	  }
          	 else if(h=='n'||h=='N')
              {
			   print("NO keypad switch pressed within 100ms time\n\r");
               goto KEY;
              }
             else
              {
               print("Invalid choice. try again!\n\r"); 
               goto SCH;
              }
            }

            else
            {
             print("Connetction problem.Check connection\n\r");
             goto KEY;     
		    }
         
			
		}//end of *
 
     
         
           
}//end of keypadtest fn
     