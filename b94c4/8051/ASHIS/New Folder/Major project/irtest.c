#include<reg51.h>
#include"uart.h"
sbit led=P0^0;

//external interrupt
void ir_test()
{
EA=1;  //ENABLE ALL
EX0=1; //ENABLE EXTERNAL INTERRUPT 0.
print("press remote switch... and enter\n\r");

uart_rx();
}

//THIS ISR WILL BE CALLED WHEN IR-REMOTE IS PRESSED. 
//SIGNAL SENT BY IR REMOTE WILL BE CAUGHT BY THE IR-SENSOR ON THE KIT.
//IN THIS ISR WE ARE COMPLEMENTING LED.
//SO WHENEVER A INTERRUPT COMES THROUGH REMOTE THEN LED STATE IS COMPLEMENTED.
//i.e.,ON EACH BUTTON PRESS ON REMOTE THE LED WILL CHANGE ITS PREVIOUS STATE.

void ISR_EXT(void) interrupt 0   //void ext_int0(void) interrupt 0
{
led=~led;
	print("IR IS WORKING PROPERLY\n\r");
	print("Do You want continue?(press any key to continue:-\n\r");
 	 uart_rx();
       	
} 
