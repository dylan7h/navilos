#include "stdint.h"
#include "HalUart.h"

#include "stdio.h"

static void HW_init(void);
static void Print_Test(void);

int main(void)
{
    uint8_t ch;
    uint32_t i = 100;

    HW_init();

    while(i--)
    {
        Hal_uart_put_char('N');
    }
    Hal_uart_put_char('\n');

    putstr("Hello World!\n");

    Print_Test();

    i = 100;
    while(i--)
    {
        ch = Hal_uart_get_char();
        Hal_uart_put_char(ch);
    }

    return 0;
}

static void HW_init(void)
{
    Hal_uart_init();
}

static void Print_Test(void)
{
    const char* str = "printf pointer test";
    char* nullptr = 0;
    uint32_t i = 5;

    debug_printf("%s\n", "Hello Printf");
    debug_printf("output string pointer: %s\n", str);
    debug_printf("%s is null pointer, %u\n", nullptr, 10);
    debug_printf("%u = 5\n", i);
    debug_printf("dec = %u, hex = %x\n", 0xff, 0xff);
    debug_printf("print zero %u\n", 0);
}
