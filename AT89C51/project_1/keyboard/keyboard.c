#include <REGX51.H>
#include <intrins.h>
unsigned char led[]={0xc0,0xf9,0xa4,0xb0,0x99,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char i,k,p;
void delay1ms1(unsigned int i);
char scan_key ( )
{
  unsigned char temp,result=-1;
	P0=0xff;
  P0=0xf0;
  temp=P0; 
  if(temp!=0xf0) 
   { 
    delay1ms1(5); 
    if(temp!=0xf0)
     { 
      P0=0xfe;
      temp=P0;
      switch(temp) 
       { 
	     case(0xee):result='0';break; 
	     case(0xde):result='1';break; 
	     case(0xbe):result='2';break; 
	     case(0x7e):result='3';break; 
       }

     P0=0xfd;
     temp=P0;
     switch(temp) 
       { 
	     case(0xed):result='4';break; 
	     case(0xdd):result='5';break; 
	     case(0xbd):result='6';break; 
	     case(0x7d):result='7';break; 
       }

     P0=0xfb;
     temp=P0;
     switch(temp) 
       { 
	     case(0xeb):result='8';break; 
	     case(0xdb):result='9';break; 
	     case(0xbb):result='A';break; 
	     case(0x7b):result='B';break; 
       }

     P0=0xf7;
     temp=P0;
     switch(temp) 
       { 
	     case(0xe7):result='C';break; 
	     case(0xd7):result='D';break; 
	     case(0xb7):result='E';break; 
	     case(0x77):result='F';break; 
       } 
   } 
 } 
 return result;
}
void delay1ms1(unsigned int i)
{
   unsigned char j;
   while(i--)
     {
	  for (j=0;j<114;j++);
	 }
}
void main()
{
	char i,p;
  while(1)
	{
		i=scan_key();
		if(i==-1)continue;
else
		{
		  switch(p)
			{
			  case 0:P2=led[i-'0'];break;
				case 1:P2=led[i-'0'];break;
				case 2:P2=led[i-'0'];break;
				case 3:P2=led[i-'0'];
			}
		}
	}
}


