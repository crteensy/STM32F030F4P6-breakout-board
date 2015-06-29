#include "systick.h"

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>

namespace systick
{

uint32_t millis()
{
  uint32_t result;
  CM_ATOMIC_BLOCK()
  {
    result = millis_;
  }
  return result;
}
uint32_t extraTicks()
{
  return (STK_RVR & STK_RVR_RELOAD) - (STK_CVR & STK_CVR_CURRENT);
}
void init()
{
  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
  /* clear counter so it starts right away */
  STK_CVR = 0;

  systick_set_reload(rcc_ahb_frequency / 1000);
  systick_counter_enable();
  systick_interrupt_enable();
}

} // namespace systick

// not in namespace systick, because the linker wouldn't use it as an ISR otherwise:
void sys_tick_handler(void)
{
  systick::millis_++;
}

