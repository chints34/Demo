void delay_ms(unsigned int j)
{
	unsigned char i;
	for(;j>0;j--)
	{
		for(i=255;i>0;i--);
		for(i=232;i>0;i--);
	}
}

