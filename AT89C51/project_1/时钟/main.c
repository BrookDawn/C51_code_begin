#include<reg51.h>

unsigned char count=0;
unsigned char sec=45,min=59,hour=23;
void timer_1() interrupt 3 
{
  TH1=(65536-50000)/256;
  TL1=(65536-50000)%256;
  count++;
  if(count==20)
 {
count=0;
sec++;

  if(sec==60)
 {
  min++;
  sec=0;
  if(min==60)
   {
  hour++;
  min=0;
   }
if(hour==24)
     {
       hour=0;
     }
    }
  }
}
void disp(unsigned char sec,unsigned min,unsigned hour)
{
   unsigned char j;
   unsigned char led[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
   P1=0xff;
   P3=0xff;
   P2=0xef;
   P1=led[sec/10];
   for(j=0;j<100;j++);
 
   P1=0xff;
   P3=0xff;
   P2=0xdf;
   P1=led[sec%10];
   for(j=0;j<100;j++);

   P1=0xff;
   P3=0xff;
   P2=0xfe;
   P1=led[hour/10];
   for(j=0;j<100;j++);

   P1=0xff;
   P3=0xff;
   P2=0xfd;
   P1=led[hour%10];
   for(j=0;j<100;j++);

   P1=0xff;
   P3=0xff;
   P2=0xfb;
   P1=led[min/10];
   for(j=0;j<100;j++);

   P1=0xff;
   P3=0xff;
   P2=0xf7;
   P1=led[min%10];
   for(j=0;j<100;j++);
  }
void main()
{
   TMOD=0x10;
   TH1=(65536-50000)/256;
   TL1=(65536-50000)%256;
   ET1=1;
   EA=1;
   TR1=1;
 while(1)
  {

  disp(sec,min,hour);
  }
}