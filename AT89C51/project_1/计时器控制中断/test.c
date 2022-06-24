#include <REGX51.H>

unsigned char count=0;
unsigned char miao=0;

void timer_1() interrupt 3
{
  TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	count++;
	if(count==20)
	{
	  count=0;
		miao++;
		if(miao==100)miao=0;
	}
}

void disp(unsigned char i)
{
  unsigned char j;
	unsigned char led[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	P1=0xff;
	P2=0xfe;
	P1=led[i/10];
	for (j=0;j<100;j++);
	
	P1=0xff;
	P2=0xfd;
	P1=led[i%10];
	for (j=0;j<100;j++);
}

void main()
{
  TMOD=0X10;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	ET1=1;
	EA=1;
	TR1=1;
	while(1)
	{
	  disp(miao);
	}
}