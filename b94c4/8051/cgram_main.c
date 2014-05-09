#include<reg51.h>
#include"lcd.h"
code unsigned char cgram_lut[]={0x1d,0x05,0x05,0x1f,0x14,0x14,0x07,0x00};
main()
{
 init_lcd();
 build_cgram(cgram_lut,8);
 disp_lcd(0);
 cmd_lcd(0xc0);
 disp_lcd('0');
 while(1);

}
