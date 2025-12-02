#include <LPC21xx.h>
#include "mini_proj_declar.h"
u32 key,start=16,end=45;
u8 str2[7]="1234";
u8 str[7];
void pass()
{
	int i;
	for(i=0;i<4;i++)
	{
		key=KeyScan();
		lcddata(key);
		while(ColScan()==0);
		str[i]=key;
		
	}
	str[i]='\0';
}
void password()
{
	 
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcdstr("Enter Password:");
	lcdcmd(0xc0);
	pass();
	if(strcmp(str,str2)==0)
	{
	if(HOUR==start&&MIN<=end)
	{
		lcdcmd(0x01);
		lcdcmd(0x80);
		lcdstr("valid pass");	
		delay_ms(500);
	}
	else
	{
		lcdcmd(0x01);
		lcdstr("Access Denied");
		lcdcmd(0xc0);
		lcdstr("* ");
		lcdnum(start);
		lcdstr("H--to--");
		lcdnum(end);
		lcdstr("M");
		delay_ms(3000);
	}
    }
	else
	{
		lcdcmd(0x01);
		lcdstr("invalid pass");
		delay_ms(500);
		
	}
	
}
void print_menu()
{
	u32 key1;
	//lcdcmd(0x01);
	//lcdcmd(0x80);
	//lcdstr("1:E.INF 3:PWD.CHNG");
	//lcdcmd(0xc0);
	//lcdstr("2:E.END.TYM 4:EXIT");
	//key1=KeyScan();
	//while(ColScan()==0);
	lcdcmd(0x01);
	lcdstr("Enter Password");
	lcdcmd(0xc0);
	pass();
	if(strcmp(str,str2)==0)
	{
		while(1)
		{
	  lcdcmd(0x01);
	  lcdcmd(0x80);
	  lcdstr("1:E.INF 3:PWD.CHNG");
	  lcdcmd(0xc0);
	  lcdstr("2:E.END.TYM 4:EXIT");
	  key1=KeyScan();
		while(ColScan()==0);
		if(key1=='1')
		{
			Edit_rtc_info();
			lcdcmd(0x01);
		}
		else if(key1=='2')
		{
			edit_log();
			
		}
		else if(key1=='3')
		{
			change_pass();
			lcdcmd(0x01);
		}
		else if(key1=='4')
		{
			lcdcmd(0x01);
			break;
		}
	  }
	}
	else
	{
		lcdcmd(0x01);
		lcdstr("Invalid password");
		delay_ms(500);
		lcdcmd(0x01);
	}
}
void Edit_rtc_info()
{
	u32 key,cnt,num=0;
	while(1)
	{
	lcdcmd(0x01);
	lcdcmd(0x80);
	lcdstr("1:H 2:MIN 3:DATE");
	lcdcmd(0xc0);
	lcdstr("4:MNT 5:yr 6:ext");
	key=KeyScan();
	while(ColScan()==0);
	if(key=='1')
	{
		lcdcmd(0x01);
		lcdstr("Enter");
		lcdcmd(0xc0);
		lcdstr("&Hour=");
		cnt=0;
		num=0;
		while(cnt<2)
		{
			key=KeyScan();
			lcddata(key);
		    while(ColScan()==0);
			num=(num*10)+(key-48);
			cnt++;
			
		}
		HOUR=num;
		delay_ms(300);
		
	}
	else if(key=='2')
	{
		lcdcmd(0x01);
		lcdstr("Enter");
		lcdcmd(0xc0);
		lcdstr("&MINUTE=");
		cnt=0;
		num=0;
		while(cnt<2)
		{
			key=KeyScan();
			lcddata(key);
		    while(ColScan()==0);
			num=(num*10)+(key-48);
			cnt++;
			
		}
		MIN=num;
		 
		
	}
	else if(key=='3')
	{
		lcdcmd(0x01);
		lcdstr("Enter");
		lcdcmd(0xc0);
		lcdstr("&DATE=");
		cnt=0;
		num=0;
		while(cnt<2)
		{
			key=KeyScan();
			lcddata(key);
		    while(ColScan()==0);
			num=(num*10)+(key-48);
			cnt++;
			
		}
		DOM=num;
		
	}
	else if(key=='4')
	{
		lcdcmd(0x01);
		lcdstr("Enter");
		lcdcmd(0xc0);
		lcdstr("&MONTH=");
		cnt=0;
		num=0;
		while(cnt<2)
		{
			key=KeyScan();
			lcddata(key);
		  while(ColScan()==0);
			num=(num*10)+(key-48);
			cnt++;
			
		}
		MONTH=num;
	}
	else if(key=='5')
	{
		lcdcmd(0x01);
		lcdstr("Enter");
		lcdcmd(0xc0);
		lcdstr("&YEAR=");
		cnt=0;
		num=0;
		while(cnt<4)
		{
			key=KeyScan();
			lcddata(key);
		    while(ColScan()==0);
			num=(num*10)+(key-48);
			cnt++;
			
		}
		YEAR=num;
	}
	else if(key=='6')
	{
		break;
	}
 }
	 
}
void change_pass()
{
	u32 i;
	lcdcmd(0x01);
	lcdstr("enter new pass");
	lcdcmd(0xc0);
	for(i=0;i<4;i++)
	{
		key=KeyScan();
		lcddata(key);
		while(ColScan()==0);
		str2[i]=key;
		
	}
	str2[i]='\0';
	lcdcmd(0x01);
	lcdstr("pass updated");
	delay_ms(300);
	
}
void edit_log()
{
	u32 k,cnt=0,num=0;
	while(1)
	{
	lcdcmd(0x01);
	lcdstr("1:Start 2:End");
	lcdcmd(0xc0);
	lcdstr("3:Exit");
	k=KeyScan();
	while(ColScan()==0);
	if(k=='1')
	{
		lcdcmd(0x01);
		lcdstr("&Start[HOUR]:");
		lcdcmd(0xc0);
		cnt=0;
		num=0;
		while(cnt<2)
		{
			k=KeyScan();
			lcddata(k);
		    while(ColScan()==0);
			num=(num*10)+(k-48);
			cnt++;
			
		}
		start=num;
		
	}
	else if(k=='2')
	{
			lcdcmd(0x01);
		lcdstr("&End[MIN]:");
		lcdcmd(0xc0);
		cnt=0;
		num=0;
		while(cnt<2)
		{
			k=KeyScan();
			lcddata(k);
		    while(ColScan()==0);
			num=(num*10)+(k-48);
			cnt++;
			
		}
		end=num;
		
	}
	else if(k=='3')
	{
		//lcdcmd(0x01);
		break;
	}
	
	
	}
	
}
