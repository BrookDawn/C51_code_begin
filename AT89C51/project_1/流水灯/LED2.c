#include<reg51.h>
void delay()
{
  unsigned int i;
	for (i=0;i<20000;i++)
	{}
}

void main ()
{
  unsigned char index,LED;
	SCON=0;
	while(1)
	{
	  LED=0x7f;
		for(index=0;index<8;index++)
		{
		  SBUF=LED;
			do{} while (!TI);
				LED=((LED>>1)|0x80);
				delay();
		}
	}
}