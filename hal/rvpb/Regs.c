#include "type.h"
#include "stdint.h"
#include "Uart.h"
#include "Interrupt.h"

__IO PL011_t* Uart = (__IO PL011_t*)UART_BASE_ADDRESS0;
__IO GicCput_t* GicCpu = (__IO GicCput_t*)GIC_CPU_BASE;
__IO GicDist_t* GicDist = (__IO GicDist_t*)GIC_DIST_BASE;
