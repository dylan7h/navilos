#ifndef __ARMV7AR__H__
#define __ARMV7AR__H__

/* 
##################################################################################################
##                                          PSR Register                                        ##
##################################################################################################
 31 30 29 28 27 26 25 24  23 22 21 20  19 18 17 16   15 14 13 12 11 10  9  8  7  6  5  4 3 2 1 0
┌-┬-┬-┬-┬-┬-----┬-┬-----------┬------------┬------------------┬-┬-┬-┬-┬-┬-----------┐
│N│Z│C│V│Q│     │J│    DNM    │     GE     │       IT         │E│A│I│F│T│     M     │
└-┴-┴-┴-┴-┴-----┴-┴-----------┴------------┴------------------┴-┴-┴-┴-┴-┴-----------┘
[31]    : N     - 연산 결과가 음수일때 1로 Set
[30]    : Z     - 연산 결과가 0일때 1로 Set
[29]    : C     - 연산 결과가 32bit을 넘으면 1로 Set
[28]    : V     - 연산 결과가 32bit을 넘어서 sign bit가 상실되면 1로 Set
[27]    : Q     - 연산결과가 +의 최대값(0x7FFFFFFF)과 -의 최소값(0x80000000)이 넘지 않게 하기위해 사용되고 주로 분수 연산을 한다.
[24]    : J     - JAVA Code 실행 가능 여부
[23:20] : DNM   - Do Not Modify
[19:16] : GE    - SIMD greater-or-equal 플래그
[15:10] : IT    - ITSTATE로 Thumb-2에 포함된 IT(If-Then) 명령어를 처리할때 참조하는 Bit
[9]     : E     - Data Endian Selector(1: Big, 0: Little)
[8]     : A     - 1: 예측 가능한 ABORT만 발생, 0: 예측 불가능한 ABORT까지 발생
[7]     : I     - 1: IRQ Enable, 0: IRQ Disable
[6]     : F     - 1: FIQ Enable, 0: FIQ Disable
[5]     : T     - Thumb Mode일 때 1로 Set
[4:0]   : M     - Mode Bit
                0b10000 : USR(Normal Program execution mode)
                0b10001 : FIQ(When a high priority (fast) interrupt is raised)
                0b10010 : IRQ(When a low priority (normal) interrupt is raised)
                0b10011 : SVC(A protected mode for the operating system, entered when a SWI instruction is executed)
                0b10110 : MON(Monitor)
                0b10111 : ABT(Used to handle memory access violations)
                0b11010 : HYP(Hypervisor)
                0b11011 : UND(Used to handle undefined instructions)
                0b11111 : SYS(Run privileged operating system tasks)
 */

/* ARMv7 동작 Mode 전환 값 */
#define ARM_MODE_BIT_USR 0x10
#define ARM_MODE_BIT_FIQ 0x11
#define ARM_MODE_BIT_IRQ 0x12
#define ARM_MODE_BIT_SVC 0x13
#define ARM_MODE_BIT_MON 0x16
#define ARM_MODE_BIT_ABT 0x17
#define ARM_MODE_BIT_UND 0x1B
#define ARM_MODE_BIT_SYS 0x1F

#endif  //!__ARMV7AR__H__
