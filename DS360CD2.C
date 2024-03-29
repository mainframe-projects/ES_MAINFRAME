#include "ds360opt.h"
#include <stdio.h>
#include <dos.h>
#include <io.h>
#include <\sys\stat.h>
#include <fcntl.h>
#include <math.h>

#include "ds360psw.h"
#include "ds360dfn.h"

void CODE20(char far *COM)
{static char RR;
 static char RX;
 static int R1,R2,B2,IS;


 static char BD;
 static char DD;
 static unsigned int DDD;

 static signed long *RR1;
 static signed long *RR2;
 static long *REZ;
 static long RREZ;
 static unsigned long URREZ;
 static unsigned long *URR1;
 static unsigned long *URR2;
 static unsigned long ADRESS;
 static int i,j;
#define B1 B2
#define I2 RX
#define X2 R2

 GET_OPERAND_RR;
 FORWARD_PSW;
 switch(COM[0])
	 {
		case 0x20:          		           /* LPDR */
																			 /* �������� �窠
																			 ����㧪� ������⥫쭠�
																			 㤢������ �筮���
																			 */
				///T();
				PSW_CC=2;
				R_FLOAT[R1]=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else  ((char *)R_FLOAT[R1])[9]|=0x80;
				///T();
				break;

		case 0x21:                         /* LNDR */
																			 /*
																			 ����㧪� ����⥫쭠�
																			 㤢������ �筠���
																			 */

				///T();
				PSW_CC=1;
				R_FLOAT[R1]=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else ((char *)R_FLOAT[R1])[9]|=0x80;
				///T();
				break;

		case 0x22:                         /* LTDR */
																			 /*
																			 ����㧪� � �஢�ઠ 㤢������
																			 �筮��
																			 */
				R_FLOAT[R1]=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;
				//T();
				break;

		case 0x23:                         /* LCDR */
																			 /*
																			 ����㧪� ����������� 㤢������
																			 �筮��
																			 */

				///T();
				R_FLOAT[R1]=-R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;

				///T();
				break;

		case 0x24:                         /* HDR  */
																			 /*
																			 ������� ��ன ���࠭� �������
																			 ������� � ����頥���
																			 �� ���� ��ண�
																			 */
				///T();
				R_FLOAT[R1]=R_FLOAT[R2]/2.0;
				///T();
				break;

		case 0x25:                         /*  ����।������ ��� ����樨 */
				T();
				break;

		case 0x26:                         /* ��� */
				T();
				break;

		case 0x27:                         /* ��� */
				T();
				break;

		case 0x28:                         /* LDR */
																			 /*����㧪� 㤢������ �筮���
																			 */
				R_FLOAT[R1]=R_FLOAT[R2];
				//T();
				break;

		case 0x29:                         /* CDR */
																			 /*
																			 �ࠢ����� 㤢������ �筮���
																			 */
				///T();
				if (R_FLOAT[R1]==R_FLOAT[R2]) PSW_CC=0;
				else if (R_FLOAT[R1]<R_FLOAT[R2]) PSW_CC=1;
						else PSW_CC=2;
				///T();
				break;

		case 0x2a:                         /* ADR */
																			 /* ᫮����� � ��ଠ����樥�
																			 㤢������ �筠���
																			 */
				R_FLOAT[R1]+=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;
				//T();
				break;

		case 0x2b:                         /* SDR */
																			 /*
																			 ���⠭�� � ��ଠ����樥�
																			 㤢������ �筮���
																			 */
				R_FLOAT[R1]-=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;
				//T();
				break;

		case 0x2c:                         /* MDR  */
																			 /*
																			 㬭������ 㤢������ �筮���
																			 */
				///T();
				R_FLOAT[R1]*=R_FLOAT[R2];
				///T();
				break;
		case 0x2d:                         /* DDR  */
																			 /*
																			 ������� 㤢������ �筮���
																			 */
				///T();
				if (R_FLOAT[R2]==0.0)
					{RQ_PRG=0x000f;RETURN=1;return;
					}
				else R_FLOAT[R1]/=R_FLOAT[R2];
				///T();
				break;
		case 0x2e:                         /*  AWR */
																			 /*
																			 ᫮����� ��� ��ଠ����樨
																			 㤢������ �筮���
																			 */
				///T();
				R_FLOAT[R1]+=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;
				///T();
				break;
		case 0x2f:                         /*  SWR */
																			 /*
																			 ���⠭�� ��� ��ଠ����樨
																			 㤢������ �筮���
																			 */
				R_FLOAT[R1]-=R_FLOAT[R2];
				if (R_FLOAT[R1]==0.0) PSW_CC=0;
				else if (R_FLOAT[R1]<0.0) PSW_CC=1;
						else PSW_CC=2;
				//T();
				break;
	 }
}
#undef B1
#undef I2
#undef X2
