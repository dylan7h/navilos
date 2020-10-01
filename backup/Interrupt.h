#ifndef __HAL_RVPB_INTERRUPT__H__
#define __HAL_RVPB_INTERRUPT__H__

/* GIC PL390 */

/* ================================================== 
 * Distributor register map 
 * ==================================================
 **/
typedef union {
    uint32_t reg;
    struct {
        uint32_t enable     : 1;
        uint32_t reserved   : 31;
    } bit;
} ICDDCR_t;            // 0x000            : Distributor Control Register 

typedef union {
    uint32_t reg;
    struct {
        uint32_t IT_Lines_Number    : 5;    // Returns the number of INTIDs, to the nearest 32, that the Distributor provides:
                                            // b00000 = the Distributor provides 1 - 32 INTIDsa
                                            // b00001 = the Distributor provides 33 - 64 INTIDs
                                            // b00010 = the Distributor provides 65 - 96 INTIDs
                                            // b00011 = the Distributor provides 97 - 128 INTIDs
                                            // ...
                                            // b11110 = the Distributor provides 961 - 992 INTIDs
                                            // b11111 = the Distributor provides 993 - 1020 INTIDs.
                                            // Note 
                                            // Software can use the Enable Set Registers (ICDISERn) on page 3-9 to discover exactly how many INTIDs the GIC contains.

        uint32_t CPU_Number         : 3;    // Returns the number of CPU Interfaces that the GIC provides. 
                                            // The GIC provides either:
                                            // b000 = one CPU Interface
                                            // b001 = two CPU Interfaces
                                            // b010 = three CPU Interfaces                                            
                                            // b011 = four CPU Interfaces                                            
                                            // b100 = five CPU Interfaces                                            
                                            // b101 = six CPU Interfaces                                            
                                            // b110 = seven CPU Interfaces                                            
                                            // b111 = eight CPU Interfaces                                            
        uint32_t reserved           : 2;

        uint32_t TZ                 : 1;    // Returns the number of security states that the GIC supports.
                                            // 0 = the GIC supports the Secure state
                                            // 1 = the GIC supports a Secure state and a Non-secure state.

        uint32_t LSPI               : 5;    // Returns the number of Lockable Shared Peripheral Interrupts (LSPIs) that the GIC contains:
                                            // b00000 = no LSPIs
                                            // b00001 = 1 LSPI. INTID 32
                                            // b00010 = 2 LSPIs, INTID 32 - INTID 33
                                            // b00011 = 3 LSPIs, INTID 32 - INTID 34
                                            // ...
                                            // b11110 = 30 LSPIs, INTID 32 - INTID 61
                                            // b11111 = 31 LSPIs, INTID 32 - INTID 62.
                                            // When cfgsdisable is HIGH then the GIC prevents writes to any register locations that control the operating state of an LSPI that is programmed to be secure. 
                                            // See the ARM Generic Interrupt Controller Architecture Specification for more information about cfgsdisable.                                           
        uint32_t reserved2          : 16;
    } bit;
} ICDICTR_t;           // 0x004            : Interrupt Controller Type Register

typedef union {
    uint32_t implementer            : 12;   // Returns the JEP106 code of the company that implemented the Distributor RTL, that is, ARM. 
                                            // It uses the following bit format:
                                            // •[11:8] = 0x4, that is, the JEP106 continuation code for ARM
                                            // •[7] = 0
                                            // •[6:0] = b0111011, that is, the JEP106 code [6:0] for ARM.
                                            // See the JEDEC Standard Manufacturer’s Identification Code for information about JEP106.

    uint32_t rev_num                : 12;   // Returns the revision number of the GIC. For revision r0p0, this field returns 0x000

    uint32_t impl_ver               : 8;    // Returns the product identifier. For a GIC (PL390) this field returns 0x00.
} ICDIIDR_t;           // 0x008            : Distributor Implementer Identification Register

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_security_if<n>d  0x080       
        uint32_t PPI                : 16;   // ppi_security_if<n>d  0x082
    } if_n;
    uint32_t SPI[31];                       // spi_security         0x084 - 0x0FC
} ICDISR_t;            // 0x080 - 0x0FC    : Interrupt Security Registers

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_enable_if<n>d  0x100       
        uint32_t PPI                : 16;   // ppi_enable_if<n>d  0x102
    } if_n;
    uint32_t SPI[31];                       // spi_enable         0x104 - 0x17C
} ICDISER_t;           // 0x100 - 0x17C    : Enable Set Register

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_clear_if<n>d  0x180       
        uint32_t PPI                : 16;   // ppi_clear_if<n>d  0x182
    } if_n;
    uint32_t SPI[31];                       // spi_clear         0x184 - 0x1FC
} ICDICER_t;           // 0x180 - 0x1FC    : Enable Clear Register

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_set_pending_if<n>d  0x200       
        uint32_t PPI                : 16;   // ppi_set_pending_if<n>d  0x202
    } if_n;
    uint32_t SPI[31];                       // spi_set_pending         0x204 - 0x27C
} ICDISPR_t;           // 0x200 - 0x27C    : Pending Set Register

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_clear_pending_if<n>d  0x280       
        uint32_t PPI                : 16;   // ppi_clear_pending_if<n>d  0x282
    } if_n;
    uint32_t SPI[31];                       // spi_clear_pending         0x284 - 0x2FC
} ICDICPR_t;           // 0x280 - 0x2FC    : Pending Clear Register

