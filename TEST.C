#include <stdio.h>
#include <math.h>
void SR(unsigned long *RR1,unsigned long *RR1_PLUS_1,
				unsigned long *RR2,unsigned long *RR2_PLUS_1)
 {

	static int FLA;
	(*RR1_PLUS_1)-=(*RR2_PLUS_1);
	FLA=_FLAGS;
	(*RR1)-=(*RR2);
	if (FLA&0x0001) (*RR1)-=1;


 }

void MR(unsigned long *RR1,unsigned long *RR1_PLUS_1,unsigned long *MN_MN)
 {
	static unsigned long rr1;
	static unsigned long rr1_plus_1;
	static unsigned long URREZ;
	static unsigned long URREZ2;
	static unsigned long URREZ3;
	static unsigned long URREZ4;
	static int SIGN1,SIGN2;
	SIGN1=0;SIGN2=0;
	if (((signed long)*MN_MN)<0)
		 {SIGN2=1;
			*MN_MN=-(*MN_MN);
		 }
	if (((signed long)*RR1_PLUS_1)<0)
		 {SIGN1=1;
			rr1_plus_1=-(*RR1_PLUS_1);
		 }
	else
		 {rr1_plus_1=*RR1_PLUS_1;
		 }
				URREZ4  = ((rr1_plus_1) >>16)  * ((*MN_MN)>>16);

				URREZ   = ((rr1_plus_1) >>16)  * ((*MN_MN)&0xffff);
				URREZ2  = ((rr1_plus_1)&0xffff)* ((*MN_MN)>>16);
				URREZ4 += URREZ >>16;
				URREZ4 += URREZ2>>16;
				URREZ3  = (0xffff&(rr1_plus_1))* (0xffff&(*MN_MN));
				URREZ   = (0xffff&URREZ)+(0xffff&URREZ2)+(URREZ3>>16);
				rr1     = URREZ4+(URREZ>>16);
				rr1_plus_1=(URREZ<<16)+(URREZ3&0xffff);
	if ( ((SIGN1==0) && (SIGN2==1)) ||
			 ((SIGN1==1) && (SIGN2==0))
		 )
		 {*RR1=0;*RR1_PLUS_1=0;
			SR(RR1,RR1_PLUS_1,&rr1,&rr1_plus_1);
		 }
	else
		 {*RR1=rr1;*RR1_PLUS_1=rr1_plus_1;
		 }
 }

void DR(unsigned long *RR1,unsigned long *RR1_PLUS_1,unsigned long *DEL_DEL)
	{
	 static unsigned long rr1;
	 static unsigned long rr1_plus_1;
	 static unsigned long del_del;
	 static int SIGN1,SIGN2;
	 static long double F_R1_R2;
	 static long double F_DEL_DEL;
	 static unsigned long r0;
	 static unsigned long r0_plus_1;
	 static unsigned long r2;
	 static unsigned long r2_plus_1;
	 static unsigned long r3;
	 static unsigned long r3_plus_1;
	 SIGN1=0;SIGN2=0;
	 if (((signed long)*DEL_DEL)<0)
		 {SIGN2=1;
			del_del=-(*DEL_DEL);
		 }
	 else del_del=*DEL_DEL;
	 if ((*RR1)&0x80000000)
		 {SIGN1=1;
			rr1=0;rr1_plus_1=0;
			SR(&rr1,&rr1_plus_1,RR1,RR1_PLUS_1);
		 }
	 else
		 {rr1=*RR1;rr1_plus_1=*RR1_PLUS_1;
		 }
	 if (rr1==0)
		{
		 rr1=rr1_plus_1%del_del;
		 rr1_plus_1/=del_del;
		}
	 else

		{
		 F_R1_R2=((long double)rr1)/(long double)del_del*4096.0*4096.0*256.0+
						 ((long double)rr1_plus_1)/(long double)del_del;
		 r0_plus_1=F_R1_R2;r0=0;
		 if (r0_plus_1>0) r0_plus_1--;
		 r2=r0;r2_plus_1=r0_plus_1;
		 MR(&r2,&r2_plus_1,&del_del);
		 SR(&r2,&r2_plus_1,&rr1,&rr1_plus_1);
		 if (r2&0x80000000)
			 {
				r3=0;r3_plus_1=0;
				SR(&r3,&r3_plus_1,&r2,&r2_plus_1);
			 }
		 else
			 {r3=r2;r3_plus_1=r2_plus_1;
			 }
		 rr1=r0_plus_1+r3_plus_1/del_del;
		 rr1_plus_1=r3_plus_1%del_del;
		}

	 if ( ((SIGN1==0) && (SIGN2==0)))
		 {*RR1=rr1;*RR1_PLUS_1=rr1_plus_1;
		 }
	 else if ( ((SIGN1==0) && (SIGN2==1)))
					{*RR1=rr1;*RR1_PLUS_1=-rr1_plus_1;
					}
				else if ( ((SIGN1==1) && (SIGN2==0)))
							 {*RR1=-rr1;*RR1_PLUS_1=-rr1_plus_1;
							 }
						 else
							 {*RR1=-rr1;*RR1_PLUS_1=rr1_plus_1;
							 }

	}



