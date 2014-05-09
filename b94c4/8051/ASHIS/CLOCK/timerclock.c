#include<reg51.h>
#include"lcd.h"
//#include"delay.h"
//#include"delay.c"
//#include"lcd.c"
#include"delay.h"
unsigned char hrs=11 , mins=50, secs=50;
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
sbit sw4=P3^3;




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
		unsigned int cnt=0;
		init_lcd();
		while(1)
		{
main1:
			time();
			
			delay_ms(982);
			secs++;
			
			if(secs>59)
			{
				if(sw4==0)
				{
					//while(!sw4);
					secs=secs;
					goto l1;	
				}
				secs=0;
				mins++;
				if(sw1==0)
				goto l1;
				if(mins>59)
				{
					mins=0;
				if(sw1==0)
					{
				goto l1;
					//secs=secs;
					}
					hrs++;
					if(hrs>23)
				{
				if(sw1==0)
				
					goto l1;
					hrs=0;
					}
				}
			}

l1:			if(sw1==0)
				{
				while(sw1==0);		
				 cnt++;
				delay_ms(100);
					}
					if(sw4==0)
				{
					while(!sw4);
					secs=secs;	
				}
				if(cnt==1)
				goto hours;

				else if(cnt==2)
				goto minits;

				else if(cnt==3)
				goto seconds;
				
				else if(cnt==4)
					cnt=0;
					

		}
hours:
if(sw2==0)
	{
				while(sw2==0);		
				hrs++;
	}
		time();
		
 if(sw3==0)
		{

				while(sw3==0);		
			hrs--;
		}
			time();
			goto main1;
minits:

if(sw2==0)
	{
		while(sw2==0);
		mins++;
	}
		time();
 if(sw3==0)
	{
		while(sw2==0);
		mins--;
	}
			time();
			goto main1;


seconds:

if(sw2==0)
	{
		while(sw2==0);
		secs++;
	}
		time();
 if(sw3==0)
	{
		while(sw2==0);
		secs--;
	}
			time();
			goto main1;

}