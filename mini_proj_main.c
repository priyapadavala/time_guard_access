#include <LPC21xx.h>
#include "mini_proj_declar.h"

int main()
{
	initlcd();
	init_rtc();
	Init_Kpm();
	init_int();
	while(1)
	{
	run_rtc();
	password();
	}
	//run_rtc();
 
 	
		//HOUR=14;
		 
		//	run_rtc();
	//while(1);
	
	
}
