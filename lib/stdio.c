#include "type.h"
#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

#define PRINTF_BUF_LEN  1024

static char sPrintf_buf[PRINTF_BUF_LEN];   // 1KB

uint32_t putstr(const char* s)
{
    uint32_t c = 0;

    while((*s) != '\0')
    {
        Hal_uart_put_char(*s);
        s++;
        c++;
    }

    return c;
}

uint32_t debug_printf(const char* format, ...)
{
    va_list args;

    va_start(args, format);
    vsprintf(sPrintf_buf, format, args);
    va_end(args);

    return putstr(sPrintf_buf);
}

uint32_t vsprintf(char* buf, const char* format, va_list arg)
{
    uint32_t c = 0;
    uint32_t i;

    char        ch;
    char*       str;
    uint32_t    uint;
    uint32_t    hex;

    for(i = 0; format[i] != '\0'; i++)
    {
        if(format[i] == '%')
        {
            switch (format[++i])
            {
            case 'c':
                ch = (char)va_arg(arg, int32_t);
                buf[c++] = ch;
                break;
            case 's':
                str = (char*)va_arg(arg, char*);
                if(str == NULL) {
                    str = "(null)";
                }

                while(*str) {
                    buf[c++] = (*str);
                    str++;
                }
                break;
            case 'u':
                uint = (uint32_t)va_arg(arg, uint32_t);
                c += utoa(&buf[c], uint, utoa_dec);
                break;
            case 'x':
                hex = (uint32_t)va_arg(arg, uint32_t);
                c += utoa(&buf[c], hex, utoa_hex);
                break;
            default:
                break;
            }
        }
        else {
            buf[c++] = format[i];
        }
    }

    if(c >= PRINTF_BUF_LEN) {
        buf[0] = '\0';
        return 0;
    }

    buf[c] = '\0';

    return c;
}

uint32_t utoa(char* buf, uint32_t val, utoa_t base)
{
    uint32_t c = 0;
    uint32_t t;
    int32_t idx = 0;
    char tmp[11];

    do {
        t = val % (uint32_t)base;

        if(t >= 10) {
            t += 'A' - '0' - 10;
        }

        tmp[idx] = (t + '0');
        val /= base;
        idx++;
    } while(val);

    /* reverse */
    idx--;
    while(idx >= 0) {
        buf[c++] = tmp[idx];
        idx--;
    }

    return c;
}
