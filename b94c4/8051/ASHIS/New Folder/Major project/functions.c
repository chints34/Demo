#include<reg51.h>

#include"uart.h"

#include"ledtest.h"
#include"lcdtest.h"
#include"switchtest.h"
#include"delay.h"
#include"sevensegtest.h"
#include"keypadtest.h"
#include"uarttest.h"
#include"i2ctest.h"
#include"irtest.h"
main()
{

while(1)
{
char ch;
 uart_init(); 
print("             *****                         MENU                        ****                          \n\r");
print("******************************     ENTER (A) TO CHECK LEDs     **************************************\n\r");
print("******************************     ENTER (B) TO CHECK LCD      **************************************\n\r");
print("******************************     ENTER (C) TO CHECK SWITCH   **************************************\n\r");
print("******************************     ENTER (D) TO CHECK 7 SEG    **************************************\n\r");
print("******************************     ENTER (F) TO CHECK KEYPAD   **************************************\n\r");
print("******************************     ENTER (G) TO CHECK UART     **************************************\n\r");
print("******************************     ENTER (H) TO CHECK I2C      **************************************\n\r");
//print("******************************     ENTER (I) TO CHECK SPI      **************************************\n\r");
print("******************************     ENTER (J) TO CHECK IR       **************************************\n\r");
//print("******************************     ENTER (K) TO CHECK DC MOTOR **************************************\n\r");
//print("******************************     ENTER (L) TO CHECK STPR MTR **************************************\n\r");
//print("******************************     ENTER (M) TO CHECK SERVO MTR**************************************\n\r");
print("******************************     ENTER (E) TO EXIT           **************************************\n\r");
print("\n***********************   enter the correct choice in upper case   ********************************\n\r");

ch=uart_rx();

switch(ch)
{

case 'A'://TESTING LEDS
    led_test();
	break;

case 'B':  lcd_test();
	break;

case 'C':switch_test();
	break;

case 'D':sevseg_test();
	break;

case 'F':keypad_test();
	break;

case 'G':uart_test();
	break;

case 'H':i2c_test();
	break;

case 'J':ir_test();
	break;	

case 'I'://spi_test();
	break;

case 'K'://dcmtr_test();
	break;
case 'L'://stprmtr_test();
	break;
case 'M'://servomtr_test();
	break;

case 'E'://exit(0); NOT SUPPORTED IN C51 COMPILER
    return;	
default: print("invalid choice---enter the correct option in upper case\n\r");
    break;



}//end of switch
}//end of while(1)
}//end of main 
	 