typedef struct {
    struct {
        uint32_t SGI                : 16;   // sgi_active_if<n>d  0x300       
        uint32_t PPI                : 16;   // ppi_active_if<n>d  0x302
    } if_n;
    uint32_t SPI[31];                       // spi_active_pending 0x304 - 0x37C
} ICDABR_t;            // 0x300 - 0x37C    : Active Status Register

typedef union {

} ICDIPR_t;            // 0x400 - 0x7FB    : Priority Level Register

typedef union {

} ICDIPTR_t;           // 0x800 - 0xBFB    : Target Register

typedef union {

} ICDICR_t;            // 0xC00 - 0xCFC    : Interrupt Configuration Register

typedef union {

} PPI_t;               // 0xD00

typedef union {

} SPI_t;               // 0xD04 - 0xD7C    : SPI

typedef union {

} TEST_t;              // 0xDD4 - 0xDE4

typedef union {

} ICDSGIR_t;           // 0xF00            : Software Generated Interrupt Register


typedef struct {
    uint32_t ICDDCR;            // 0x000            : Distributor Control Register 
    uint32_t ICDICTR;           // 0x004            : Interrupt Controller Type Register
    uint32_t ICDIIDR;           // 0x008            : Distributor Implementer Identification Register
    uint32_t reserved0[29];     // 0x00C - 0x07C
    uint32_t ICDISR[32];        // 0x080 - 0x0FC    : Interrupt Security Registers
    uint32_t ICDISER[32];       // 0x100 - 0x17C    : Enable Set Register
    uint32_t ICDICER[32];       // 0x180 - 0x1FC    : Enable Clear Register
    uint32_t ICDISPR[32];       // 0x200 - 0x27C    : Pending Set Register
    uint32_t ICDICPR[32];       // 0x280 - 0x2FC    : Pending Clear Register
    uint32_t ICDABR[32];        // 0x300 - 0x37C    : Active Status Register
    uint32_t reserved1[32];     // 0x380 - 0x400
    uint32_t ICDIPR[255];       // 0x400 - 0x7FB    : Priority Level Register
    uint32_t reserved2;         // 0x7FC
    uint32_t ICDIPTR[255];      // 0x800 - 0xBFB    : Target Register
    uint32_t reserved3;         // 0xBFC
    uint32_t ICDICR[64];        // 0xC00 - 0xCFC    : Interrupt Configuration Register
    uint32_t PPI;               // 0xD00
    uint32_t SPI;               // 0xD04 - 0xD7C    : SPI
    uint32_t reserved4;         // 0xD80 - 0xDD0
    uint32_t TEST[5];           // 0xDD4 - 0xDE4
    uint32_t reserved5[70];     // 0xDE8 - 0xEFC
    uint32_t ICDSGIR;           // 0xF00            : Software Generated Interrupt Register
} GIC_DIST_t;

/* ==================================================
 * CPU Interface register map 
 * ==================================================
 **/
typedef struct {
    uint32_t ICCICR;            // 0x000            : CPU Interface Control Register
    uint32_t ICCPMR;            // 0x004            : Priority Mask Register
    uint32_t ICCBPR;            // 0x008            : Binary Point Register
    uint32_t ICCIAR;            // 0x00C            : Interrupt Acknowledege Register
    uint32_t ICCEOIR;           // 0x010            : End of Interrupt Register
    uint32_t ICCRPR;            // 0x014            : Running Priority Register
    uint32_t ICCHPIR;           // 0x018            : Highest Pending Interrupt Register
    uint32_t ICCABPR;           // 0x01C            : Aliased Binary Point Register
    uint32_t reserved0[9];      // 0x020 - 0x03C
    uint32_t TEST0[2];          // 0x040 - 0x044
    uint32_t reserved1[2];      // 0x048 - 0x04C
    uint32_t TEST1[2];          // 0x050 - 0x054
    uint32_t reserved2[41];     // 0x058 - 0x0F8
    uint32_t ICCIDR;            // 0x0FC            : CPU Interface Implementer Identification Register
} GIC_CPU_t;


#endif  //!__HAL_RVPB_INTERRUPT__H__