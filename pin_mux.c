/* MODULE pin_mux. */


#include "fsl_device_registers.h"
#include "fsl_port_hal.h"
#include "fsl_sim_hal.h"
#include "pin_mux.h"



void configure_can_pins(uint32_t instance)
{
  /* PORTB_PCR19 */
  PORT_HAL_SetMuxMode(PORTB_BASE,19u,kPortMuxAlt2);
  /* PORTB_PCR18 */
  PORT_HAL_SetMuxMode(PORTB_BASE,18u,kPortMuxAlt2);
}

void configure_cmp_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_CMP0:                       /* CMP0 */
      /* Affects PORTB_PCR20 register */
      PORT_HAL_SetMuxMode(PORTB_BASE,20u,kPortMuxAlt6);
      break;
    default:
      break;
  }
}

void configure_enet_pins(uint32_t instance)
{
  /* Affects PORTC_PCR16 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,16u,kPortMuxAlt4);
  /* Affects PORTC_PCR17 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,17u,kPortMuxAlt4);
  /* Affects PORTC_PCR18 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,18u,kPortMuxAlt4);
  /* Affects PORTC_PCR19 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,19u,kPortMuxAlt4);
  /* Affects PORTB_PCR1 register */
  PORT_HAL_SetMuxMode(PORTB_BASE,1u,kPortMuxAlt4);
  /* Affects PORTB_PCR0 register */
  PORT_HAL_SetMuxMode(PORTB_BASE,0u,kPortMuxAlt4);
  PORT_HAL_SetOpenDrainCmd(PORTB_BASE,0u,true);
  PORT_HAL_SetPullMode(PORTB_BASE,0u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTB_BASE,0u,true);
  /* Affects PORTA_PCR13 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,13u,kPortMuxAlt4);
  /* Affects PORTA_PCR12 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,12u,kPortMuxAlt4);
  /* Affects PORTA_PCR14 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,14u,kPortMuxAlt4);
  /* Affects PORTA_PCR5 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,5u,kPortMuxAlt4);
  /* Affects PORTA_PCR16 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,16u,kPortMuxAlt4);
  /* Affects PORTA_PCR17 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,17u,kPortMuxAlt4);
  /* Affects PORTA_PCR15 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,15u,kPortMuxAlt4);
  /* Affects PORTA_PCR28 register */
  PORT_HAL_SetMuxMode(PORTA_BASE,28u,kPortMuxAlt4);
}

void configure_gpio_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_PORTA:                      /* HW_PORTA */
      /* Affects PORTA_PCR4 register */
      PORT_HAL_SetPassiveFilterCmd(PORTA_BASE,4u,false);
      PORT_HAL_SetMuxMode(PORTA_BASE,4u,kPortMuxAsGpio);
      PORT_HAL_SetPullMode(PORTA_BASE,4u,kPortPullUp);
      PORT_HAL_SetPullCmd(PORTA_BASE,4u,true);
      break;
    case HW_PORTB:                      /* HW_PORTB */
      /* Affects PORTB_PCR21 register */
      PORT_HAL_SetDriveStrengthMode(PORTB_BASE,21u,kPortLowDriveStrength);  
      PORT_HAL_SetMuxMode(PORTB_BASE,21u,kPortMuxAsGpio);
      PORT_HAL_SetSlewRateMode(PORTB_BASE,21u,kPortSlowSlewRate);
      /* Affects PORTB_PCR22 register */
      PORT_HAL_SetDriveStrengthMode(PORTB_BASE,22u,kPortLowDriveStrength);  
      PORT_HAL_SetMuxMode(PORTB_BASE,22u,kPortMuxAsGpio);
      PORT_HAL_SetSlewRateMode(PORTB_BASE,22u,kPortSlowSlewRate);
      
      PORT_HAL_SetMuxMode(PORTB_BASE,23u,kPortMuxAsGpio);       //GARO
      PORT_HAL_SetMuxMode(PORTB_BASE,9u,kPortMuxAsGpio);
      break;
    case HW_PORTC:                      /* HW_PORTC */
      /* Affects PORTC_PCR0 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,0u,kPortMuxAsGpio);
      /* Affects PORTC_PCR6 register */
      PORT_HAL_SetPassiveFilterCmd(PORTC_BASE,6u,false);
      PORT_HAL_SetMuxMode(PORTC_BASE,6u,kPortMuxAsGpio);
      PORT_HAL_SetPullMode(PORTC_BASE,6u,kPortPullUp);
      PORT_HAL_SetPullCmd(PORTC_BASE,6u,true);
      /* Affects PORTC_PCR8 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,8u,kPortMuxAsGpio);
      /* Affects PORTC_PCR9 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,9u,kPortMuxAsGpio);
      /* Affects PORTC_PCR12 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,12u,kPortMuxAsGpio);
      /* Affects PORTC_PCR13 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,13u,kPortMuxAsGpio);
      break;
    case HW_PORTE:                      /* HW_PORTE */
      /* Affects PORTE_PCR6 register */
      PORT_HAL_SetMuxMode(PORTE_BASE,6u,kPortMuxAsGpio);
      /* Affects PORTE_PCR26 register */
      PORT_HAL_SetDriveStrengthMode(PORTE_BASE,26u,kPortLowDriveStrength);  
      PORT_HAL_SetMuxMode(PORTE_BASE,26u,kPortMuxAsGpio);
      PORT_HAL_SetSlewRateMode(PORTE_BASE,26u,kPortSlowSlewRate);
      break;
    default:
      break;
  }
}

