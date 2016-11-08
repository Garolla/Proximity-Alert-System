   

#ifndef __gpio_pins_H
#define __gpio_pins_H

/* MODULE gpio_pins. */

/* Include inherited beans */
#include "fsl_gpio_driver.h"


/*! @brief Configuration structure 0 for input pins */
extern gpio_input_pin_user_config_t switchPins[];
/*! @brief Configuration structure 1 for input pins */
extern const gpio_input_pin_user_config_t accelIntPins[];
/*! @brief Configuration structure 3 for input pins */
extern const gpio_input_pin_user_config_t sdhcCdPin[];

/*! @brief Configuration structure 0 for output pins */
extern const gpio_output_pin_user_config_t ledPins[];

extern const gpio_output_pin_user_config_t spiCsPin[];

extern const gpio_input_pin_user_config_t gpioUartDemoRxPin[];

/*! @brief Pin names */
enum _gpio_pins_pinNames{
  kGpioSW1 = GPIO_MAKE_PIN(HW_GPIOC, 6U),
  kGpioSW2 = GPIO_MAKE_PIN(HW_GPIOA, 4U),
  kGpioAccelINT1 = GPIO_MAKE_PIN(HW_GPIOC, 6U),
  kGpioAccelINT2 = GPIO_MAKE_PIN(HW_GPIOC, 13U),
  kGpioSdhc0Cd = GPIO_MAKE_PIN(HW_GPIOE, 6U),
  kGpioLED1 = GPIO_MAKE_PIN(HW_GPIOE, 26U),
  kGpioLED2 = GPIO_MAKE_PIN(HW_GPIOB, 22U),
  kGpioLED3 = GPIO_MAKE_PIN(HW_GPIOB, 21U),
  kGpioUartDemoRX = GPIO_MAKE_PIN(HW_GPIOB, 16),
  kGpioSpi0Cs0 = GPIO_MAKE_PIN(HW_GPIOD, 0),
  kGpioSpi0Cs1 = GPIO_MAKE_PIN(HW_GPIOD, 4),
  
  outPTB23 = GPIO_MAKE_PIN(HW_GPIOB, 23U), //GARO
  inPTB9 = GPIO_MAKE_PIN(HW_GPIOB, 9U),
};

  
#endif

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.10]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
