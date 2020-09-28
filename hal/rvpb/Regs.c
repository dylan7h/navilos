#include "type.h"
#include "stdint.h"
#include "Uart.h"
#include "HalUart.h"

__IO PL011_t* Uart = (__IO PL011_t*)UART_BASE_ADDRESS0;

void Hal_uart_init(void)
{
    /* Enable Uart */
    Uart->CR.bit.UARTEN = DISABLE;
    Uart->CR.bit.TXE = ON;
    Uart->CR.bit.RXE = ON;
    Uart->CR.bit.UARTEN = ENABLE;
}

void Hal_uart_put_char(uint8_t ch)
{
    /* Check Transmit FIFO full */
    while(Uart->FR.bit.TXFF != OFF);

    /* Data Transmit */
    Uart->DR.reg = (0xFF & ch);
}
