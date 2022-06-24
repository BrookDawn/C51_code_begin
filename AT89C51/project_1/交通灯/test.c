#include<reg51.h>

sbit S1=P3^2;
sbit S2=P3^3;
unsigned char t0,t1,xx;
void delay0_5s1()
{
for(t0=0;t0<10;t0++)
{
TH1=(65536-50000)/256;
TL1=(65536-50000)%256;
TR1=1;
while(!TF1);
TF1=0;
}
}
void delay_t1(unsigned char t)
{
for(t1=0;t1<t;t1++)
delay0_5s1();
}


void main()
{

EA=1;
EX0=1;
EX1=1;
IT0=1;
IT1=1;
xx=0;
while(1){


P2=0xf3;//111110011
delay_t1(50);

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xfb;
delay0_5s1();
P2=0xf3;
delay0_5s1();

P2=0xeb;
delay_t1(30);

P2=0xde;//11011110
delay_t1(50);

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdf;
delay0_5s1();
P2=0xde;
delay0_5s1();

P2=0xdd;
delay_t1(30);
}
}
void int0() interrupt 0
{
xx++;
if(xx==1){
xx=0;
P2=0xdb;
delay_t1(100);}
}
void int1() interrupt 2
{
xx--;
if(xx==-1)
xx=0;P2=0xf7;
delay_t1(50);
}