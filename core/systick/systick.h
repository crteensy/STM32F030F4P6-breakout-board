#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

#include <libopencm3/cm3/nvic.h>

namespace systick
{
  static volatile uint32_t millis_;
  uint32_t millis();
  uint32_t extraTicks();
  void init();
} // namespace systick

#endif // SYSTICK_H

