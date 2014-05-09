#include<reg51.h>
void disp_mux_segs(unsigned int n);
unsigned char dp3=0x7f;
code unsigned char lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90};
#define segs_4_mux P0
sbit sel1=P2^0;
sbit sel2=P2^1;
sbit sel3=P2^2;
sbit sel4=P2^3;

void delay_ms(unsigned int dly)
{
unsigned char i;
for(;dly>0;dly--)
{
for(i=255;i>0;i--);
for(i=232;i>0;i--);
}
}

void disp_mux_segs(unsigned int n)
{
segs_4_mux=lut[n/10];
sel1=1;
delay_ms(2);
sel1=0;
segs_4_mux=lut[n%10]&dp3;
sel2=1;
delay_ms(2);
sel2=0;
//}

//void disp_mux_segs(unsigned int n)
//{
segs_4_mux=lut[n/10];
sel3=1;
delay_ms(2);
sel3=0;

segs_4_mux=lut[n%10];
sel4=1;
delay_ms(2);
sel4=0;
}

main()
{
unsigned char i=0,j=0;
while(1)
{
for(j=0;j<60;j++)
{
for(i=0;i<60;i++)
{
delay_ms(20);
disp_mux_segs(j);
delay_ms(20);
disp_mux_segs(i);
}
}
}
}
