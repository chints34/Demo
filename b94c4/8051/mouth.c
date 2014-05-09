#include<reg51.h>
#include"lcd.h"
#include"delay.h"
code unsigned char cgram_close[]={0x04,0x0A,0x11,0x17,0x11,0x11,0x0A,0x04};
code unsigned char cgram_open[]={0x04,0x0A,0x11,0x12,0x14,0x12,0x09,0x06};
main()
{
int i;
char *str="welcome to vector";
init_lcd();
cmd_lcd(0x01);
cmd_lcd(0x80);
build_cgram(cgram_close,8);
disp_lcd(0);
cmd_lcd(0x81);
str_lcd(str);
delay_1ms(1000);
cmd_lcd(0x080);
build_cgram1(cgram_open,8);
disp_lcd(1);


while(1)
{
for(i=0;i<16;i++)
  {
   cmd_lcd(0x80+i+1);
   disp_lcd(0);
   cmd_lcd(0x80+i);
   disp_lcd(' ');
   delay_1ms(500);
   cmd_lcd(0x80+i+1);
   disp_lcd(1);
   delay_1ms(500);
  }

 for(i=16;i>0;i--)
   {
    cmd_lcd(0x80+i);
	disp_lcd(0);
	delay_1ms(500);
	cmd_lcd(0x80+i-1);
	disp_lcd(1);
	str_lcd(str+i);
	delay_1ms(500);
   }
delay_1ms(1000);

}
}
