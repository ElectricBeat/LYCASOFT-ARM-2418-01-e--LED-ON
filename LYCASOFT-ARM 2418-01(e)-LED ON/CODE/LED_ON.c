#include <lpc21xx.h>

void delay_ms(unsigned int count)
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<333;i++);
  }
}

int a[]={0x01,0X02,0X04,0X08,0X10,0x20,0x40,0x80};

int main() 
{
	int i;
	
  PINSEL0 = 0x0000;			//Configure the P0 Pins for GPIO;
  PINSEL1 = 0x0000;			//Configure the P1 Pins for GPIO;
  PINSEL2 = 0x00000000;			//Configure the P1 Pins for GPIO;
	
  IODIR0 = 0xffffffff;			//Configure the P0 pins as OUTPUT;
	IODIR1 = 0xffffffff;			//Configure the P1 pins as OUTPUT;

  while(1)
  {
		for(i=0;i<8;i++)
		{
			IOSET0 = a[i];		// Make all the Port pins as high  
//			IOSET1 = 0xffffffff;		// Make all the Port pins as high  
			 delay_ms(200);
			
			IOCLR0 = a[i];		// Make all the Port pins as low 
//			IOCLR1 = 0xffffffff;		// Make all the Port pins as low  
//			 delay_ms(100);
		}
		
		for(i=0;i<8;i++)
		{
			IOSET0 = a[i]<<8;		// Make all the Port pins as high
			 delay_ms(200);
			
			IOCLR0 = a[i]<<8;		// Make all the Port pins as low
//			 delay_ms(100);
		}
		
		for(i=0;i<8;i++)
		{
			IOSET0 = a[i]<<16;		// Make all the Port pins as high
			 delay_ms(200);
			
			IOCLR0 = a[i]<<16;		// Make all the Port pins as low
//			 delay_ms(100);
		}
		
		for(i=0;i<8;i++)
		{
			IOSET0 = a[i]<<24;		// Make all the Port pins as high
			 delay_ms(200);
			
			IOCLR0 = a[i]<<24;		// Make all the Port pins as low
//			 delay_ms(100);
		}
		
		for(i=0;i<8;i++)
		{
			IOSET1 = a[i]<<16;		// Make all the Port pins as high
			 delay_ms(200);
			
			IOCLR1 = a[i]<<16;		// Make all the Port pins as low
//			 delay_ms(100);
		}
		
		for(i=0;i<8;i++)
		{
			IOSET1 = a[i]<<24;		// Make all the Port pins as high
			 delay_ms(200);
			
			IOCLR1 = a[i]<<24;		// Make all the Port pins as low
//			 delay_ms(100);
		}
  }
}