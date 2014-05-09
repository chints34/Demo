#include<reg51.h>
#include"lcd.h"
#include"delay.h"
unsigned char hrs=11,mins=54,secs=23;
void time()
{
 cmd_lcd(0x01);
 disp_lcd((hrs/10)+48);
 disp_lcd((hrs%10)+48);
 disp_lcd(':');

 disp_lcd((mins/10)+48);
 disp_lcd((mins%10)+48); 
 disp_lcd(':');

 disp_lcd((secs/10)+48);
 disp_lcd((secs%10)+48);
 disp_lcd(':');
}
main()
{
init_lcd();
while(1)
{
 time();
delay_1ms(982);
secs++;

if(secs>59)
{
secs=0;
mins++;

if(mins>59)
{
mins=0;
hrs++;

if(hrs>23)
{
hrs=0;
}
}
}
}
}
