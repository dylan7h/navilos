#ifndef __MEMORYMAP__H__
#define __MEMORYMAP__H__

/* 
########################################################################
##                            Memory Map                              ##
########################################################################

│ 0x0000_0000 ┌-----------------------┐
│             │ TEXT Region           │ 0x0000_0000 - 0x000F_FFFF ( 1MB)
│ 0x0010_0000 ├-----------------------┤
│             │ USR/SYS Mode Stack    │ 0x0010_0000 - 0x002F_FFFF ( 2MB)
│ 0x0030_0000 ├-----------------------┤
│             │ SVC Mode Stack        │ 0x0030_0000 - 0x003F_FFFF ( 1MB)
│ 0x0040_0000 ├-----------------------┤
│             │ IRQ Mode Stack        │ 0x0040_0000 - 0x004F_FFFF ( 1MB)
│ 0x0050_0000 ├-----------------------┤
│             │ FIQ Mode Stack        │ 0x0050_0000 - 0x005F_FFFF ( 1MB)
│ 0x0060_0000 ├-----------------------┤
│             │ ABT Mode Stack        │ 0x0060_0000 - 0x006F_FFFF ( 1MB)
│ 0x0070_0000 ├-----------------------┤
│             │ UND Mode Stack        │ 0x0070_0000 - 0x007F_FFFF ( 1MB)
│ 0x0080_0000 ├-----------------------┤
│             │ TASK Mode Stack       │ 0x0080_0000 - 0x047F_FFFF (64MB) - MAX of Task 64EA
│ 0x0480_0000 ├-----------------------┤
│             │ Global Variable Stack │ 0x0480_0000 - 0x048F_FFFF ( 1MB)
│ 0x0490_0000 ├-----------------------┤
│             │ Heap Region           │ 0x0490_0000 - 0x07FF_FFFF (55MB)
│ 0x0800_0000 └-----------------------┘
∇

**/

#define INST_ADDR_START     0x00000000
#define USRSYS_STACK_START  0x00100000
#define SVC_STACK_START     0x00300000
#define IRQ_STACK_START     0x00400000
#define FIQ_STACK_START     0x00500000
#define ABT_STACK_START     0x00600000
#define UND_STACK_START     0x00700000
#define TASK_STACK_START    0x00800000
#define GLOBAL_ADDR_START   0x04800000
#define DALLOC_ADDR_START   0x04900000
#define END_OF_MEMORY_MAP   0x08000000

#define INST_ADDR_SIZE     (USRSYS_STACK_START  - INST_ADDR_START)
#define USRSYS_STACK_SIZE  (SVC_STACK_START     - USRSYS_STACK_START)
#define SVC_STACK_SIZE     (IRQ_STACK_START     - SVC_STACK_START)
#define IRQ_STACK_SIZE     (FIQ_STACK_START     - IRQ_STACK_START)
#define FIQ_STACK_SIZE     (ABT_STACK_START     - FIQ_STACK_START)
#define ABT_STACK_SIZE     (UND_STACK_START     - ABT_STACK_START)
#define UND_STACK_SIZE     (TASK_STACK_START    - UND_STACK_START)
#define TASK_STACK_SIZE    (GLOBAL_ADDR_START   - TASK_STACK_START)
#define GLOBAL_ADDR_SIZE   (DALLOC_ADDR_START   - GLOBAL_ADDR_START)
#define DALLOC_MEM_SIZE    (END_OF_MEMORY_MAP   - DALLOC_ADDR_START)

#define USRSYS_STACK_TOP   (USRSYS_STACK_START  + USRSYS_STACK_SIZE - 4)
#define SVC_STACK_TOP      (SVC_STACK_START     + SVC_STACK_SIZE    - 4)
#define IRQ_STACK_TOP      (IRQ_STACK_START     + IRQ_STACK_SIZE    - 4)
#define FIQ_STACK_TOP      (FIQ_STACK_START     + FIQ_STACK_SIZE    - 4)
#define ABT_STACK_TOP      (ABT_STACK_START     + ABT_STACK_SIZE    - 4)
#define UND_STACK_TOP      (UND_STACK_START     + UND_STACK_SIZE    - 4)

#endif  //!__MEMORYMAP__H__