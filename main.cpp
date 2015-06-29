//#include <systick/systick.h>

/* PB1 is connected to the onboard LED on the STM32F030F4P6 breakout board. */
#define PORT_LED_ONBOARD GPIOB
#define PIN_LED_ONBOARD GPIO1

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include <core/core.h>

/* set STM32 to clock by 48MHz from HSI oscillator */
static void clock_setup(void)
{
	rcc_clock_setup_in_hsi_out_48mhz();

	/* Enable clocks to the GPIO subsystems */
	rcc_periph_clock_enable(RCC_GPIOB);
}

static void gpio_setup(void)
{
	gpio_mode_setup(PORT_LED_ONBOARD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_ONBOARD);
}

int main(void)
{
	clock_setup();
	gpio_setup();

	/* setup systick to generate 2 LED flashes per second */
	systick::init();

	/* Do nothing in main loop */
	while (1)
  {
    static const uint16_t period = 500;
    static elapsedMillis timer = period;
    if (timer >= period)
    {
      timer = 0;
      gpio_toggle(PORT_LED_ONBOARD, PIN_LED_ONBOARD);
    }
  }
}
