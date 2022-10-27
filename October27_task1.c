#include <reg51.h>

sbit led_main = P0^0;
sbit led_intr0 = P0^1;
sbit led_intr1 = P0^1;
#define LED0 P0
#define LED1 P1
#define LED2 P2
 
void delay()
{
int i,j;
	for(i=0;i<10000;i++){
for(j=0;j<1000;j++);
}
}
 void intr0_external() interrupt 0
{
	 int j;
	unsigned char a=0xff;
	unsigned char b=0x01;
	for(j=0;j<8;j++)
	{
		b=(b<<1);
		LED1=(a^b);
		delay();
	}	
}
		void intr1_external() interrupt 2
{
	int j;
	unsigned char a=0xff;
	unsigned char b=0x01;
	for(j=0;j<8;j++)
	{
		b=(b<<1);
		LED2=(a^b);
		delay();
}
}
main()
{
     EA=1;
     EX0=1;
	   IT0=1;
	   EX1=1;
	   IT1=1;
			PX1=1;

	 while(1)
	 {
	 int j;
	unsigned char a=0xff;
	unsigned char b=0x01;
	for(j=0;j<8;j++)
	{
		b=(b<<1);
		LED0=(a^b);
		delay();
	}	
	  
	 }
	 
}
	
	
	