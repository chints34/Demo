#ifndef lcdtest_h
#define lcdtest_h

extern void write_lcd(unsigned char dat);
extern void cmd_lcd(unsigned char cmd);
extern void disp_lcd(unsigned char c);
extern void init_lcd(void);
extern void str_lcd(unsigned char *s);
extern void uint_lcd(unsigned int n);
extern void hex_lcd(unsigned int n);
extern void float_lcd(float f);
extern void build_cgram(char *s,unsigned int n);
extern void lcd_test(void);

#endif