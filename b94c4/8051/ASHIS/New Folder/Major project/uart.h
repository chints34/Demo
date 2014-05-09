#ifndef uart_h
#define uart_h

extern void uart_init(void);
extern void uart_tx(unsigned char dat);
extern unsigned char uart_rx(void);
extern void print(unsigned char *s);

#endif
