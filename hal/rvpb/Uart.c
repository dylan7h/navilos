#include "type.h"
#include "stdint.h"
#include "Uart.h"
#include "HalUart.h"

extern __IO PL011_t* Uart;

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

uint8_t Hal_uart_get_char(void)
{
    uint32_t data;

    /* Check Receive FIFO Empty */
    while(Uart->FR.bit.RXFE != OFF);

    data = Uart->DR.reg;

    /* Check Error Flag */
    if((data & __UARTDR__(1, 1, 1, 1)) != 0)
    {
        /* Clear Error Flag */
        Uart->DR.reg = __UARTDR__(1, 1, 1, 1);
        return 0;
    }

    return (uint8_t)(0xFF & data);
}
