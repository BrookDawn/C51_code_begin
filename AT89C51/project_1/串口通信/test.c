#include<reg51.h>
#include<intrins.h>
code unsigned char tab[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char buffer[]={0x00,0x00,0x00,0x00,0x00,0x00};
void disp(void);
unsigned char index=0,flag=0;

void Uart_SendString(unsigned char *Buffer)
{
  unsigned char j=0;
	while (Buffer[j]!=0x00)
	{
	  SBUF=Buffer[j];
		while(!TI);
		TI=0;
		j++;
	}
}

void disp()
{
    //unsigned char w,i,j;
	  unsigned char w,i;
	  unsigned int j;
	
	  w=0xfe;				//??????0xfe
    for(i=0;i<6;i++)
      {
        P1=0xff;                   //???,??????0xff??
        P2=w;              		//???????P2?
        w=_crol_(w,1);		//???????,?????LED
        P1=tab[buffer[i]-'0']; // ??????????
				//P1=tab[buffer[i]];//Error
        for(j=0;j<600;j++);// ????
       }
}

void main()
{
  unsigned char i=0;
	unsigned int j;
	TMOD=0x20;
	EA=1;
	ES=1;
	
	TL1=0xfd;
	TH1=0xfd;
	
	SCON=0x40;
	REN=1;
	TR1=1;
	
	while(1)
	{
	  if(flag==1)
		{
		  disp();
		}
	}
}

void uart_receive(void) interrupt 4
{
  unsigned char dat;
	if(RI==1)
	{
	  RI=0;
		dat=SBUF;
		buffer[index]=dat;
		if(index>=6)
		{
		  flag=1;
			index=0;
		}
	}
}




