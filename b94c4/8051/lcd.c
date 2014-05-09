#include<reg51.h>
#include"delay.h"
#define lcd_dat P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
void write_lcd(unsigned char dat)
{
lcd_dat=dat;
rw=0;//wrte operaton
en=1;
en=0;
delay_1ms(2);//sync delay

}
void cmd_lcd(unsigned char c)
{

rs=0;//set cmd reg
write_lcd(c);//write nto ddram via data reg.
}
void disp_lcd(unsigned char c)
{
rs=1;
write_lcd(c);

}
void init_lcd(void)
{
//clr ddram/dsplay/screen
cmd_lcd(0x01);
//return cursor to the home position
cmd_lcd(0x02);
//set cursor move diirection to right
cmd_lcd(0x06);
//enable display,cursor off
cmd_lcd(0x0c);
//set interfece length to 8 bit

cmd_lcd(0x38);
//bgn the dsplay/set cursor to ddram AT LINE1 POS 0
cmd_lcd(0x80);
}



/*void build_cgram(char *s,unsigned int n)
{
unsigned char i;
cmd_lcd(0x40);
for(i=0;i<n;i++)
{
disp_lcd(s[i]);

}
cmd_lcd(0x80);
}

void build_cgram1(char *s,unsigned int n)
{
unsigned char j;
cmd_lcd(0x48);
for(j=0;j<n;j++)
{
disp_lcd(s[j]);

}
cmd_lcd(0x80);
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

   for(--i;i>=0;i--)
   disp_lcd(a[i]);
 }
}

void float_lcd(float f)
{
  unsigned int i;
  unsigned char j;
  i=f;
  uint_lcd(i);
  disp_lcd('.'); 
 for(j=0;j<i;j++)
  {
   f=(f-1)*10;
   i=f;
   uint_lcd(i);

  }

}

void hex_lcd(unsigned int n)
{
 char a[4]={0},i,t;
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


         for(--i;i>=0;i--)
             disp_lcd(a[i]);


    }

  }

 }

*/
