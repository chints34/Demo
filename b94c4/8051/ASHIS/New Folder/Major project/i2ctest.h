#ifndef i2ctest_h
#define i2ctest_h

extern void i2c_start(void);
extern void i2c_write(unsigned char dat);
extern void i2c_ack(void);
extern void i2c_stop(void);
extern unsigned char i2c_read();
extern void i2c_noack(void);
extern void eeprom_write(unsigned char sa,unsigned char add,unsigned char dat);
extern unsigned  eeprom_read(unsigned char sa,unsigned char add);
extern void i2c_test();

#endif