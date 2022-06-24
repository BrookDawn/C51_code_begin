#include <REGX51.H>

sbit k1=P3^2;
sbit k2=P3^3;

unsigned char Tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0xf8,0x80,0x90};
unsigned char xx;

void int0(void)interrupt 0
{
  xx++;
	if(xx==100)
		xx=0;
}

void int1(void)interrupt 2
{
  xx--;
	if(xx==100)
		xx=0;
}


void delaylms(unsigned int i)
{
  unsigned char j;
	while(i--)
	{
	  for(j=0;j<125;j++);
	}
}

void Display(unsigned char x)
{
  P2=0xfe;
	P1=Tab[x/10];
	delaylms(5);

	P1=0xff;
	P2=0xfd;
	P1=Tab[x%10];
	delaylms(5);
	P1=0xff;
	delaylms(5);
}
void main()
{
  EA=1;
	EX0=1;
	EX1=1;
	
	IT0=1;
	IT1=1;
	
	xx=0;
	while(1)
	{
    Display(xx);	
	}
}


