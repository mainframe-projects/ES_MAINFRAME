/****************************************************************
*
* void RUN_7920(int UNIT)
*
****************************************************************/
#include "ds360opt.h"
#include <stdio.h>
#include <dos.h>
#include <io.h>
#include <\sys\stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>
#include <mem.h>

#include "ds360psw.h"

#include "ds360dfn.h"

//#include "ds360trn.h"


void RUN_7920(int UNIT)
{
 static int flag_reader_open=0;
 static int RDFILE;
 static int RE;
 static unsigned long CAW;
 static char BUFER[80];
 static unsigned long ar;
 static int i;
 static char CHAR;

 /****************************************************************
	ชฎฌ ญค  ็โฅญจ๏ กใไฅเ 
	1 ก ฉโ  
			 7D ชซ ขจ่  ขขฎค
			 F1 ชซ ขจ่  F1
			 ..
			 F9 ชซ ขจ่  F9
			 7A ชซ ขจ่  F10
			 7B         F11
			 7C         F12
			 6C         PD1
			 6E         PD2
			 6B         PD3
			 6D         CLEAR
	2 ก ฉโ   
	1 ก ฉโ  
	1 ก ฉโ  
	
	.....
 *****************************************************************
 ็โฅญจฅ ฌฎคจไจๆจเฎข ญญฎฃฎ
 1 ก ฉโ  
 2 ก ฉโ   
 1 ก ฉโ 
 1 ก ฉโ  คเฅแ  โเจกใโ 
    ( )
 *****************************************************************
 ง ฏจแ์ จ แโจเ ญจฅ ง ฏจแ์

 ****************************************************************/
 switch(CSW_COD[UNIT])
	 {
		case 0x01:
									/*               */
				RUN_7920_WR(CSW_ADRESS[UNIT],CSW_COUNT[UNIT],UNIT);
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				//tt(UNIT);
				break;

		case 0x05:    /*  _*/
				RUN_7920_CLWR(CSW_ADRESS[UNIT],CSW_COUNT[UNIT],UNIT);
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				//tt(UNIT);
				break;

		case 0x02:    /*      */
				RUN_7920_RD(CSW_ADRESS[UNIT],CSW_COUNT[UNIT],UNIT);
				IO_STATUS[UNIT][1]=U4|U5;
				//tt(UNIT);
				break;

		case 0x06:    /*   */

				RUN_7920_RDMD(CSW_ADRESS[UNIT],CSW_COUNT[UNIT],UNIT);
				IO_STATUS[UNIT][1]=U4|U5;
				//tt(UNIT);
				break;

		case 0x07:    /*             */
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				tt(UNIT);
				break;

		case 0x1f:    /*    */
				RUN_7920_CLNZ(CSW_ADRESS[UNIT],CSW_COUNT[UNIT],UNIT);
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				tt(UNIT);
				break;

		case 0x0b:
				//putchar(7);
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				//tt(UNIT);
				break;
		case 0x03:   /* X X   */
				IO_STATUS[UNIT][1]=U4|U5;
				tt(UNIT);
				break;
		case 0x04:   /*     */
				for(i=0,ar=CSW_ADRESS[UNIT];i<1;i++,ar++)
						{
						 PUT_BYTE(ar,IO_STATUS[UNIT][2]);
						}
				IO_STATUS[UNIT][2]=0;
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				tt(UNIT);
				break;

		default:
				CSW_COUNT[UNIT]=0;
				IO_STATUS[UNIT][1]=U4|U5;
				tt(UNIT);
				break;
		}

}
