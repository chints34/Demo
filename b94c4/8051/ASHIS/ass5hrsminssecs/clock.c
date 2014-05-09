#include<reg51.h>
#include"lcd.h"
#include"delay.h"
unsigned char hrs=22,
			  mins=49,
			  secs=35;
int cnt=0;

sbit sw1=P3^4;
sbit sw2=P3^5;
sbit sw3=P3^6;
sbit sw4=P3^7;
//sbit sw5=P3^4;

void time()
{
 cmd_lcd(0x80);
 disp_lcd((hrs/10)+48);
 disp_lcd((hrs%10)+48);
 disp_lcd(':');

 disp_lcd((mins/10)+48);
 disp_lcd((mins%10)+48); 
 disp_lcd(':');

 disp_lcd((secs/10)+48);
 disp_lcd((secs%10)+48);
// disp_lcd(':'); no colon here
}

//continue funtion


//edit time function
edit()
{
	while(1)
	{
			
			if(sw1==0)
			{
			while(!sw1);
			cnt++;
			if(cnt>4)
			cnt=0;
			//delay_ms(984);
			}
			if(cnt==2)
			{			
						if(sw1==0)
						{
						while(!sw1);
						cnt++;
						if(cnt>4)
						cnt=0;
						//delay_ms(984);
						}
						if(sw2==0)
						{
						while(!sw2);
						++hrs;
						if(hrs>23)
						hrs=0;
						time();
						//delay_ms(1000);
						}
					
						if(sw3==0)
						{
						
						while(!sw3);
						--hrs;
						if(hrs>23)
						hrs=0;
						time();
						//delay_ms(1000);
						}
				}
				if(cnt==3)
				{	
							if(sw1==0)
							{
							while(!sw1);
							cnt++;
							if(cnt>4)
							cnt=0;
							//delay_ms(984);
							}
							if( sw2==0)
							{
							
							while(!sw2);
							++mins;
							if(mins>59)
							mins=0;
							time();
							}
							
							if( sw3==0)
							{
							while(!sw3);
							--mins;
							if(mins>59)
							mins=0;
							time();
							}
					}
					if(cnt==4)
				{	
							if(sw1==0)
							{
							while(!sw1);
							cnt++;
							if(cnt>4)
							cnt=0;
							//delay_ms(984);
							}
							if( sw2==0)
							{
							while(!sw2);
							++secs;
							if(secs>59)
							secs=0;
							time();
							}
							if( sw3==0)
							{
							while(!sw3);
							--secs;
							if(secs>59)
							secs=0;
							time();
							}
					}
			if(sw4==0)
			{
				while(!sw4);                                                                                                   
				break;
				if(++secs>59)
				{
				//secs=secs-60;
				secs=0;
				
					if(++mins>59)
					{
					//mins=mins-60;
					mins=0;
					
						if(++hrs>23)
						{
						//hrs=hrs-24;
						hrs=0;
						}
					}
				}
			}
		}

}


main()
{

init_lcd();
time();

	while(1)
	{

	time();
	delay_ms(980);
			if(++secs>59)
			{
			//secs=secs-60;
			secs=0;
			
				if(++mins>59)
				{
				//mins=mins-60;
				mins=0;
				
					if(++hrs>23)
					{
					//hrs=hrs-24;
					hrs=0;
					}
				}
			}
	
		if(sw1==0)
		{
		while(!sw1);
		cnt++;
		if(cnt>4)
			cnt=0;
		edit();
		//delay_ms(984);
		}
	
	}
}


