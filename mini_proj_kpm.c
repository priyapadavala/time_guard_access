//mini_proj_kpm.c
#include <LPC21xx.h>
#include "mini_proj_declar.h"
#include "mini_proj_defines.h"
u8 kpmLUT[4][4]={{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'C','0','=','+'}};
void Init_Kpm()
{
	//ROWS output and grounded
	IODIR1=15<<ROW0;
	//COLS input &high,any way default
}
u32 ColScan()
{
	u32 status;
	status=(((IOPIN1>>COL0)&15)<15)?0:1;
	return status;
}
u32 RowCheck()
{
	u32 r;
	for(r=0;r<=3;r++)
	{
		//starting with ROW0,upto ROW3
		//ground only one row keep other ROWS high
		IOPIN1=((IOPIN1&~(15<<ROW0))|(~(1<<r)<<ROW0));
		//check if key was pressed in that row
		if(ColScan()==0)
		{
			break;
		}
	}
	//reinitialize rows to their state
	IOCLR1=15<<ROW0;
	return r;
}
u32 ColCheck()
{
	u32 c;
	for(c=0;c<=3;c++)
	{
		//starting with col0 upto col3
		//check one col at a time for low
		if(((IOPIN1>>(COL0+c))&1)==0)
		{
			break;
		}
	}
	return c;
	
}
u32 KeyScan()
{
	u32 r,c,keyV;
	//Initialize kpm
	Init_Kpm();
	//wait for any key press detection
	while(ColScan());
	//upon key press detection,key is in pressed
	//identify row in which key way pressed
	r=RowCheck();
	//identify col in which key way pressed
	c=ColCheck();
	//extract the key values from lut
	keyV=kpmLUT[r][c];
	return keyV;
}

