sbit SCL=P3^0;
sbit SDA=P3^1;

/*
void i2c_start(void);
void i2c_write(unsigned  char dat);
void i2c_ack(void);

void i2c_stop(void);
char i2c_read(void);
void i2c_nock(void);
*/

void i2c_start(void)
{
	SDA=1;
	SCL=1;
	SDA=0;
}

void i2c_write(unsigned char dat)
{
	char i;
	for(i=0;i<8;i++)
	{
		SCL=0;
		SDA=(dat&(0x80>>i)?1:0);
		SCL=1;
	}
}


void i2c_ack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;
	SCL=0;
}


void i2c_stop(void)
{
	SCL=0;
	SDA=0;
	SDA=1;
	SCL=1;
}


unsigned char i2c_read()
{
	unsigned char i,buff=0;
	SDA=1;
	for(i=0;i<8;i++)
	{
		SCL=1;
		if(SDA)
		{
			buff|=((0x80)>>i);
		}
		SCL=0;
	}
	return buff;
}


void i2c_noack(void)
{
	SCL=0;
	SDA=1;
	SCL=1;
	SCL=0;
}

