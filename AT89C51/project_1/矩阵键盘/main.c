#include <REGX51.H>
#include <string.h>
#include "Keyborad.h"

unsigned char code Code[]="1234AB";
unsigned char Str[7];

void delay(unsigned int i)
{
  unsigned char j;
	while(i--)
	{
	  for(j=0;j<114;j++)
		{}
	}
}

void main()
{
  unsigned char p=0;
	unsigned char led[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	unsigned char led1[]={0xbf,0x8c,0x86};
	unsigned char i,k;
	
	Str[6]='\0';
	P2=led1[0];
	P0=0xff;
	while(1)
	{
	  i=scan_key();
		if(i==-1)continue;
		else
		{
			switch(p)
			{
		  case 0:Str[0]=i;p++;P2=led[i-'0'];delay(1000);break;
		  case 1:Str[1]=i;p++;P2=led[i-'0'];delay(1000);break;
		  case 2:Str[2]=i;p++;P2=led[i-'0'];delay(1000);break;
			case 3:Str[3]=i;p++;P2=led[i-'0'];delay(1000);break;
		  case 4:Str[4]=i;p++;P2=led[i-'0'];delay(1000);break;
			case 5:Str[5]=i;p++;P2=led[i-'0'];delay(1000);
			k=strcmp(Str,Code);
			if(k==0)
			{
			  P2=led1[1];
				delay(500);
				P2=led1[0];
			}
			else 
			{
			  P2=led1[2];
				delay(1000);
				P2=led1[0];
			}
			p=0;
			break;
		}
	 }
  }
}