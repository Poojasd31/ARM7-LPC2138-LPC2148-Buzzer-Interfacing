#include<LPC21XX.h>
#define Buzzer 21
#define SW 14


void delay(int); //Forward Declaration

void main()
{
	//Pinsel reg to select pin function
	PINSEL0 = 0X00000000; //p0.0-p0.15
	PINSEL1 = 0X00000000; //P0.16-P0.31
	
	//Direction reg
	IODIR0 |= (1<<Buzzer) | (0<<SW); //Buzzer as an Output and SW is an input
	
	IOCLR0 = (1<<Buzzer);
	
	while(1)
	{
		if(!(IOPIN0 & (1<<SW)))  //IF SWitch is pressed
		{
			delay(50); //Debouncing delay
			IOSET0 = (1<<Buzzer);
		}
		
		else
		{
			IOCLR0 = (1<<Buzzer);
		}
		
	}
}

void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<60000;j++)
		{
		}
	}
}



