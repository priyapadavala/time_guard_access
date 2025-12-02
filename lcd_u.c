//lcd_u.c(lcd difinations)
#include <LPC21xx.h>
#include "mini_proj_defines.h"
#include "delay.h"
#include "mini_proj_declar.h"
void lcdcmd(unsigned char mycmd)
{
	IOCLR0=1<<RS;//cmd mode 16=0(LOW)
	IOCLR0=1<<RW;//write mode RW=17=0(LOW)
	IOCLR0=255<<data;
	IOSET0=mycmd<<data; 
	IOSET0=1<<EN;
	delay_ms(2);
	//delay_lcd();
	IOCLR0=1<<EN;
	
	
}
void lcddata(unsigned char mydata)
{
	IOSET0=1<<RS;//data mode 16=1(HIGH)
	IOCLR0=1<<RW;//write mode RW=17=0(LOW)
	IOCLR0=255<<data;
	IOSET0=mydata<<data; 
	IOSET0=1<<EN;
	delay_ms(2);
	//delay_lcd();
	IOCLR0=1<<EN;
	
	
}
void initlcd(void)
{
	IODIR0|=2047<<8;
	lcdcmd(0x01);
	lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x06);
	//lcdcmd(0x01);
	lcdcmd(0x80);
	
}
void lcdnum(unsigned int n)
{
	unsigned char digit[10];
	int i=0;
	if(n==0)
	{
		lcddata('0');
	}
	else
	{
		while(n)
		{
			digit[i]=(n%10)+48;
			i++;
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			lcddata(digit[i]);
		}
	}
}

void lcdstr(char *ptr)
{
	int i;
	for(i=0;ptr[i];i++)
	{
		lcddata(ptr[i]);
		delay_ms(50);
	}
}
