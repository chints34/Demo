#include<reg51.h>
#include"delay.h"
#define lcd_dat P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void write_lcd(unsigned char dat)
{
	lcd_dat=dat;
	rw=0;	//write operation
	en=1;	//latch data into buffer
	
	delay_ms(2);	//sync delay
en=0;	//reset latch for next operation
}

void cmd_lcd(unsigned char cmd)
{
	rs=0;	//select cmd reg
	write_lcd(cmd); //write info into cmd reg
}

void disp_lcd(unsigned char c)
{
	rs=1;	//sel data reg
	write_lcd(c);	//write info into DDRAM via data reg
}

void init_lcd(void)
{
	cmd_lcd(0x01);	//clr DDRAM/display/screen
	cmd_lcd(0x02);	//return cursor to home pos
	cmd_lcd(0x06);	//set cursor move direction to right
	cmd_lcd(0x0c);	//enable disply,cursor off
	cmd_lcd(0x38);	//set interface length 5x7 char font
	cmd_lcd(0x80);	//begin display to DDRAM at line 1 pos 0
}

void str_lcd(unsigned char *s)
{
	while(*s)
		disp_lcd(*s++);
}

void uint_lcd(unsigned int n)
{
	char a[5]={0},i=0;
	if(n==0)
		disp_lcd('0');
	else
	{
		while(n>0)
		{
			a[i++]=(n%10)+48;
			n=n/10;
		}
	}
	for(--i;i>=0;i--)
		disp_lcd(a[i]);
}

void float_lcd(float f)
{
	unsigned int i;
	unsigned char j;
	i=f;
	uint_lcd(i);
	disp_lcd('.');
	for(j=0;j<6;j++)
	{
		f=(f-i)*10;
		i=f;
		uint_lcd(i);
	}
}

void hex_lcd(unsigned int n)
{
	char a[4],i=0,t;
	if(n==0)
		disp_lcd('0');
	else
	{
		while(n>0)
		{
			t=n%16;
			n=n/16;
			if(t<10)
				a[i++]=t+48;
			else
				a[i++]=(t-10)+'A';			
		}
	for(--i;i>=0;i--)
		disp_lcd(a[i]);
	}
}

void build_cgram(char *s,unsigned char n)
{
unsigned char i;
//cmd_lcd(0x01);
cmd_lcd(0x40);
for(i=0;i<n;i++)
{
disp_lcd(s[i]);
}
cmd_lcd(0x80);
}