void configure_i2c_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_I2C0:                       /* I2C0 */
      /* Affects PORTE_PCR24 register */
      PORT_HAL_SetMuxMode(PORTE_BASE,24u,kPortMuxAlt5);
      PORT_HAL_SetOpenDrainCmd(PORTE_BASE,24u,true);
      /* Affects PORTE_PCR25 register */
      PORT_HAL_SetMuxMode(PORTE_BASE,25u,kPortMuxAlt5);
      PORT_HAL_SetOpenDrainCmd(PORTE_BASE,25u,true);
      break;
    case HW_I2C1:                       /* I2C1 */
      /* Affects PORTC_PCR10 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,10u,kPortMuxAlt2);
      PORT_HAL_SetOpenDrainCmd(PORTC_BASE,10u,true);
      /* Affects PORTC_PCR11 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,11u,kPortMuxAlt2);
      PORT_HAL_SetOpenDrainCmd(PORTC_BASE,11u,true);
      break;
    default:
      break;
  }
}

void configure_i2s_pins(uint32_t instance)
{
  /* Affects PORTC_PCR8 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,8u,kPortMuxAlt4);
  /* Affects PORTC_PCR9 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,9u,kPortMuxAlt4);
  /* Affects PORTC_PCR7 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,7u,kPortMuxAlt4);
  /* Affects PORTC_PCR5 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,5u,kPortMuxAlt4);
  /* Affects PORTB_PCR18 register */
  PORT_HAL_SetMuxMode(PORTB_BASE,18u,kPortMuxAlt4);
  /* Affects PORTB_PCR19 register */
  PORT_HAL_SetMuxMode(PORTB_BASE,19u,kPortMuxAlt4);
  /* Affects PORTC_PCR1 register */
  PORT_HAL_SetMuxMode(PORTC_BASE,1u,kPortMuxAlt6);
}

void configure_rtc_pins(uint32_t instance)
{
  /* Affects PORTE_PCR26 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,26u,kPortMuxAlt6);
}

void configure_sdhc_pins(uint32_t instance)
{
  /* Affects PORTE_PCR3 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,3u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,3u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,3u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,3u,kPortHighDriveStrength);
  /* Affects PORTE_PCR1 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,1u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,1u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,1u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,1u,kPortHighDriveStrength);
  /* Affects PORTE_PCR0 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,0u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,0u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,0u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,0u,kPortHighDriveStrength);
  /* Affects PORTE_PCR5 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,5u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,5u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,5u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,5u,kPortHighDriveStrength);
  /* Affects PORTE_PCR4 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,4u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,4u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,4u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,4u,kPortHighDriveStrength);
  /* Affects PORTE_PCR2 register */
  PORT_HAL_SetMuxMode(PORTE_BASE,2u,kPortMuxAlt4);
  PORT_HAL_SetPullMode(PORTE_BASE,2u,kPortPullUp);
  PORT_HAL_SetPullCmd(PORTE_BASE,2u,true);
  PORT_HAL_SetDriveStrengthMode(PORTE_BASE,2u,kPortHighDriveStrength);
}

void configure_spi_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_SPI0:                       /* SPI0 */
      /* Affects PORTD_PCR0 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,0u,kPortMuxAlt2);
      /* Affects PORTD_PCR3 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,3u,kPortMuxAlt2);
      /* Affects PORTD_PCR1 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,1u,kPortMuxAlt2);
      /* Affects PORTD_PCR2 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,2u,kPortMuxAlt2);
      break;
    case HW_SPI1:                       /* SPI1 */
      /* Affects PORTD_PCR4 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,4u,kPortMuxAlt7);
      /* Affects PORTD_PCR7 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,7u,kPortMuxAlt7);
      /* Affects PORTD_PCR5 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,5u,kPortMuxAlt7);
      /* Affects PORTD_PCR6 register */
      PORT_HAL_SetMuxMode(PORTD_BASE,6u,kPortMuxAlt7);
      break;
    default:
      break;
  }
}

void configure_uart_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_UART0:                      /* UART0 */
      /* Affects PORTB_PCR16 register */
      PORT_HAL_SetMuxMode(PORTB_BASE,16u,kPortMuxAlt3);
      /* Affects PORTB_PCR17 register */
      PORT_HAL_SetMuxMode(PORTB_BASE,17u,kPortMuxAlt3);
      break;
    case HW_UART4:                      /* UART4 */
      /* Affects PORTC_PCR14 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,14u,kPortMuxAlt3);
      /* Affects PORTC_PCR15 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,15u,kPortMuxAlt3);
      break;
    default:
      break;
  }
}

void configure_spi_cs0_pins(uint32_t instance)
{
  PORT_HAL_SetMuxMode(PORTD_BASE,0u,kPortMuxAsGpio);
}

void configure_spi_cs1_pins(uint32_t instance)
{
  PORT_HAL_SetMuxMode(PORTD_BASE,4u,kPortMuxAsGpio);
}

void configure_gpio_i2c_pins(uint32_t instance)
{
  PORT_HAL_SetMuxMode(PORTE_BASE,24u,kPortMuxAsGpio);
  PORT_HAL_SetMuxMode(PORTE_BASE,25u,kPortMuxAsGpio);
}

void configure_ftm_pins(uint32_t instance)
{
  switch(instance) {    
    case HW_FTM0:                       /* FTM0 */
      /* Affects PORTE_PCR6 register */
      PORT_HAL_SetMuxMode(PORTC_BASE,1u,kPortMuxAlt4);
      break;
    default:
      break;
  }
}

/* END pin_mux. */
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
