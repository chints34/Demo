#include <reg52.h>
#define LCD P0

sbit DCLK = P1^0;
sbit SDAT= P1^1;
sbit CS =P1^2;






void init_lcd(void);
void cmd_lcd(unsigned char);
void write_lcd(unsigned char);
void display_lcd(unsigned char *);
void integer_lcd(int);
void float_lcd(float);
void delay_ms(unsigned int);

void adc_convert (void);
unsigned char byte_read(void);

unsigned char byte0,byte1;
unsigned int num;
float val;

void main (void)
{

  init_lcd();
  delay_ms(100);
  display_lcd("SPI Protocol");
  cmd_lcd(0xc0);
  display_lcd("Using MCP3201");
  delay_ms(1500);
  cmd_lcd(0x01);
  display_lcd("ADC Conversion");
  
  while(1)
  {
  cmd_lcd(0xc0);
  adc_convert();  
  
  	
  delay_ms(100);
  }
}
void adc_convert (void)  
{  
    DCLK=1;
    CS=1;                  //low to high to start conversion
    CS=0;
    byte1=byte_read();	 //msb result from adc
	byte0=byte_read();	//lsb result from adc
 
    CS=1; 
    num=(byte1&0x1f);	//
    num=((num<<8)|byte0)>>1;
    val=((num*5.00)/4096)*100;

    integer_lcd(val);
	display_lcd(" Degrees");

}
  
unsigned char byte_read (void)  
{
 unsigned char i,c=0,mask=0x80;
  for (i=0;i<8;i++)
   {
    DCLK=0;
     if (SDAT==1)
      c|=mask;
    DCLK=1;
    mask>>=1;                                          
   }
  return c;
}


 
void init_lcd(void)
{                            
delay_ms(10);
cmd_lcd(0x28);
cmd_lcd(0x0e);
cmd_lcd(0x06);
cmd_lcd(0x01);
}

void cmd_lcd(unsigned char c)
{          
unsigned char temp;
temp=c>>4;
LCD=temp<<4|0x08;
LCD=0;
LCD=c<<4|0x08;
LCD=0;
delay_ms(2);
}

void write_lcd(unsigned char c)
{
unsigned char temp;
temp=c>>4;
LCD=temp<<4|0x0a;
LCD=0;
LCD=c<<4|0x0a;
LCD=0;
delay_ms(2);
}

void display_lcd(unsigned char *s)
{
while(*s)
write_lcd(*s++);
}

void integer_lcd(int n)
{
unsigned char c[6];
unsigned int i=0;
  if(n<0)
  {
    write_lcd('-');
    n=-n;
  }
  if(n==0)
    write_lcd('0');
  while(n>0)
  {
    c[i++]=(n%10)+48;
    n/=10;
  }
  while(i-->=1)
    write_lcd(c[i]);
}

void float_lcd(float f)
{
int n;
float temp;
n=f;
integer_lcd(n);
write_lcd('.');
temp=f-n;
if(temp>=0.00&&temp<=0.09)
write_lcd('0');
f=temp*100;
n=f;
integer_lcd(n);
}

void delay_ms(unsigned int i)
{
unsigned int j;
	while(i-->0)
	{
		for(j=0;j<500;j++)
		{
			;
		}
	}
} 
