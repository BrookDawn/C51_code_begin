#include<reg51.h>
sbit Left=P2^1;
sbit Right=P2^0;
void delaylms(unsigned int n)
{
	unsigned char j;
	while(n--)
	{
	  for(j=0;j<120;j++)
		{
			
		}
	}
}
void main()
{
	while(1)
  {
		   if(Left==0 && Right==0)
		 {
		   P0=0xFC;
		   delaylms(200);
		   P0=0xFF;
		   delaylms(200);
			 break;
		 }
  if(Left==0)
	 {
	  P0=0xFE;
		delaylms(200);
		P0=0xFF;
		delaylms(200);
		break;
	 }
	 if(Right==0)
	   {
	     P0=0xFD;
		   delaylms(200);
		   P0=0xFF;
		   delaylms(200);
			 break;
	   }

   }
 }