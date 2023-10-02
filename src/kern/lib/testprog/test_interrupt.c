#include <test_interrupt.h>
#include <cm4.h>
#include <kstdio.h>

volatile int hardfault_event_enabled = 0; // Volatile to prevent optimization

void hardfault_event(void)
{
      int *ptr = 0xFFFFFFFF; // Invalid memory address
      int value = *ptr;                      // This will trigger a HardFault
}

void reboot()
{
      kprintf("Rebooting..................\n");
      SCB->AIRCR = (0x5FA << 16) | (0x4 << 0); // SCB_AIRCR = VECTKEY | SYSRESETREQ
}
void enableSysTickInterrupt(void)
{
      SYSTICK->CTRL |= (1 << 1);
      for (int i = 0; i < 5; i++)
      {
            Delay(1000);
            kprintf("SysTick: %d\n", getMsCount());
      }
}

void disableSysTickInterrupt(void)
{
      SYSTICK->CTRL &= ~(1 << 1);
}