#include<reg51.h>
#include"lcd.h"
#include"delay.h"

sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
sbit sw4=P3^3;

unsigned char hrs=00 , mins=00, secs=00;
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
		
}
main()
{
	unsigned char cnt=0;
	init_lcd();
	cmd_lcd(0x80);
	while(1)
	{	
		origin:
		time();
		delay_ms(982);
		if(sw1==0)
		{
			cnt++;
			goto time;
		}
		if(++secs>59)
		{
			secs=0;
			if(++mins>59)
			{
				mins=0;
				if(++hrs>23)
				{
				hrs=0;
				}		  
			}
		}
		goto origin;
time:
		while(1)
		{
			time();
			delay_ms(250);
			if(cnt>3)
				cnt=1;
			if(sw1==0)
				cnt++;
			if(cnt==1)
			{
				disp_lcd(hrs/10+48);
				disp_lcd(hrs%10+48);
				if(sw2==0)
				{
					if(hrs>24)
					hrs=0;
					hrs++;
				}
				if(sw3==0)
				{
					if(hrs<=0)
					hrs=23;
					hrs--;
				}
				if(sw4==0)
				{
					goto origin;
				}					
			}
			if(cnt==2)
			{
				disp_lcd(mins/10+48);
				disp_lcd(mins%10+48);
				if(sw2==0)
				{
					if(mins>60)
					mins=0;
					mins++;
				}
				if(sw3==0)
				{
					if(mins<=0)
					mins=60;
					mins--;
				}
				if(sw4==0)
				{
					goto origin;
				}					
			}
			if(cnt==3)
			{
				disp_lcd(secs/10+48);
				disp_lcd(secs%10+48);
				if(sw2==0)
				{
					if(secs>60)
					secs=0;
					secs++;
				}
				if(sw3==0)
				{
					if(secs<=0)
					secs=60;
					secs--;
				}
				if(sw4==0)
				{
					goto origin;
				}
			}					
		}
	}
}     
