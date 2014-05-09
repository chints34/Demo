#include<reg51.h>
#include"delay.h"

code unsigned char seg_lut[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

#define segs_4_mux P0

sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;

unsigned char dp1=0x80,dp2=0x80;
unsigned char dp3=0x80,dp4=0x80;


void disp_4_mux_segs(unsigned int n)
{
if(n>=0 && n<10)
{
 segs_4_mux=seg_lut[n%10]|dp4;
 sel4=0;
 delay_ms(1);
 sel4=1;
}

else if(n>=10 && n<100)
{
 segs_4_mux=seg_lut[n/10]|dp3;
 sel3=0;
 delay_ms(1);
 sel3=1;

 segs_4_mux=seg_lut[n%10]|dp4;
 sel4=0;
 delay_ms(1);
 sel4=1;
}

else if(n>=100 && n<1000)
{
 segs_4_mux=seg_lut[n/100]|dp2;
 sel2=0;
 delay_ms(1);
 sel2=1;
 
 segs_4_mux=seg_lut[(n/10)%10]|dp3;
 sel3=0;
 delay_ms(1);
 sel3=1;

 segs_4_mux=seg_lut[n%10]|dp4;
 sel4=0;
 delay_ms(1);
 sel4=1;
}

else
{
 segs_4_mux=seg_lut[n/1000]|dp1;
 sel1=0;
 delay_ms(1);
 sel1=1;

 segs_4_mux=seg_lut[(n/100)%10]|dp2;
 sel2=0;
 delay_ms(1);
 sel2=1;
 
 segs_4_mux=seg_lut[(n%100)/10]|dp3;
 sel3=0;
 delay_ms(1);
 sel3=1;

 segs_4_mux=seg_lut[n%10]|dp4;
 sel4=0;
 delay_ms(1);
 sel4=1;
}
}
void dispf_4_mux_segs(float f)
{
 int t;
 if(f>=0.0 && f<10.0)
{
 t=f*1000;
 dp1=0;
}

else if(f>=10.0 && f<100.0)
{
 t=f*100;
 dp2=0;
}

else if(f>=100.0 && f<1000.0)
{
 t=f*10;
 dp3=0;
}
disp_4_mux_segs(t);

}
