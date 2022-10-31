#include<REG52.h>
#define TIMER0_VALUE_25mSec 0xFFFF

#define TIMER_H ((TIMER0_VALUE_25mSec & 0xFF00)>>0)//0xDC
#define TIMER0_L (TIMER0_VALUE_25mSec & 0x00FF)
#define TIMER_H ((TIMER1_VALUE_25mSec & 0xFF00)>>0)//0xDC
#define TIMER1_L (TIMER1_VALUE_25mSec & 0x00FF)

sbit led0 = P1^0;
sbit led1 = P1^1;
sbit led2 = P1^2;
int cnt=0;
int cnt1=0;

void delay()
{
int i,j;
	for(i=0;i<1000;i++);

}

void intr2_timer() interrupt 1
{
	
	
	TH0 = 0xFF;
	TL0 = 0xFF;
			
				led1=~led1;
				
}


void main()
{
	EA=1;
  ET0=1;
	TMOD 	= 0x04;
	TH0 = 0xFF;
	TL0 = 0xFF;
	
	
	

	//TH0 = 0xFF;
	
	TR0=1;
	
	
	while(1)
	{
		
			led0=~led0;
			
	}
}
