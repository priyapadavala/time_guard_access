#include <LPC21xx.h>

#include "mini_proj_declar.h"
#include "types.h"

#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)
#define PREINT_VAL ((PCLK/32768)-1)
#define PREFRAC_VAL (PCLK - ((PREINT_VAL+1)*32768))


s8 week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

void init_rtc()
{
	//VPBDIV=0X00;
	//reset clock tick counter using CCR 
	CCR = 1<<1;
	//set 1 second tick rate
	PREINT =456;//PREINT_VAL;//456;
	PREFRAC =25024;//PREFRAC_VAL;//25024;
	//enable the clock
	CCR = 1<<0 | 1<<4;
	
	
	
	
	HOUR = 16;
	MIN = 51;
	SEC = 50;
	DOM = 24;
	MONTH = 11;
	YEAR = 2025;
	DOW = 1;
}
void run_rtc()
{
	lcdcmd(0x01);
	//while(1)
	do
		{
		lcdcmd(0x80);
		lcddata((HOUR/10)+48);
		lcddata((HOUR%10)+48);
		lcddata(':');
		lcddata((MIN/10)+48);
		lcddata((MIN%10)+48);
		lcddata(':');
		lcddata((SEC/10)+48);
		lcddata((SEC%10)+48);
		
		lcdcmd(0x80+10);
		lcdstr((u8 *)week[DOW]);
		
		lcdcmd(0xc0);
		lcddata((DOM/10)+48);
		lcddata((DOM%10)+48);
		lcddata('/');
		lcddata((MONTH/10)+48);
		lcddata((MONTH%10)+48);
		lcddata('/');
		lcdnum(YEAR);
	
		
	}while(ColScan()==1);
}
