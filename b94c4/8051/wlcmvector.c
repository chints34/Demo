#include"lcd.h"
#include"delay.h"
main()
{
int i;
char str[20]="welcome vector";
code unsigned char cgram_lut[]={0x0E,0x11,0x11,0x1F,0x11,0x11,0x0E,0x00};
code unsigned char cgram_lut1[]={0x0E,0x14,0x18,0x10,0x18,0x14,0x0E,0x00};
code unsigned char cgram_lut2[]={0x00,0x00,0x00,0x00,0x100,0x00,0x00,0x00};
build_cgram(cgram_lut,8);
init_lcd();
//cmd_lcd(0x80);
//disp_lcd(0);
//str_lcd(str+i);
delay_1ms(100);
for(i=0;i<=14;i++)
{
cmd_lcd(0x01);
cmd_lcd(0x80+i+1);
str_lcd(str+i);
build_cgram(cgram_lut,8);
cmd_lcd(0x80+i);
disp_lcd(0);
delay_1ms(1000);
build_cgram(cgram_lut1,8);
cmd_lcd(0x80+i);
disp_lcd(0);
delay_1ms(1000);
build_cgram(cgram_lut2,8);
cmd_lcd(0x80);
disp_lcd(0);
delay_1ms(1000);

}
while(1);
}

