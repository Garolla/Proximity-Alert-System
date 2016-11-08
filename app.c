#include "fsl_interrupt_manager.h"
#include "fsl_gpio_common.h"
#include "MK64F12_lptmr.h"
#include "stdint.h" 
#include  <math.h>
#include  <lib_math.h>
#include  <cpu_core.h>
#include  <app_cfg.h>
#include  <os.h>
#include  <fsl_os_abstraction.h>
#include  <system_MK64F12.h>
#include  <board.h>
#include  <bsp_ser.h>

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
static  OS_TCB       AppTaskStartTCB;
static  CPU_STK      AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];
static  OS_TCB       TriggerTCB;
static  CPU_STK      TriggerStk[APP_CFG_TASK_START_STK_SIZE];
static  OS_TCB       BlinkingTCB;
static  CPU_STK      BlinkingStk[APP_CFG_TASK_START_STK_SIZE];

static  uint32_t period;
static  uint32_t previous;
static  float range=0.0;


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppTaskStart (void  *p_arg);
static  void  Trigger (void  *p_arg);
static  void  Blinking (void  *p_arg);


/*
  This interrupt receives data from the sensor and computes the range
*/

void BSP_PORT9_int_hdlr( void )
{
  OS_ERR err;
  uint32_t ifsr;         /* interrupt flag status register */
  uint32_t portBaseAddr = g_portBaseAddr[GPIO_EXTRACT_PORT(inPTB9)];
  uint32_t portPin = (1 << GPIO_EXTRACT_PIN(inPTB9));
  uint32_t value;
  
  CPU_CRITICAL_ENTER();
  OSIntEnter();                                               /* Tell the OS that we are starting an ISR              */
  
  ifsr = PORT_HAL_GetPortIntFlag(portBaseAddr);
  
  if( (ifsr & portPin) )                                         /* Check if the pending interrupt is for inPTB9 */
  {  
      value=GPIO_DRV_ReadPinInput( inPTB9 );
      
      if(value==1){
        LPTMR0_CSR = 1; //START the counter
      }
      else if(value==0){
        LPTMR0_CNR=0; //Freescale says you have to write to CNR any value, before read

        range=LPTMR0_CNR*31.25/58.0;

        LPTMR0_CSR =0; //STOP the counter

        //The following code will assign the period of the blinking
        previous=period;
        if(range>=200)                    period=2000u;
        else if(range>=180 && range<200)  period=1000u;  
        else if(range>=160 && range<180)  period=800u;  
        else if(range>=140 && range<160)  period=600u;
        else if(range>=120 && range<140)  period=400u;    
        else if(range>=100 && range<120)  period=200u; 
        else if(range>=75 && range<100)   period=1000u;  
        else if(range>=50 && range<75)    period=800u;  
        else if(range>=25 && range<50)    period=600u;
        else if(range<25)                 period=400u;    
        
        //This is code is necessary to have e real time behavior
        if(previous!=period)
          OSTimeDlyResume(&BlinkingTCB,&err);

      }
     GPIO_DRV_ClearPinIntFlag( inPTB9 );
  }
  CPU_CRITICAL_EXIT();
  OSIntExit();
  
}
int  main (void)
{
    OS_ERR   err;
    
#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_ERR  cpu_err;
#endif
  
    hardware_init();
    
    //LPTMR init
    SIM_SCGC5 |= SIM_SCGC5_LPTMR_MASK; //Enable the clock of the LPTMR
    LPTMR0_CSR = 0; //Clean the control register
    LPTMR0_PSR = 6; //LPO feeds directly to LPT; use of ERCLK 32 KHZ 
    LPTMR0_CMR =65535; //Set compare value as max

    GPIO_DRV_Init(switchPins, ledPins);


#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_NameSet((CPU_CHAR *)"MK64FN1M0VMD12",
                (CPU_ERR  *)&cpu_err);
