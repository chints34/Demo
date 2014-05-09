#include<reg51.h>
//#include"delayp.h"
#define lcd_dat P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;


void write_lcd(unsigned char dat)
  {
   lcd_dat=dat;
 	rw=0;
	en=1;
 	delay_ms(2);
	en=0;
  }
void cmd_lcd(unsigned char cmd)
 {
 	rs=0;
	write_lcd(cmd);
 }
void disp_lcd(unsigned char c)
 {
	rs=1;
	write_lcd(c);
 }
	
void init_lcd(void)
 {
  	cmd_lcd(0x01);
    cmd_lcd(0x02);
 	cmd_lcd(0x06);
	cmd_lcd(0x0c);
	cmd_lcd(0x38);
	cmd_lcd(0x80);
 }