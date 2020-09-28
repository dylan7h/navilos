#include "ARMv7AR.h"
#include "MemoryMap.h"

.text
    .code 32                

    .global vector_start    @ EXPORT vector_start
    .global vector_end      @ EXPORT vector_end

    vector_start:
        LDR PC, reset_handler_addr
        LDR PC, undef_handler_addr
        LDR PC, svc_handler_addr
        LDR PC, pftch_abt_handler_addr
        LDR PC, data_abt_handler_addr
        B   .
        LDR PC, irq_handler_addr
        LDR PC, fiq_handler_addr

        reset_handler_addr:     .word reset_handler
        undef_handler_addr:     .word dummy_handler
        svc_handler_addr:       .word dummy_handler
        pftch_abt_handler_addr: .word dummy_handler
        data_abt_handler_addr:  .word dummy_handler
        irq_handler_addr:       .word dummy_handler
        fiq_handler_addr:       .word dummy_handler
    vector_end:

    reset_handler:
        @ Set SVC Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_SVC   @ r1    = (r1 | ARM_MODE_BIT_SVC)  ==> Set Mode bit to SCV Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =SVC_STACK_TOP          @ sp    = SVC_STACK_TOP

        @ Set IRQ Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_IRQ   @ r1    = (r1 | ARM_MODE_BIT_IRQ)  ==> Set Mode bit to IRQ Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =IRQ_STACK_TOP          @ sp    = IRQ_STACK_TOP

        @ Set FIQ Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_FIQ   @ r1    = (r1 | ARM_MODE_BIT_FIQ)  ==> Set Mode bit to FIQ Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =FIQ_STACK_TOP          @ sp    = FIQ_STACK_TOP

        @ Set ABT Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_ABT   @ r1    = (r1 | ARM_MODE_BIT_ABT)  ==> Set Mode bit to ABT Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =ABT_STACK_TOP          @ sp    = ABT_STACK_TOP

        @ Set UND Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_UND   @ r1    = (r1 | ARM_MODE_BIT_UND)  ==> Set Mode bit to UND Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =UND_STACK_TOP          @ sp    = UND_STACK_TOP

        @ Set SYS Stack Pointer
        MRS r0, cpsr                    @ r0    = cpsr
        BIC r1, r0, #0x1F               @ r1    = (r0 & ~0x1F)             ==> Clear Mode bit
        ORR r1, r1, #ARM_MODE_BIT_SYS   @ r1    = (r1 | ARM_MODE_BIT_SYS)  ==> Set Mode bit to SYS Mode
        MSR cpsr, r1                    @ cpsr  = r1
        LDR sp, =USRSYS_STACK_TOP       @ sp    = USRSYS_STACK_TOP

        BL main

    dummy_handler:
        B .

.end
