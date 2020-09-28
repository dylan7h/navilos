#ifndef __UART__H__
#define __UART__H__

#include "type.h"
#include "stdint.h"

/* 0x000 - RW 0x --- 12/8 Data Register, UARTDR on page 3-5 */ 
typedef union {
    uint32_t reg;
    struct {
        uint32_t DATA       : 8;
        uint32_t FE         : 1;
        uint32_t PE         : 1;
        uint32_t BE         : 1;
        uint32_t OE         : 1;
        uint32_t RESERVED   : 20;
    } bit;
} UARTDR_t;

/* 0x004 - RW 0x0 4/0 Receive Status Register/Error Clear Register, UARTRSR/UARTECR on page 3-6 */
typedef union {
    uint32_t reg;
    struct {
        uint32_t FE         : 1;
        uint32_t PE         : 1;
        uint32_t BE         : 1;
        uint32_t OE         : 1;
        uint32_t reserved   : 28;
    } bit;
} UARTRSR_t;

/* 0x004 - RW 0x0 4/0 Receive Status Register/Error Clear Register, UARTRSR/UARTECR on page 3-6 */
typedef union {
    uint32_t reg;
    struct {
        uint32_t FE         : 1;
        uint32_t PE         : 1;
        uint32_t BE         : 1;
        uint32_t OE         : 1;
        uint32_t reserved   : 28;
    } bit;
} UARTECR_t;

/* 0x018 - RO 0b-10010 --- 9 Flag Register, UARTFR on page 3-8*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t CTS        : 1;
        uint32_t DSR        : 1;
        uint32_t DCD        : 1;
        uint32_t BUSY       : 1;
        uint32_t RXFE       : 1;
        uint32_t TXFF       : 1;
        uint32_t RXFF       : 1;
        uint32_t TXFE       : 1;
        uint32_t RI         : 1;
        uint32_t reserved   : 23;   
    } bit;
} UARTFR_t;

/* 0x020 - RW 0x00 8 IrDA Low-Power Counter Register, UARTILPR on page 3-9*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t ILPDVSR    : 8;
        uint32_t reserved   : 24;
    } bit;
} UARTILPR_t;

/* 0x024 - RW 0x0000 16 Integer Baud Rate Register, UARTIBRD on page 3-9*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t BAUDDIVINT : 16;
        uint32_t reserved   : 16;
    } bit;
} UARTIBRD_t;

/* 0x028 - RW 0x00 6 Fractional Baud Rate Register, UARTFBRD on page 3-10*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t BAUDDIVFRAC: 6;
        uint32_t reserved   : 26;
    } bit;
} UARTFBRD_t;

/* 0x02C - RW 0x00 8 Line Control Register, UARTLCR_H on page 3-12*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t BRK        : 1;
        uint32_t PEN        : 1;
        uint32_t EPS        : 1;
        uint32_t STP2       : 1;
        uint32_t FEN        : 1;
        uint32_t WLEN       : 2;
        uint32_t SPS        : 1;
        uint32_t reserved   : 24;
    } bit;
} UARTLCR_H_t;

/* 0x030 - RW 0x0300 16 Control Register, UARTCR on page 3-15*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t UARTEN     : 1;
        uint32_t SIREN      : 1;
        uint32_t SIRLP      : 1;
        uint32_t Reserved1  : 4;
        uint32_t LBE        : 1;
        uint32_t TXE        : 1;
        uint32_t RXE        : 1;
        uint32_t DTR        : 1;
        uint32_t RTS        : 1;
        uint32_t Out1       : 1;
        uint32_t Out2       : 1;
        uint32_t RTSEn      : 1;
        uint32_t CTSEn      : 1;
        uint32_t reserved2  : 16;
    } bit;
} UARTCR_t;

/* 0x034 - RW 0x12 6 Interrupt FIFO Level Select Register, UARTIFLS on page 3-17*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t TXIFLSEL   : 3;
        uint32_t RXIFLSEL   : 3;
        uint32_t reserved   : 26;
    } bit;
} UARTIFLS_t;

/* 0x038 - RW 0x000 11 Interrupt Mask Set/Clear Register, UARTIMSC on page 3-17*/
typedef union {
    uint32_t reg;
    struct {
        uint32_t RIMIM      : 1;
        uint32_t CTSMIM     : 1;
        uint32_t DCDMIM     : 1;
        uint32_t DSRMIM     : 1;
        uint32_t RXIM       : 1;
        uint32_t TXIM       : 1;
        uint32_t RTIM       : 1;
        uint32_t FEIM       : 1;
        uint32_t PEIM       : 1;
        uint32_t BEIM       : 1;
        uint32_t OEIM       : 1;
        uint32_t reserved   : 21;
    } bit;
} UARTIMSC_t;