#endif

    OSA_Init();                                                 /* Init uC/OS-III.                                      */
    
    INT_SYS_InstallHandler(PORTB_IRQn, BSP_PORT9_int_hdlr);      
    
    OSTaskCreate(&AppTaskStartTCB,                              /* Create the start task                                */
                 "App Task Start",
                  AppTaskStart,
                  0u,
                  APP_CFG_TASK_START_PRIO,
                 &AppTaskStartStk[0u],
                 (APP_CFG_TASK_START_STK_SIZE / 10u),
                  APP_CFG_TASK_START_STK_SIZE,
                  0u,
                  0u,
                  0u,
                 (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP),
                 &err);

    OSA_Start();                                                /* Start multitasking (i.e. give control to uC/OS-III). */

    while (DEF_ON) {                                            /* Should Never Get Here                                */
        ;
    }
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
    OS_ERR    os_err;

    (void)p_arg;                                                /* See Note #1                                          */


    CPU_Init();                                                 /* Initialize the uC/CPU Services.                      */
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    BSP_Ser_Init(115200u);

    APP_TRACE_DBG(("Blinking RGB LED...\n\r"));
    
    OSTaskCreate(&TriggerTCB,                              /* Create the task trigger                              */
                 "Triggering Sensor",
                  Trigger,
                  0u,
                  APP_CFG_TASK_START_PRIO,
                 &TriggerStk[0u],
                 (APP_CFG_TASK_START_STK_SIZE / 10u),
                  APP_CFG_TASK_START_STK_SIZE,
                  0u,
                  0u,
                  0u,
                 (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP),
                 &os_err);


    OSTaskCreate(&BlinkingTCB,                              /* Create the task blink                                */
                 "Task Blink",
                  Blinking,
                  0u,
                  APP_CFG_TASK_START_PRIO,
                 &BlinkingStk[0u],
                 (APP_CFG_TASK_START_STK_SIZE / 10u),
                  APP_CFG_TASK_START_STK_SIZE,
                  0u,
                  0u,
                  0u,
                 (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP),
                 &os_err);
        
    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
      ;
    }
}

/*
  This task only sends the trigger to the sensor
*/

static  void  Trigger (void *p_arg)
{
    OS_ERR    os_err;
    (void)p_arg;                                                /* See Note #1                                          */
    
    while (DEF_TRUE) {     
                                     /* Task body, always written as an infinite loop.       */         
    
      GPIO_DRV_SetPinOutput( outPTB23 );       //Trigger
      OSTimeDlyHMSM(0u, 0u, 0u, 1u,OS_OPT_TIME_HMSM_STRICT,&os_err); 
      
      GPIO_DRV_ClearPinOutput( outPTB23 ); 
      
      OSTimeDlyHMSM(0u, 0u, 0u, 60u,OS_OPT_TIME_HMSM_STRICT,&os_err); //One trigger every 60 microseconds, roughly

    }
}

/*
  This task makes blink the led
*/
static  void  Blinking(void *p_arg)
{
    OS_ERR    os_err;
    (void)p_arg;                                                /* See Note #1                                          */
    uint32_t on;
    uint32_t off1;
    uint32_t off2;    
    float TMP=0.0;
    
    while (DEF_TRUE) {    
      

      TMP=range;
      
      if (TMP < 10){
        
        GPIO_DRV_ClearPinOutput( BOARD_GPIO_LED_RED );
        GPIO_DRV_SetPinOutput( BOARD_GPIO_LED_GREEN );
        GPIO_DRV_SetPinOutput( BOARD_GPIO_LED_BLUE );
      }else{
        if(TMP>=200){  
        on= BOARD_GPIO_LED_GREEN;
        off1=BOARD_GPIO_LED_RED;
        off2=BOARD_GPIO_LED_BLUE;

       }else if (TMP>=100 && TMP<200){
        on= BOARD_GPIO_LED_BLUE;
        off1=BOARD_GPIO_LED_RED;
        off2=BOARD_GPIO_LED_GREEN;

      }else if (TMP>=10 && TMP<100){
        on= BOARD_GPIO_LED_RED;
        off1=BOARD_GPIO_LED_GREEN;
        off2=BOARD_GPIO_LED_BLUE;
      } 
      
      GPIO_DRV_TogglePinOutput( on );
      GPIO_DRV_SetPinOutput( off1 );
      GPIO_DRV_SetPinOutput( off2 );

      OSTimeDlyHMSM(0u, 0u, 0u, period,OS_OPT_TIME_HMSM_STRICT,&os_err); 
      }
    }
}