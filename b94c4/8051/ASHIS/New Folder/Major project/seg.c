#include<reg51.h>
#include"delay.h"

sfr p0=0x80;
sfr p2=0xa0;

code unsigned char seg_lut[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

#define seg_4_mux p0

sbit sel1=p2^0;

sbit sel2=p2^1;

sbit sel3=p2^2;

sbit sel4=p2^3;

unsigned char dp1=0x00,dp2=0x00,dp3=0x00,dp4=0x00;

void disp_4_mux_segs(unsigned int n)
{

		if(n>=0 && n<10)
		{           
			seg_4_mux=seg_lut[n%10]|dp4;
			sel4=0;
			delay_ms(1);
			sel4=1;
		 }
		 else if(n>=10 && n<100)
		{
        	
			seg_4_mux=seg_lut[n/10]|dp3;
			sel3=0;
			delay_ms(1);
			sel3=1;  
		
			seg_4_mux=seg_lut[n%10]|dp4;
			sel4=0;
			delay_ms(1);
			sel4=1;
		 }
		 else if(n>=100 && n<1000)
		{
        
            seg_4_mux=seg_lut[n/100]|dp2;
			sel2=0;
			delay_ms(1);
			sel2=1;
			
			seg_4_mux=seg_lut[(n/10)%10]|dp3;
			sel3=0;
			delay_ms(1);
			sel3=1;
		
      
			seg_4_mux=seg_lut[n%10]|dp4;
			sel4=0;
			delay_ms(1);
			sel4=1;
		 }
		 else
		{
        
		    seg_4_mux=seg_lut[n/1000]|dp1;
			sel1=0;
			delay_ms(1);
			sel1=1;

            seg_4_mux=seg_lut[(n/100)%10]|dp2;
			sel2=0;
			delay_ms(1);
			sel2=1;
			
			seg_4_mux=seg_lut[(n%100)/10]|dp3;
			sel3=0;
			delay_ms(1);
			sel3=1;
		
      
			seg_4_mux=seg_lut[n%10] | dp4;
			sel4=0;
			delay_ms(1);
			sel4=1;
		 }

}