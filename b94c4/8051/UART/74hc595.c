
sbit ds=P3^0; //connection to serial ip pin of 74hc595
sbit sh_clk=P3^1;//connection to sh_clk ip
//sbit st_clk=P3^2;



void write_74hc595(unsigned char dat)

{
 unsigned char i;
for(i=0;i<=7;i++)
{

 sh_clk=0;
ds=(dat&(0x080>>i))?1:0;
sh_clk=1;

}
//clk for moving from shift to storage register
sh_clk=0;
sh_clk=1;
}
