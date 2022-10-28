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
#include "Bits1.h"
#include "BitsIoLdd3.h"
#include "RS.h"
#include "BitIoLdd1.h"
#include "RW.h"
#include "BitIoLdd2.h"
#include "EN.h"
#include "BitIoLdd3.h"
#include "Set.h"
#include "BitIoLdd4.h"
#include "Inc.h"
#include "BitIoLdd5.h"
#include "Dec.h"
#include "BitIoLdd6.h"
#include "Run.h"
#include "BitIoLdd7.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


/* User includes (#include below this line is not maintained by Processor Expert) */
int k,w,j,i,x,y,z,count=0,hh=0,mm=0,ss=0,h1=0,h2=0,temp=0,m1=0,m2=0,temp1=0,s1=0,s2=0,temp2=0,flag=0,run_flag=0,temp3=0,temp4=0,temp5=0,temp6=0;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
void Lcd_Delay(unsigned char Delay)
{
	
	for(w=0;w<Delay;w++)
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


int Set(count){
	
	if(count==1){
		Lcd_command(0x80);
		Lcd_Data('0');
		
		return count;
		
	}
	else if(count==2){

		Lcd_command(0x83);
		Lcd_Data('0');
		
		return count;
}
	else if (count==3){
		Lcd_command(0x86);
		Lcd_Data('0');
		return count;
	}
		
		else if(count==4)
		{
			Run(hh,mm,ss);
			count = 0;
		  return count;
		}
	
		
		
			
			
		
	
}
int Inc_H(hh)
{
	 
	 if(hh<24){
		 h1=hh%10;
		 h1=h1+48;
		 Lcd_command(0x81);
		 Lcd_Data(h1);
		 h2=hh/10;
		 h2=h2+48;
		 Lcd_command(0x80);
		 		 Lcd_Data(h2);
		 		 hh=hh+1;
		 		 if(hh>=23)
		 			 hh=0;
		 		 return hh;
	 }
	 else{
		 hh=0;
		 return hh;
	 }
		 		  
	 
	
}
int Dec_H(hh)
{
	 
	 if(hh>=1){
		 hh=hh-1;
		 h1=hh%10;
		 h1=h1+48;
		 Lcd_command(0x81);
		 Lcd_Data(h1);
		 h2=hh/10;
		 h2=h2+48;
		 Lcd_command(0x80);
		 		 Lcd_Data(h2);
		 		 return hh;
		 		 
	 }
	 else{
		 hh=24;
		 return hh;
	 }
		 		  
	 
	
}
int Inc_M(mm)
{
	 if(mm<60){
			 m1=mm%10;
			 m1=m1+48;
			 Lcd_command(0x84);
			 Lcd_Data(m1);
			 m2=mm/10;
			 m2=m2+48;
			 Lcd_command(0x83);
			 		 Lcd_Data(m2);
			 		 mm=mm+1;
			 		 return mm;
		 }
		 else{
			 mm=0;
			 return mm;
		 }

}
int Dec_M(mm)
{
	 if(mm>=1){
			 mm=mm-1;
			 m1=mm%10;
			 m1=m1+48;
			 Lcd_command(0x84);
			 Lcd_Data(m1);
			 m2=mm/10;
			 m2=m2+48;
			 Lcd_command(0x83);
			 		 Lcd_Data(m2);
			 		 return mm;
			 		 
		 }
		 else{
			 mm=60;
			 return mm;
		 }


}

int Inc_S(ss)
{
	 
	 if(ss<60){
				 s1=ss%10;
				 s1=s1+48;
				 Lcd_command(0x87);
				 Lcd_Data(s1);
				 s2=ss/10;
				 s2=s2+48;
				 Lcd_command(0x86);
				 		 Lcd_Data(s2);
				 		 ss=ss+1;
				 		 return ss;
			 }
			 else{
				 ss=0;
				 return ss;
			 }

}


int Dec_S(ss)
{
	 
	 if(ss>=1){
				 ss=ss-1;
				 s1=ss%10;
				 s1=s1+48;
				 Lcd_command(0x87);
				 Lcd_Data(s1);
				 s2=ss/10;
				 s2=s2+48;
				 Lcd_command(0x86);
				 		 Lcd_Data(s2);
				 		 return ss;
				 		 
			 }
			 else{
				 ss=60;
				 return ss;
			 }

}
void Run(hh,mm,ss)
{
		 for(i=hh;i<24;i++){
			 Inc_H(i);
			  Lcd_Delay(10);
			 for(j=mm;j<60;j++){
				 Inc_M(j);
				  Lcd_Delay(10);
				 for(k=ss;k<60;k++){
				 			
				 					  Inc_S(k);
				 					  Lcd_Delay(15);
				 					 
				 				 }
				  
				 ss=0;
			 }
			 mm=0;
			 if(i>=23){
				 i=-1;
				 
			 }
				 
		 }
		 
		 
		
				 
			 
		 
}
	  

void Alpha()
{
	if(Set_GetVal()==0)
		{ 
		    count++;	 
		    flag=count;
		    count = Set(count);
		  
		}
		

	if(Inc_GetVal()==0)
		{ 
		     if(flag==1)
		     {
		    	 temp1= Inc_H(temp1);
		    	 hh=temp1;
		    	
		     }
		     else if(flag==2)
		    		     {
		    		    	temp2=Inc_M(temp2);
		    		    	mm=temp2;
		    		     }
		     else if(flag==3)
		    		     {
		    		    	temp3=Inc_S(temp3);
		    		    	ss=temp3;
		    		     }
		     
		}
	if(Dec_GetVal()==0)
			{ 
			     if(flag==1)
			     {
			    	 temp1=Dec_H(temp1);
			    	 hh=temp1;
			    	
			     }
			     else if(flag==2)
			    		     {
			    		    	temp2=Dec_M(temp2);
			    		    	mm=temp2;
			    		     }
			     else if(flag==3)
			    		     {
			    		    	temp3=Dec_S(temp3);
			    		    	ss=temp3;
			    		     }
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
  Lcd_puts("00:00:00");
while(1)
{

  /* Write your code here */
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
