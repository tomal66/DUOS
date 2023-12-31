#ifndef __SYS_H
#define __SYS_H
#ifdef __cplusplus
extern "C"
{
#endif
#define NVIC_SetPriorityGrouping __NVIC_SetPriorityGrouping
#define NVIC_GetPriorityGrouping __NVIC_GetPriorityGrouping
#define NVIC_EnableIRQ __NVIC_EnableIRQn
#define NVIC_GetEnableIRQ __NVIC_GetEnableIRQ
#define NVIC_DisableIRQ __NVIC_DisableIRQ
#define NVIC_GetPendingIRQ __NVIC_GetPendingIRQ
#define NVIC_SetPendingIRQ __NVIC_SetPendingIRQ
#define NVIC_ClearPendingIRQ __NVIC_ClearPendingIRQ
#define NVIC_GetActive __NVIC_GetActive
#define NVIC_SetPriority __NVIC_SetPriority
#define NVIC_GetPriority __NVIC_GetPriority
#define NVIC_SystemReset __NVIC_SystemReset

#define Disable_irq __disable_irq
   
#define Set_BASEPRI __set_BASEPRI
#define Get_BASEPRI_Value __get_basepri_value
#define Enable_irq(); __enable_irq();
    
#define Unset_BASEPRI  __unset_BASEPRI
#define Set_PRIMASK  __set_PRIMASK
#define Get_PRIMASK __get_PRIMASK
#define Enable_fault_irq  __enable_fault_irq
#define Set_FAULTMASK  __set_FAULTMASK
#define Disable_fault_irq  __disable_fault_irq
#define Get_FAULTMASK   __get_FAULTMASK
#define Clear_pending_IRQn  __clear_pending_IRQn
#define Get_pending_IRQn  __get_pending_IRQn


#include <cm4.h>
#include <gpio.h>
      /* Functions of NVIC */
      void __NVIC_SetPriority(IRQn_TypeDef IRQn, uint32_t priority);
      uint32_t __NVIC_GetPriority(IRQn_TypeDef IRQn);
      void __NVIC_EnableIRQn(IRQn_TypeDef IRQn);
      void __NVIC_DisableIRQn(IRQn_TypeDef IRQn);
      void __disable_irq();
      void __set_BASEPRI(uint32_t value);
      void __enable_irq();
      void __unset_BASEPRI(uint32_t value);
      void __set_PRIMASK(uint32_t priMask);
      uint32_t __get_PRIMASK(void);
      void __enable_fault_irq(void);
      void __set_FAULTMASK(uint32_t faultMask);
      void __disable_fault_irq(void);
      uint32_t __get_FAULTMASK(void);
      void __clear_pending_IRQn(IRQn_TypeDef IRQn);
      uint32_t __get_pending_IRQn(IRQn_TypeDef IRQn);
      uint32_t __NVIC_GetActive(IRQn_TypeDef IRQn);
      void EXTI_Init(GPIO_TypeDef *port, uint16_t pin);

#ifdef __cplusplus
}
#endif
#endif