/* 0x03C - RO 0x00 - 11 Raw Interrupt Status Register, UARTRIS on page 3-19 */
typedef union {
    uint32_t reg;
    struct {
        uint32_t RIRMIS     : 1;
        uint32_t CTSRMIS    : 1;
        uint32_t DCDRMIS    : 1;
        uint32_t DSRRMIS    : 1;
        uint32_t RXRIS      : 1;
        uint32_t TXRIS      : 1;
        uint32_t RTRIS      : 1;
        uint32_t FERIS      : 1;
        uint32_t PERIS      : 1;
        uint32_t BERIS      : 1;
        uint32_t OERIS      : 1;
        uint32_t reserved   : 21;
    } bit;
} UARTRIS_t;

/* 0x040 - RO 0x00 - 11 Masked Interrupt Status Register, UARTMIS on page 3-20 */
typedef union {
    uint32_t reg;
    struct {
        uint32_t RIMMIS     : 1;
        uint32_t CTSMMIS    : 1;
        uint32_t DCDMMIS    : 1;
        uint32_t DSRMMIS    : 1;
        uint32_t RXMIS      : 1;
        uint32_t TXMIS      : 1;
        uint32_t RTMIS      : 1;
        uint32_t FEMIS      : 1;
        uint32_t PEMIS      : 1;
        uint32_t BEMIS      : 1;
        uint32_t OEMIS      : 1;
        uint32_t reserved   : 21;
    } bit;
} UARTMIS_t;

/* 0x044 - WO - 11 Interrupt Clear Register, UARTICR on page 3-21 */ 
typedef union {
    uint32_t reg;
    struct {
        uint32_t RIMIC      : 1;
        uint32_t CTSMIC     : 1;
        uint32_t DCDMIC     : 1;
        uint32_t DSRMIC     : 1;
        uint32_t RXIC       : 1;
        uint32_t TXIC       : 1;
        uint32_t RTIC       : 1;
        uint32_t FEIC       : 1;
        uint32_t PEIC       : 1;
        uint32_t BEIC       : 1;
        uint32_t OEIC       : 1;
        uint32_t reserved   : 21;
    } bit;
} UARTICR_t;

/* 0x048 - RW 0x00 3 DMA Control Register, UARTDMACR on page 3-22 */ 
typedef union {
    uint32_t reg;
    struct {
        uint32_t RXDMAE     : 1;
        uint32_t TXDMAE     : 1;
        uint32_t DMAONERR   : 1;
        uint32_t reserved   : 29;
    } bit;
} UARTDMACR_t;

typedef struct
{
    __IOM UARTDR_t DR;
    union {
        __IM UARTRSR_t SR;
        __OM UARTECR_t ECR;
    };
    /* 0x008 - 0x014 */
    __IOM uint32_t Reserved0[4];
    __IOM UARTFR_t FR;
    /* 0x01C */
    __IOM uint32_t Reserved1;
    __IOM UARTILPR_t ILPR;
    __IOM UARTIBRD_t IBRD;
    __IOM UARTFBRD_t FBRD;
    __IOM UARTLCR_H_t LCR_H;
    __IOM UARTCR_t CR;
    __IOM UARTIFLS_t IFLS;
    __IOM UARTIMSC_t IMSC;
    __IM  UARTRIS_t RIS;
    __IM  UARTMIS_t MIS;
    __IM  UARTICR_t ICR;
    __IOM UARTDMACR_t DMACR;
} PL011_t;

#define UART_BASE_ADDRESS0  0x10009000
#define UART_INTERRUPT0     44

#endif  //!__UART__H__