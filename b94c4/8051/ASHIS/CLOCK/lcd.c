#include<reg51.h>
#include"delay.h"
#define lcd_dat P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
void write_lcd(unsigned char dat)
{
lcd_dat=dat;

rw=0;
en=1;
delay_ms(2);
en=0;
}
void cmd_lcd(unsigned char cmd)
{
rs=0;
write_lcd(cmd);
}
void disp_lcd(unsigned char c)
{
rs=1;
write_lcd(c);
}
void init_lcd(void)
{
cmd_lcd(0x01);
cmd_lcd(0x02);
cmd_lcd(0x06);
cmd_lcd(0X0C);
cmd_lcd(0X38);
cmd_lcd(0x80);
}

/*void unit_lcd(unsigned int n)
{
char a[5]={0};
int i=0;
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

void str_lcd(unsigned char *s)
{
while(*s)
disp_lcd(*s++);
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

}*/
