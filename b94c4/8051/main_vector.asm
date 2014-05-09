#include<reg51.h>
#include"lcd.h"
#include"delay.h"
main()
{
 unsigned char i;
init_lcd();
while(1)
{
for(i=0;i<10;i++)
 str_lcd("vector");
delay_ms(250);
cmd_lcd(0x01);
delay_ms(250);

}
for(i=0;i<10;i++)
{
cmd_lcd(0x080+i);
str_lcd("vector");
delay_ms(250);
cmd_lcd(0x01);
}
delay_ms(2000);
for(i=0;i<10;i++)
{

cmd_lcd(0x0f-i);
str_lcd("vector");
delay_ms(250);
cmd_lcd(0x01);
}
}
}
