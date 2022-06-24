#include<reg51.h>
#include<intrins.h>
unsigned char code led[]={0xb0,0x80,0xb0,0xc0,0xc0,0x82};
unsigned char i,j;
void delaylms(unsigned int i)
{
  unsigned int x;
  while(i--)	
  {
	for(x=0;x<120;x++);
	}
}

void main()
{		
	  j=0xfe;
	for(i=0;i<6;i++)
	{
	  P1=0xff;
		P3=j;
		j=_crol_(j,1);
	  P1=led[i];
		delaylms(2);
	}
}

