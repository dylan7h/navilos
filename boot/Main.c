#include "stdint.h"
#include "HalUart.h"

static void HW_init(void);

int main(void)
{
    uint32_t i = 100;

    HW_init();

    while(i--)
    {
        Hal_uart_put_char('N');
    }

    return 0;
}

static void HW_init(void)
{
    Hal_uart_init();
}