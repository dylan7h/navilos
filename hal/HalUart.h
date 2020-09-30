#ifndef __HALUART__H__
#define __HALUART__H__

void Hal_uart_init(void);
void Hal_uart_put_char(uint8_t ch);
uint8_t Hal_uart_get_char(void);

#endif  //!__HALUART__H__