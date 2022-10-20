/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 09:53, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "RS.h"
#include "BitIoLdd1.h"
#include "RW.h"
#include "BitIoLdd2.h"
#include "EN.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
int k;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
void Lcd_Delay(unsigned char Delay)
{
	int i,j;
	for(i=0;i<Delay;i++)
		for(j=0;j<0x7fff;j++);
}
void Lcd_command(unsigned char command)
{
	Bits1_PutVal(command);
	RS_PutVal(0);
	RW_PutVal(0);
	EN_PutVal(1);
	Lcd_Delay(1);
	EN_PutVal(0);
}
void Lcd_Data(unsigned char data)
{
	Bits1_PutVal(data);
	RS_PutVal(1);
	RW_PutVal(0);
	EN_PutVal(1);
	Lcd_Delay(1);
	EN_PutVal(0);
}
void Lcd_puts(unsigned char *string)
{
	 while(*string)
	 {
		 Lcd_Data(*string++);
	}
}
void Lcd_init()
  {
	 Lcd_command(0x01);  
	  Lcd_command(0x38);
	  Lcd_command(0x0F);
	  Lcd_command(0x06);
	  
	   
	  
//      Lcd_command(0x28);
	  
	   
  }

int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  Lcd_init();
  while(1)
  {
	  
	  Lcd_command(0x80);
     Lcd_puts("Hello");
     Lcd_command(0x1c);
     Lcd_command(0xc7);     
     Lcd_puts("Bosch ");
     Lcd_command(0x1c);
	  
  
  }/*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
