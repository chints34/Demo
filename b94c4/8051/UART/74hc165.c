sbit q7=P3^0;//serial in pin
sbit clk=P3^1;
sbit Pl=P3^2;

unsigned char read_74hc165(void)
{
 char i;
unsigned char t=0;
pl=0;//asunchro. load of parallel to internal reg.
pl=1;
for(i=7;i>=0;i--)
{
 clk=0;
if(q7)//read data msb first
t!=1<<i;//update status to appropriate bit position in var
clk=1;

}
return t;


}
