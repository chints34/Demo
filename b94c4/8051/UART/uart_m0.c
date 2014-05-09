sbit clk=P3^1;
void init_uart()
{

//default but ensure
 scon=0x00;
}
void uart_tx(char c)
{

sbuf=c;
while(!T1);//waiting for 8 clks
T1=0;

clk=0;//extra clock for shift to
clk=1;//storage register

}
