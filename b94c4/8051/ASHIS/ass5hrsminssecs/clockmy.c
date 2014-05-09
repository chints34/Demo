#include<reg51.h>
#include"delay.h"
#include"lcd.h"
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2;
sbit sw4=P3^3;
unsigned char sec=33,min=49,hour=22,cnt=0;


void time()
{
cmd_lcd(0x80);
disp_lcd((hour/10)+48);
disp_lcd((hour%10)+48);
disp_lcd(':');

disp_lcd((min/10)+48);
disp_lcd((min%10)+48);
disp_lcd(':');

disp_lcd((sec/10)+48);
disp_lcd((sec%10)+48);
}

main()
{

init_lcd();
time();

while(1)
{
time();
delay_ms(982);
										
if(++sec>59)
{
sec=0;
if(++min>59)
{
	min=0;
	if(hour>23)
	{
	hour=0;
	}
}
}
if(sw1==0)
{
	 		if(sw1==0)
			{
			while(!sw1);
			cnt++;
			if(cnt>4)
				cnt=0;
			}
   
label:
   
     if(cnt==1)
       {
        
        while(sw2==0)
            {
              if(++hour>23)
				hour=0;
			 time();
			delay_ms(500);
           }
		while(sw3==0)
			{
 			 if(--hour<1)
				hour=23;
				time();
				delay_ms(500);
			}
        }
    if(cnt==2)
     {
        while(sw2==0)
            {
              if(++min>59)
				min=0;
			 time();
			delay_ms(200);
           }
		while(sw3==0)
			{
 			 if(--min<1)
				min=59;
				time();
				delay_ms(200);
			}  
     }
     if(cnt==3)
       {
				 while(sw2==0)
	            {
	              if(++sec>59)
					sec=0;
				 time();
				delay_ms(200);
	           }
			   while(sw3==0)
				{
	 			 if(--sec<1)
					sec=59;
					time();
					delay_ms(200);
				}
       }
     while(sw4==1)
         {
	      if((sw2==1)&&(sw3==1))
	        goto label;
	     }

  }

}
}