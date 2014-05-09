#include<LPC21xx.h>
#define led 1<<31
void delay(unsigned int dly)
{
	 int k;
	
for(;dly>0;dly--)
   for(k=1000;k>0;k--);	

	
}
int main()
{
PINSEL0=0X00000000;
IODIR0=led;
while(1)
{
IOCLR0=led;
	delay(2000);
	IOSET0=led;
	delay(2000);
}	
}
