#include <REGX51.H>

unsigned char LEDNum;


void delay(unsigned int xms)
{
   unsigned char i,j;
	while (xms--)
  { 
		i=2;
	  j=239;
	do{
	while(--j);
	  }while(--i);
  }
}

void main()
{
  while(1)
	{
	  if(P3_1==0)
		{
		  delay(20);
			while(P3_1==0);
			delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			{
			  LEDNum=0;
			}
			 P2=~(0x01<<LEDNum);//���Ʋ�������
		}
		
	}
}