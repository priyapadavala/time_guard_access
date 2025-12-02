#ifndef __MINI_PROJ_DECLAR_H_
#define __MINI_PROJ_DECLAR_H_
#include "types.h"
#include "delay.h"
void init_rtc(void);
void lcdcmd(unsigned char mycmd);
void lcddata(unsigned char mydata);
void initlcd(void);
void lcdnum(unsigned int n);
void lcdstr(char *ptr);
void run_rtc(void);
void Init_Kpm(void);
u32 ColScan(void);
u32 RowCheck(void);
u32 ColCheck(void);
u32 KeyScan(void);
void password(void);
void enit0_isr(void) __irq;
void init_int(void);
void print_menu(void);
void Edit_rtc_info(void);
void change_pass(void);
void edit_log(void);
#include <string.h>
#endif


