#include <LPC21xx.h>
#include "mini_proj_declar.h"
void init_int()
{
	PINSEL0=(PINSEL0&~(3<<2))|(3<<2);
	VICIntEnable|=1<<14;
	VICVectCntl0=(1<<5)|14;
	VICVectAddr0=(u32)enit0_isr;
	EXTMODE|=1<<0;
	EXTPOLAR=0;
	IODIR0|=1<<23;
	
	
}
void enit0_isr(void) __irq
{
	
	IOSET0=1<<23;
	delay_ms(500);
	IOCLR0=1<<23;
	print_menu();
	EXTINT=1<<0;
	VICVectAddr=0;
	
	
}
