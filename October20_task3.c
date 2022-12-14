<<<<<<< HEAD
/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 14:09, # CodeGen: 0
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
#include "KP_Row.h"
#include "BitsIoLdd1.h"
#include "KP_Col.h"
#include "BitsIoLdd2.h"
#include "Bits1.h"
#include "BitsIoLdd3.h"
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
int k,j,i,x,y,z,count=0;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
void Lcd_Delay(unsigned char Delay)
{
	
	for(i=0;i<Delay;i++)
		for(y=0;y<0x7fff;y++);
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
	Lcd_command(0x80);
	 Lcd_command(0x01);  
	  Lcd_command(0x38);
	  Lcd_command(0x0F);
	  Lcd_command(0x06);
	  
	   
	  
//      Lcd_command(0x28);
	  
	   
  }

int GetRows(){
	  KP_Row_SetDir(1);
	  KP_Col_SetDir(1);
	  KP_Row_PutVal(0xf);
	  KP_Col_PutVal(0x0);
	  KP_Row_SetDir(0);
	  x=KP_Row_GetVal();
	 return x;
}

int GetColumn(){
	 	  KP_Row_SetDir(1);
	 	  KP_Col_SetDir(1);
	 	  KP_Row_PutVal(0x0);
	 	  KP_Col_PutVal(0xf);
	 	  KP_Col_SetDir(0);
	 	  z=KP_Col_GetVal();
	 	  return z;
}
void Alpha()
{
	if(z==0xe&&x==0x7)
		{
			 
			Lcd_puts("A");
			 
			
			 
		}
		
		if(z==0xe&&x==0xb)
			{
				 
				Lcd_puts("B");
			}
		if(z==0xe&&x==0xd)
			{
				
				Lcd_puts("C");
			}
		if(z==0xe&&x==0xe)
			{
				 
				Lcd_puts("D");
			}
		if(z==0xd&&x==0x7)
			{	
				 
				Lcd_puts("E");
				}
		if(z==0xd&&x==0xb)
				{
					 
					Lcd_puts("F");
				}
		if(z==0xd&&x==0xd)
				{
					 
					Lcd_puts("G");
				}
		if(z==0xd&&x==0xe)
				{
					 
					Lcd_puts("H");
				}
		if(z==0xb&&x==0x7)
				{	
					 
					Lcd_puts("I");
					}
			if(z==0xb&&x==0xb)
					{
						 
						Lcd_puts("J");
					}
			if(z==0xb&&x==0xd)
					{
						 
						Lcd_puts("K");
					}
			if(z==0xb&&x==0xe)
					{
						 
						Lcd_puts("L");
					}
			if(z==0x7&&x==0x7)
						{	
							 
							Lcd_puts("M");
							}
			if(z==0x7&&x==0xb)
							{
								 
								Lcd_puts("N");
							}
			if(z==0x7&&x==0xd)
							{
								 Lcd_command(0x10);
								  
								Lcd_puts(" ");
								 Lcd_command(0x10);
								
							}
			if(z==0x7&&x==0xe)
							{
								Lcd_command(0xC0);
								 
							}
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  
  /*** End of Processor Expert internal initialization.                    ***/
  Lcd_init();
while(1)
{
	
	x=GetRows();
	z= GetColumn();
	Alpha();
	Lcd_Delay(6);
	

}

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
=======
/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 14:09, # CodeGen: 0
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
#include "KP_Row.h"
#include "BitsIoLdd1.h"
#include "KP_Col.h"
#include "BitsIoLdd2.h"
#include "Bits1.h"
#include "BitsIoLdd3.h"
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
int k,j,i,x,y,z,count=0;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
void Lcd_Delay(unsigned char Delay)
{
	
	for(i=0;i<Delay;i++)
		for(y=0;y<0x7fff;y++);
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
	Lcd_command(0x80);
	 Lcd_command(0x01);  
	  Lcd_command(0x38);
	  Lcd_command(0x0F);
	  Lcd_command(0x06);
	  
	   
	  
//      Lcd_command(0x28);
	  
	   
  }

int GetRows(){
	  KP_Row_SetDir(1);
	  KP_Col_SetDir(1);
	  KP_Row_PutVal(0xf);
	  KP_Col_PutVal(0x0);
	  KP_Row_SetDir(0);
	  x=KP_Row_GetVal();
	 return x;
}

int GetColumn(){
	 	  KP_Row_SetDir(1);
	 	  KP_Col_SetDir(1);
	 	  KP_Row_PutVal(0x0);
	 	  KP_Col_PutVal(0xf);
	 	  KP_Col_SetDir(0);
	 	  z=KP_Col_GetVal();
	 	  return z;
}
void Alpha()
{
	if(z==0xe&&x==0x7)
		{
			 
			Lcd_puts("A");
			 
			
			 
		}
		
		if(z==0xe&&x==0xb)
			{
				 
				Lcd_puts("B");
			}
		if(z==0xe&&x==0xd)
			{
				
				Lcd_puts("C");
			}
		if(z==0xe&&x==0xe)
			{
				 
				Lcd_puts("D");
			}
		if(z==0xd&&x==0x7)
			{	
				 
				Lcd_puts("E");
				}
		if(z==0xd&&x==0xb)
				{
					 
					Lcd_puts("F");
				}
		if(z==0xd&&x==0xd)
				{
					 
					Lcd_puts("G");
				}
		if(z==0xd&&x==0xe)
				{
					 
					Lcd_puts("H");
				}
		if(z==0xb&&x==0x7)
				{	
					 
					Lcd_puts("I");
					}
			if(z==0xb&&x==0xb)
					{
						 
						Lcd_puts("J");
					}
			if(z==0xb&&x==0xd)
					{
						 
						Lcd_puts("K");
					}
			if(z==0xb&&x==0xe)
					{
						 
						Lcd_puts("L");
					}
			if(z==0x7&&x==0x7)
						{	
							 
							Lcd_puts("M");
							}
			if(z==0x7&&x==0xb)
							{
								 
								Lcd_puts("N");
							}
			if(z==0x7&&x==0xd)
							{
								 Lcd_command(0x10);
								  
								Lcd_puts(" ");
								 Lcd_command(0x10);
								
							}
			if(z==0x7&&x==0xe)
							{
								Lcd_command(0xC0);
								 
							}
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  
  /*** End of Processor Expert internal initialization.                    ***/
  Lcd_init();
while(1)
{
	
	x=GetRows();
	z= GetColumn();
	Alpha();
	Lcd_Delay(6);
	

}

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
>>>>>>> 8a56d34962699b4d22ff5f938bef5f8c96cfd02c
