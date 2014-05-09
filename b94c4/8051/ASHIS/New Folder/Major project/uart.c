
#include<reg51.h>
//uart initialisation
void uart_init(void)
 {
  SCON=0x50;  //0101 0000 TO CHOOSE UART MODE 1 and ENABLE THE REN SO THAT UART CAN RECEIVE DATA.
              //[SM0 SM1 SM2 REN TB8 RB8 TI RI]
  
  TMOD=0x20;  //0010 0000 TO CHOOSE TIMER 1 AND MODE 2. 
              //[GATE C/TBAR M1 M0 | GATE C/TBAR M1 M0]
  
  TH1=TL1=253;//for 9600 baud rate 253(256-3) to
  TR1=1;      //TO START TIMER 1
  }
 
//8051 KIT to hyperterminal using uart PERIPHERAL METHOD
void uart_tx(unsigned char dat)
  {
     SBUF=dat;   //KEEP DATA INTO BUFFER TO SEND
	 while(!TI); //WAIT UNTILL TX SECTION IS BUSY TRANSMITTING 8 BITS DATA. 
	             //TI FLAG BECOMES SET i.e. 1 WHEN 8BITS DATA SENDING COMPLETED.
	 TI=0;       //THEN RESET THE TI FLAG.
  }

// Hyperterminal TO 8051 KIT using uart PERIPHERAL METHOD  
unsigned char uart_rx(void)
  {
   while(!RI);  //WAIT UNTILL RX SECTION IS BUSY RECEIVING 8 BITS DATA. 
	            //RI FLAG BECOMES SET i.e. 1 WHEN 8BITS DATA RECEIVING COMPLETED. 
     RI=0;      //THEN RESET THE RI FLAG.
   return SBUF; //DATA RECEIVED IN BUFFER
  }

 //PRINT FUNCTION TO DISPLAY A STRING BY 8051 KIT ON HYPERTERMINAL
 void print(unsigned char *s)
    {
	   
      while(*s)
	   {
	    uart_tx(*s++);
	   }
     }
