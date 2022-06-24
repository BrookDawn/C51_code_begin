#include <REGX51.H>

unsigned char led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
 sbit K=P1^0;
void delaylms(unsigned int  i)
{
	unsigned char j;
	while(i--)
	{
    for (j=0;j<125;j++);
	}
}
void main()
{
	unsigned char i,w,k,j;
	P0=0xff;
	P2=0xff;
	while(1)
	{
		if(K==0 )
		{
		  delaylms(10);
			k++;
			if(K==0&& k%2==1)
			{
			  w=0x01;
				for(i=0;i<8;i++)
				{
				  P0=~w;
					delaylms(300);
					w<<=1;
				}
			}
      if(K==0 && k%2==0)
			 {
			  w=0x80;
				for(i=0;i<8;i++)
				{
				  P0=~w;
					delaylms(300);
					w>>=1;
				}
			 }
	   }	
		//第二部分
		 
		 		if(K==0 )
		{
		  delaylms(10);
			j++;
			if(K==0&& j%2==1)
			{
			  w=0x01;
				for(i=0;i<8;i++)
				{
				  P2=~w;
					delaylms(300);
					w<<=1;
				}
			}
      if(K==0 && j%2==0)
			 {
			  w=0x80;
				for(i=0;i<8;i++)
				{
				  P2=~w;
					delaylms(300);
					w>>=1;
				}
			 }
	   }	
		else P1=0x00;
   }
}
