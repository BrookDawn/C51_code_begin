
#include <REGX51.H>
#include <intrins.h>

#define DELAY_MS 10

typedef unsigned long u32;

void setLed(u32 res);
void delay(u32 ms);

void main()
{
	u32 a = ~(0x00000001), b = 0;
	u32 k = 0, i = 0;
while(1)
 {
   i = 20;
a = 0;
for(k = 0; k < i; k++)
{
	delay(DELAY_MS * 2);
	a = ~a;
	setLed(a);
}
 }
}
void setLed(u32 res)
{ 
	P2 = (res & 0x000000FF) >> (0*4);
	P0 = (res & 0x0000FF00) >> (2*4);
}

void delay(u32 n)
{
	u32 i = 0, j = 0;
	for (i = 0; i < n; i++)
    	for (j = 0; j < 123; j++);
}

