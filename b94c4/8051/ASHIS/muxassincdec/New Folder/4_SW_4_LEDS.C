#include<intrins.h>
sfr p2=0xa0;
sbit sw1=p2^0;	sbit led1=p2^4;
sbit sw2=p2^1;	sbit led2=p2^5;
sbit sw3=p2^2;	sbit led3=p2^6;
sbit sw4=p2^3;	sbit led4=p2^7;

main()
{
	while(1)
	{
		#pragma asm
		mov a,p2
		swap a
		orl a,#0fh
		mov p2,a
		#pragma endasm

		/*t=p2;
		//t<<=4;
		t=_crol_(t,4);
		p2=t | 0x0f;*/
	}
}
