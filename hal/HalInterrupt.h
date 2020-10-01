#ifndef __HAL_INTERRUPT__H__
#define __HAL_INTERRUPT__H__

#define INTERRUPT_HANDLER_NUM 255

typedef void(*InterHdlr_fptr)(void);

void Hal_interrupt_init(void);
void Hal_interrupt_enable(uint32_t interrupt_num);
void Hal_interrupt_disable(uint32_t interrupt_num);
void Hal_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrupt_num);
void Hal_interrupt_run_handler(void);

#endif  //!__HAL_INTERRUPT__H__