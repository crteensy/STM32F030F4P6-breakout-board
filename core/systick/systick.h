#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

#include <libopencm3/cm3/nvic.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern volatile uint32_t systick_millis_;
uint32_t millis();
uint32_t systick_extraTicks();
void systick_init();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SYSTICK_H

