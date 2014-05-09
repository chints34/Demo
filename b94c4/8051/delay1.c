void delay_1ms(unsigned int dly)
{
unsigned char i;
for(;dly>0;dly--)
{
for(i=255;i>0;i--);
for(i=232;i>0;i--);
}
}
