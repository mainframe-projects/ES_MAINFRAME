
unsigned char EBCDIC_ASCII[256]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 00 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 10 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 20 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 30 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

' ' ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 40 */
0x00,0x00,'@' ,'.' ,'<' ,'(' ,'+' ,'|' ,

'&' ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 50 */
0x00,0x00,'!' ,'$' ,'*' ,')' ,';' ,'^' ,

'-' ,'/' ,0x00,0x00,0x00,0x00,0x00,0x00,       /* 60 */
0x00,0x00,0x00,',' ,'%' ,'_' ,'>' ,'?' ,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 70 */
0x00,0x00,':' ,'#' ,'@' ,'\'','=' ,'\"',

0x00,'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,       /* 80 */
'h' ,'i' ,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,       /* 90 */
'q' ,'r' ,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,       /* A0 */
'y' ,'z' ,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,'�' ,0x00,       /* B0 */
'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,

'{' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' ,'G' ,       /* C0 */
'H' ,'I' ,'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,

'}' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,       /* D0 */
'Q' ,'R' ,'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,

'\\',0x00,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,       /* E0 */
'Y' ,'Z' ,'�' ,'�' ,'�' ,'�' ,'�' ,'�' ,

'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,       /* F0 */
'8' ,'9' ,'�' ,'�' ,'�' ,'�' ,'�' ,0x00




};
unsigned char ASCII_EBCDIC[256]={

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 00 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* 10 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x40,0x5a,0x7f,0x7b,0x5b,0x6c,0x50,0x7d,//       /* 20 */
0x4d,0x5d,0x5c,0x4e,0x6b,0x60,0x4b,0x61,

0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,       /* 30 */
0xF8,0xF9,0x7a,0x5e,0x4c,0x7e,0x6e,0x6f,

0x7c,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,       /* 40 */
0xC8,0xC9,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,

0xD7,0xD8,0xD9,0xE2,0xE3,0xE4,0xE5,0xE6,       /* 50 */
0xE7,0xE8,0xE9,0x00,0x00,0x00,0x5f,0x6d,

0x00,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,       /* 60 */
0xC8,0xC9,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,

0xD7,0xD8,0xD9,0xE2,0xE3,0xE4,0xE5,0xE6,       /* 70 */
0xE7,0xE8,0xE9,0x00,0x4f,0x00,0x00,0x00,

0xc1,0xba,0xc2,0xbf,0xbc,0xc5,0xec,0xfa,       /* 80 */
0xcb,0xcc,0xd2,0xce,0xd4,0xc8,0xd6,0xdc,

0xd7,0xc3,0xe3,0xeb,0xbe,0xe7,0xbb,0xb6,       /* 90 */
0xfb,0xfd,0xee,0xef,0xee,0xfc,0xb8,0xdd,

0xc1,0xba,0xc2,0xbf,0xbc,0xc5,0xec,0xfa,       /* A0 */
0xcb,0xcc,0xd2,0xce,0xd4,0xc8,0xd6,0xdc,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* B0 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* C0 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* D0 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0xd7,0xc3,0xe3,0xeb,0xbe,0xe7,0xbb,0xb6,       /* E0 */
0xfb,0xfd,0xee,0xef,0x00,0xfc,0xb8,0xdd,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       /* F0 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00




};
