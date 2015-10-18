#ifndef STM32F429_SYSTICK__H_
#define STM32F429_SYSTICK__H_

#include "reg.h"

typedef struct
{
  volatile unsigned long CTRL;                    //!< Offset: 0x000 (R/W)  SysTick Control and Status Register  
  volatile unsigned long LOAD;                    //!< Offset: 0x004 (R/W)  SysTick Reload Value Register        
  volatile unsigned long VAL;                     //!< Offset: 0x008 (R/W)  SysTick Current Value Register       
  volatile unsigned long CALIB;                   //!< Offset: 0x00C (R/ )  SysTick Calibration Register         
} SysTick_Type;

// SysTick Control / Status Register Definitions 
#define SysTick_CTRL_COUNTFLAG_Pos         16	//!< SysTick CTRL: COUNTFLAG Position  
#define SysTick_CTRL_CLKSOURCE_Pos          2	//!< SysTick CTRL: CLKSOURCE Position  
#define SysTick_CTRL_TICKINT_Pos            1	//!< SysTick CTRL: TICKINT Position  
#define SysTick_CTRL_ENABLE_Pos             0	//!< SysTick CTRL: ENABLE Position  

#define setMcuSystickLoad(x)		SysTick->LOAD = x
#define startMcuSystick()			SysTick->CTRL = (1 << SysTick_CTRL_CLKSOURCE_Pos) | ( 1 << SysTick_CTRL_TICKINT_Pos) | ( 1 << SysTick_CTRL_ENABLE_Pos);

#endif