void PUT_WORD(unsigned long ADD,unsigned long W)
{static unsigned long A;
 A=ADD;
}
unsigned long GET_WORD(unsigned long ADD)
{
 static unsigned long A;
 A=ADD;
 return (A);
}
main()
{
 static int FLA;
 //static signed long R1;
 //static signed long R2;
 static int PSW_CC;
 static int PSW_PRG_MASK=0;
 static int RQ_PRG;
 static int RETURN;
 static unsigned long RR1;
 static unsigned long RR1_PLUS_1;
 static unsigned long DEL_DEL;
 static unsigned long MN_MN;
 static unsigned long R0;
 static unsigned long R0_PLUS_1;
 static long double MMM;
 static char MMMM[80];
 static long double *MM;
 static char far*P;
 static char far*PP;
 static unsigned long P_NN;
 static unsigned int  P_II;

 static char far *BIOS_AREA=0xf000fff0;
 static char offset_count[16]={2,7,4,8,3,9,4,5,9,12,8,6,5,14,8,1};
 static unsigned long all_count;
 static int i_count;

 static char RR;
 static char RX;
 static int R1,R2,B2,IS;


 static char BD;
 static char DD;
 static unsigned int DDD;
 static unsigned long ADRESS;

 static char COM[16]={0x12,0x34,0x56,0x78,0x9a};
 static unsigned long R[16];

#define B1 B2
#define I2 RX
#define X2 R2



 //RR1       =0x01234567;
 //RR1_PLUS_1=0x87654321;
 //R0=0;R0_PLUS_1=0;
 //SR(&R0,&R0_PLUS_1,&RR1,&RR1_PLUS_1);
 //RR1=R0;RR1_PLUS_1=R0_PLUS_1;
 //DEL_DEL     =0x10000000;
 //DR(&RR1,&RR1_PLUS_1,&DEL_DEL);
 //MMM= 1.;
 //MM=(long double*)MMMM;
 //*MM=MMM;
 //RR1=GET_WORD(0x3333l);
 //PUT_WORD(0x4444l,0x11l);
 //P=0x80007777;
 //P_NN=0x77774444;
 //PP=P+(0x000007ff&P_NN);
 //P_II=0x9;
 //PP=P+P_II;
	 //P_NN=0x00004567l;
	 //if (((P_NN^(P_NN+(unsigned long)6))&0x00fff800l)==0l)
	 //	 {P_NN=0;
	 //	 }
	 //
	 //if ((((P_NN+6)^P_NN)&0x00fff800l)==0l)
	 //	 {P_NN=0;
	 //	 }
	 //if ((((P_NN+(unsigned long)P_II)^P_NN)&0x00fff800l)==0l)
	 //	 {P_NN=0;
	 //	 }
	 //if (((((P_NN+6)^P_NN)<<8)>>19))
	 //	 {P_NN=0;
	 //	 }
	 //
	 //if (( ((unsigned int)P_NN^((unsigned int)P_NN+6))>>11)==0)
	 //	 {P_NN=0;
	 //	 }
	 //
	 //
	 //
	 //
	 //

//	 printf("\n");
//	 all_count=0;
//	 for(i_count=0;i_count<16;i_count++)
//		 {
//			all_count+=((unsigned long)(*BIOS_AREA))<<offset_count[i_count];
//			printf("%02x",(int)(*BIOS_AREA++));
//		 }
//	 printf("\n%08lx",all_count);
//
//
					 RR=COM[1];
					 R1=RR>>4;
					 R2=RR&0x0f;

					 _AL=COM[1];
					 _AH=0;
					 RR=_AL;
					 asm ror ax,4;
					 *(unsigned char *)(&R1)=_AL;
					 asm sar ax,12;
					 *(unsigned char *)(&R2)=_AL;

					 RR=COM[1];
					 *(unsigned char *)(&R1)=RR>>4;
					 *(unsigned char *)(&R2)=RR&0x0f;


RX=COM[1];

					 R1=RX>>4;
					 X2=RX&0x0f;
					 BD=COM[2];
					 B2=BD>>4;
					 if (X2) ADRESS=R[X2];else ADRESS=0;
					 if (B2) ADRESS+=R[B2];
					 ADRESS+=(unsigned long)(((BD&0x0f)<<8)+COM[3]);

_AL=COM[1];
					 _AH=0;
					 RX=_AL;
					 asm ror ax,4;
					 *(unsigned char *)(&R1)=_AL;
					 asm sar ax,12;
					 *(unsigned char *)(&X2)=_AL;
					 if (_AL) ADRESS=R[_AL]; else ADRESS=0;

					 _AL=COM[2];
					 BD=_AL;
					 asm ror ax,4;
					 *(unsigned char *)(&B2)=_AL;
					 if (_AL)
							{asm sar ax,4;
							 _AL=COM[3];
							 ADRESS+=(unsigned long)_AX+R[B2];
							}
					 else
							{asm sar ax,4;
							 _AL=COM[3];
							 ADRESS+=(unsigned long)_AX;
							}


_AL=COM[1];
					 _AH=0;
					 RX=_AL;
					 asm ror ax,4;
					 *(unsigned char *)(&R1)=_AL;
					 asm sar ax,12;
					 *(unsigned char *)(&X2)=_AL;
					 if (_AL) ADRESS=R[_AL]; else ADRESS=0;

					 _AX=*(unsigned int*)(&COM[2]);
					 if (_AL & 0xf0)
						 {_BL=_AL;
							asm xchg ah,al;
							_BH=0;
							asm sar bx,4;
							*(unsigned char *)(&B2)=_BL;
							ADRESS+=(unsigned long)(_AX&0x0fff)+R[_BX];
						 }
					 else
						 {
							asm xchg ah,al;
							ADRESS+=(unsigned long)_AX;
							B2=0;
						 }

#define GET_OPERAND_SI RX=COM[1];\
					 R1=RX>>4;\
					 X2=RX&0x0f;\
					 BD=COM[2];\
					 B2=BD>>4;\
					 if (B2) ADRESS=R[B2];else ADRESS=0;\
					 ADRESS+=(unsigned long)(((BD&0x0f)<<8)+COM[3]);

/*
#define GET_OPERAND_SS RX=COM[1];\
					 L1=RX>>4;\
					 L2=RX&0x0f;\
					 BD=COM[2];\
					 B1=BD>>4;\
					 ADRESS1=(((BD&0x0f)<<8)+COM[3]);\
					 if (B1) ADRESS1+=R[B1];\
					 BD=COM[4];\
					 B2=BD>>4;\
					 ADRESS2=(((BD&0x0f)<<8)+COM[5]);\
					 if (B2) ADRESS2+=R[B2];

 */




// R1=0x40000001;
// R2=R1;
// R1+=R2;
//				FLA=_FLAGS;
//				if (FLA&0x0040)  /*==0*/   PSW_CC=0;
//				else
//				 {if (FLA&0x0080) /*<0*/   PSW_CC=1;
//					else            /*>0*/   PSW_CC=2;
//				 }
//				if (FLA&0x0800)   /* PEREPOLNENIE*/ PSW_CC=3;
//
//				if (PSW_CC==3)
//					{
//					 if (PSW_PRG_MASK&0x8) {RQ_PRG=0x0008;RETURN=1;}
//					}

}