#include<REG52.h>
#define TIMER0_VALUE_25mSec 0xA5FF
#define TIMER1_VALUE_25mSec 0xA5FF
#define TIMER_H ((TIMER0_VALUE_25mSec & 0xFF00)>>0)//0xDC
#define TIMER0_L (TIMER0_VALUE_25mSec & 0x00FF)
#define TIMER_H ((TIMER1_VALUE_25mSec & 0xFF00)>>0)//0xDC
#define TIMER1_L (TIMER1_VALUE_25mSec & 0x00FF)

sbit led0 = P1^0;
sbit led1 = P1^1;
sbit led2 = P1^2;
int cnt=0;
int cnt1=0;


void intr2_timer() interrupt 1
{
	
	cnt=cnt+1;
	TH0 = 0xA5;
	TL0 = 0xFF;
			if(cnt==40)
			{
				led1=~led1;
				
				cnt=0;
			}
		
}

void intr3_timer() interrupt 3
{
	
	cnt1=cnt1+1;
	TH1 = 0xA5;
	TL1 = 0xFF;
			if(cnt1==120)
			{
				led2=~led2;
				
				cnt1=0;
			}
		
}


void main()
{
	
	TMOD 	= 0x11;
	TH0 = 0xA5;
	TL0 = 0xFF;
	TH1 = 0xA5;
	TL1 = 0xFF;
	EA=1;
  ET0=1;
	ET1=1;

	//TH0 = 0xFF;
	
	TR0=1;
	TR1=1;
	
	while(1)
	{
		
			led0=~led0;
			
		
	}
}