/* MODULE gpio_pins. */

#include "gpio_pins.h"
#include <stdbool.h>

gpio_input_pin_user_config_t switchPins[] = {
  {
    .pinName = kGpioSW1,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntFallingEdge
  },
  {
    .pinName = kGpioSW2,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntFallingEdge
  },
   {
    .pinName = inPTB9,          //GARO
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullDown,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntEitherEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_input_pin_user_config_t accelIntPins[] = {
  {
    .pinName = kGpioAccelINT1,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = kGpioAccelINT2,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_input_pin_user_config_t gpioUartDemoRxPin[] = {
  {
    .pinName = kGpioUartDemoRX,
    .config.isPullEnable = false,
    .config.pullSelect = kPortPullUp,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntFallingEdge,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t sdhcCdPin[] = {
  {
    .pinName = kGpioSdhc0Cd,
    .config.isPullEnable = true,
    .config.pullSelect = kPortPullDown,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntEitherEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_output_pin_user_config_t ledPins[] = {
  {
    .pinName = kGpioLED1,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioLED2,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioLED3,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = outPTB23, //GARO
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.isOpenDrainEnabled = false,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};
      
const gpio_output_pin_user_config_t spiCsPin[] = {
  {
    .pinName = kGpioSpi0Cs0,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = kGpioSpi0Cs1,
    .config.outputLogic = 1,
    .config.slewRate = kPortSlowSlewRate,
    .config.driveStrength = kPortLowDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

/* END gpio_pins. */
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
