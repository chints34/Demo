#include"delay.h"
#include"i2ctest.h"
void eeprom_write(unsigned char sa,unsigned char add,unsigned char dat)
{
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(add);
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();
	delay_ms(10);
}


unsigned  eeprom_read(unsigned char sa,unsigned char add)
{
	unsigned char buff;
	i2c_start();
	i2c_write(sa);
	i2c_ack();
	i2c_write(add);
	i2c_ack();
	i2c_start();
	i2c_write(sa|0x01);
	i2c_ack();
	buff=i2c_read();
	i2c_noack();
	i2c_stop();
	return(buff);
}