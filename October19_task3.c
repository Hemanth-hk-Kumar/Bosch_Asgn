/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-18, 14:53, # CodeGen: 0
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
#include "Bits2.h"
#include "BitsIoLdd2.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
#include "Bit3.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
int i,d1,temp,j,th1,x,c;
int number,mm,ss,z,flag=0;
/* User includes (#include below this line is not maintained by Processor Expert) */
void SevSeg(num){
	
	switch(num){
	
	
	case 0: if (num==0){
		 		Bits1_PutVal(~0x3f);
		break;
	}
	case 1: if (num==1){
		
			Bits1_PutVal(~0x06);
			break;
	}
	case 2: if (num==2){
				Bits1_PutVal(~0x5B);
				break;
		}
	case 3: if (num==3){
				Bits1_PutVal(~0x4F);
				break;
		}
	case 4: if (num==4){
				Bits1_PutVal(~0x66);
				break;
		}
	case 5: if (num==5){
				Bits1_PutVal(~0x6D);
				break;
		}
	case 6: if (num==6){
				Bits1_PutVal(~0x7C);
				break;
		}
	case 7: if (num==7){
				Bits1_PutVal(~0x07);
				break;
		}
	case 8: if (num==8){
				Bits1_PutVal(~0x7F);
				break;
		}
	case 9: if (num==9){
				Bits1_PutVal(~0x67);
				break;
		}
	case 10: if (num== 0x0a){
				Bits1_PutVal(~0x77);
				break;
		}
	case 11: if (num== 0x0b){
				Bits1_PutVal(~0x7f);
				break;
		}
	case 12: if (num== 0x0c){
				Bits1_PutVal(~0x39);
				break;
		}
	case 13: if (num== 0x0d){
				Bits1_PutVal(~0x3F);
				break;
		}
	case 14: if (num==0x0e){
				Bits1_PutVal(~0x79);
				break;
		}
	case 15: if (num==0x0f){
				Bits1_PutVal(~0x71);
				break;
		}
	}
}

void trigger(x){
	if(x==1000){
		Bits2_PutVal(0x7);
	}
	else if(x==100){
		Bits2_PutVal(0xb);
	}
	else if(x==10){
			Bits2_PutVal(0xd);
		}
	else{
		Bits2_PutVal(0xe);
	}
}
void Disp(number)
{
	
		 	
		  		  th1=1000;
		  		  
		  		  do{
		  		  temp=number/th1;
		  		  trigger(th1);
		  		  SevSeg(temp);
		  		  number=number%th1;
		  		  th1=th1/10;
		  		 for(j=0;j<0x7ff;j++);
		  		  }while(th1>=1);
		  
	
		 
}

int clock_fun(mm,ss){
	
	
	if(ss>58){
		ss=0;
		if(mm>58)
			mm=0;
		else
			mm=mm+1;
		
	}
	else
		ss=ss+1;
	c = mm*100+ss;
	 Disp(c);
	 return c;
	 
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
 mm=0;
 ss=0;
 z=0;
  while(1)
  {
	  if(Bit1_GetVal()==0){
		  if(ss>58){
			  ss=0;
		  }
		  else
		  ss=ss+1;
		  z=mm*100+ss;
		 for(i=0;i<100;i++){
			 Disp(z);
		 }
	  }
	  if(Bit2_GetVal()==0){
		  if(mm>58){
			  mm=0;
			  
		  }
		  else
			  mm=mm+1;
		   z=mm*100+ss;
		  	  
		   for(i=0;i<100;i++){
		  	Disp(z);
		  	  }
		 
	  }
	  
	  if(Bit3_GetVal()==0){
		  flag=1;
		 
	  }
	  if(flag==1){
		  for(i=0;i<100;i++){
		  			  z=clock_fun(mm,ss);
		  		  }mm=z/100;
		  		  ss=z%100;
	  }
	  if(flag==0){
		  
			  Disp(z);
		  
	  }
	  
	  
	  		  
	  		  
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
