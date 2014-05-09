#include<reg51.h>
#include"delay.h"
#include"uart.h"
#include"lcdtest.h"
sbit SCL=P3^0;
sbit SDA=P3^1;

/*
void i2c_start(void);
void i2c_write(unsigned  char dat);
void i2c_ack(void);

void i2c_stop(void);
char i2c_read(void);
void i2c_nock(void);
*/
extern unsigned char ch;
char buff;
void i2c_start(void)
{
	SCL=1;
    SDA=1;
	SDA=0;
}

void i2c_write(unsigned char dat)
{
	char i;
	for(i=0;i<8;i++)
	{
		SCL=0;
		SDA=(dat&(0x80>>i))?1:0;
		SCL=1;
	}
}


void i2c_ack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;
	SCL=0;
}


void i2c_stop(void)
{
	SCL=0;
	SDA=0;
	SCL=1;
	SDA=1;

}


unsigned char i2c_read()
{
	unsigned char i,buff=0;
//	SDA=1;
	for(i=0;i<8;i++)
	{
		SCL=1;
		if(SDA)
		{
			buff|=((0x80)>>i);
		}
		SCL=0;
	}
	return buff;
}


void i2c_noack(void)
{
	SCL=0;
	SDA=1;
    SCL=1;
	//SCL=0;
}


void eeprom_write(unsigned char sa,unsigned char add,unsigned char dat)
{
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(add);
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();
	delay_ms(10);
}


unsigned  eeprom_read(unsigned char sa,unsigned char add)
{
	unsigned char buff1;
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(add);
	i2c_ack();
	i2c_start();
	i2c_write(sa|0x01);
	i2c_ack();
	buff1=i2c_read();
	i2c_noack();
	i2c_stop();
	return(buff1);
}

//I2C TEST FUNCTION
void i2c_test()
{

			
	l7:		print("I2C TESTING\n\r");
			print("connect lcd(PO to D0-D7) and P2.1-P2.3 to rs,rw,en and connect scl to P3.0 and sda to P3.1\n\r"); 
			print("PRESS ENTER TO CONTINUE AFTER HARDWARE CONNECTION\n\r");
			
			uart_rx();
				
			//	if(ch==0x0d)
			//	{
					init_lcd();
					disp_lcd('C');
					
					eeprom_write(0xa0,0x03,'c');
					delay_ms(1000);
					cmd_lcd(0xc0);
					buff=eeprom_read(0xa0,0x03);
					disp_lcd(buff);
					
					print("IS TX and RX ARE WORKING PROPERLY... ???\n\r");
				    print("Press y-YES (or) n-N0  (or)  e-Exit\n\r");
					print("\n\r");
					ch=uart_rx();
					if(ch=='y')
					{
						print("Do you want to continue?\n\r");
						print("Press y-YES (or) n-N0  (or)  e-Exit\n\r");
						ch=uart_rx();
						if(ch=='y')
				  			goto l7;
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
						print("following are the possibilities of the error:-\n\r");
					
						print("\n\r");
											
						print("1.program logic\n\r");
				
						print("2.hardware conection\n\r");
				
						print("3.check with the other (KEYPAD OR KIT)component n verify WHETHER IT remainS closeD or ON\n\r");
				
					}
					else if(ch=='e')
						return;
			//	}
}
