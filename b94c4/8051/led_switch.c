sfr p2=0xa0;
sbit sw1=p2^0;  
sbit sw2=p2^1;
sbit sw3=p2^2;
sbit sw4=p2^3;

sbit led1=p2^4;
sbit led2=p2^5;
sbit led3=p2^6;
sbit led4=p2^7;
main()
{
while(1)
{
led1=sw1;
led2=sw2;
led3=sw3;
led4=sw4;
}


}
