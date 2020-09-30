#include "type.h"
#include "stdint.h"
#include "Uart.h"

__IO PL011_t* Uart = (__IO PL011_t*)UART_BASE_ADDRESS0;
