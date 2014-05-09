#include<reg51.h>
#include"delay.h"
#include"uart.h"
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
/*
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



*/
//lcd_test function
void lcd_test()
{
unsigned char t,i,x;
init_lcd();
repeat:  print("YOU ARE IN LCD TESTING MODULE\n\r");
    
	//[ACTIVE HIGH LEDs AT P0.0 TO P0.3 | ACTIVE LOW LEDs AT P0.4 TO P0.7]
	print("connect port P0 to data pins of lcd and tconnect port P2.0 to rs ,P2.1 to rw,P2.2 to en\n\r");
    
	//TESTING
	print("TESTING..\n\r");
print("Enter any key to test...\n\r");
uart_rx();
  
for(i=0;i<26;i++)
{
t='A'+i;
//uart_tx(t);
cmd_lcd(0x80);
disp_lcd(t);


cmd_lcd(0xc0);
disp_lcd(t);
delay_ms(1000);

}

  print("check A to Z charecters are displaying or not?\nenter(Y)for Yes(N)for No\n\r");
    x=uart_rx();
    if(x=='Y'||x=='y')
    {
     print("Yes,Lcd is working fine\n\r");
     return;
    }
	else
	{
	goto repeat;
	}



}//end of lcd_test fn

