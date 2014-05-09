#include<reg51.h>
#include"uart.h"

unsigned char ch;
void uart_test()
{

                   
		l6:   print("testing uart...\n\r"); // print is uart_string fn
			
					print("UART PERIPHERAL IS WORKING PROPERLY\n\r");
					print("Press y-YES (or) n-N0  (or)  e-Exit\n\r");
					print("\n\r");
					ch=uart_rx();
					if(ch=='y')
					{
						print("Do you want to continue\n\r");
						print("Press y-YES (or) n-N0  (or)  e-Exit\n\r");
						ch=uart_rx();
						if(ch=='y')
				  			goto l6;
				 		else if((ch=='n')|(ch=='e'))
				 		{
							P0=0x0f;
							return;
						}
						else
							print("plz press valid key to continue\n\r");
					}
					else if(ch=='n')
					{
						print("Error Possibilities...\n\r");
					
						print("\n\r");
											
						print("check the program logic\n\r");
				
						print("check the hardware conection\n\r");
				
										
					}
					else if(ch=='e')
						return;
}
