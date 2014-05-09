#include"lcd.h"
#include"delay.h"
code unsigned char cgram_lut_0[]=
//{0x1D,0X05,0X05,0X1F,0X14,0X14,0X07,0X00};	//FOR ASCII VALUE 0
{0x04,0X0A,0X11,0X1F,0X11,0X0A,0X04,0X00};	//CLOSE FACE


code unsigned char cgram_lut_1[]=
{0x1F,0X1E,0X1C,0X10,0X18,0X1C,0X1F,0X00};		//OPEN FACE	
main()
{
	unsigned char i;
	init_lcd();
	build_cgram_0(cgram_lut_0,8);
	build_cgram_1(cgram_lut_1,8);
	cmd_lcd(0x81);
	str_lcd("ASHISH");

	for(i=0x80;i<0x88;i++)
	{
		cmd_lcd(i);
		disp_lcd(1);
		delay_ms(2000);
		cmd_lcd(i);
		disp_lcd(' ');
		cmd_lcd(i+1);
		disp_lcd(0);
		delay_ms(2000);	
	}
	
	cmd_lcd(0x01);
	str_lcd("BYEE....");
	while(1);
}

