/*Write a program in Embedded C for 8051 microcontroller to find the sum
of two one -byte numbers stored at 2000H & 2001H and store the sum at 2002H.*/

#include<reg52.h>
xdata unsigned char a _at_ 0x2000;
xdata unsigned char b _at_ 0x2001;
xdata unsigned char sum _at_ 0x2002;
void main(){
	sum = a+b;
	here: goto here;
}

/* Q2.  Write a program in Embedded C for 8051 microcontroller to find the sum 
of two one -byte numbers stored at 2000H & 2001H and store the sum at 2002H & 2003H*/

#include<reg52.h>
xdata unsigned char a _at_ 0x2000;
xdata unsigned char b _at_ 0x2001;
xdata unsigned int sum _at_ 0x2003;
void main(){
	sum = a+b;
}

/* Q3.  Write a program in Embedded C for 8051 microcontroller to find the 
16 bit sum, 8 bit difference, 16 bit product and quotient & remainder 
(one byte size) of two one -byte numbers storedat 2000H & 2001H.  
All answers should be stored from memory location 2002H onwards*/

#include<reg52.h>
xdata  unsigned char a _at_ 0x2000;
xdata unsigned char b _at_ 0x2001;
xdata unsigned int sum _at_ 0x2002; //16 bit sum
xdata unsigned char diff _at_ 0x2004; //8 bit diff
xdata unsigned int prod _at_ 0x2005; //16 prod
xdata unsigned char quot _at_ 0x2007; //8bit quotient
xdata unsigned int rem _at_ 0x2008; // 8 bit remender

void main()
{
sum=a+b ;
diff=a-b;
prod=a*b;
quot=a/b;
rem=a%b;
}

/*Q4. Write a program in Embedded C for 8051 microcontroller to copy 10 bytes of 
data starting from memory location 2000H to memory location starting from 2010H.*/


#include<reg52.h>
xdata unsigned char a _at_ 0x2000;
xdata unsigned char b _at_ 0x2010;
xdata unsigned char i _at_ 0x1000;
void main(){
	unsigned char* ptr = &a;
	unsigned char* ptr1 = &b;
	for(i = 0;i<10;i++,ptr++,ptr1++){
		*ptr1 = *ptr;
	}
	here: goto here;
} 

/* Q5. Write a program in Embedded C for 8051 microcontroller to copy 10 bytes of 
data starting from memory location 2000H to memory location starting from 2010H in reverse.*/

#include<reg52.h>
xdata  unsigned char a _at_ 0x2000;//2000 to 2009
xdata  unsigned char b _at_ 0x2010;//2010 200f 200e 200d 200c 200b 200a 200

void main( )
{ 
unsigned char i;

unsigned char *ptr1=&a,*ptr2=&b;
for (i=9;i>=0; i--, ptr1++)
{
 *(ptr2+i)=*ptr1;
}
here: goto here;
}


/* Q6. Write a program in Embedded C for 8051 microcontroller to generate a square wave of 10KHz on port pin P1.2.  Assume crystal of 12MHz.
	a) Using Timer 0 in Mode 1
	b) Using Timer 0 in Mode 2*/
	#include<reg52.h>
	sbit p = P1^2;
	void main(){
		TR0 = 0;
		TF0 = 0;
		p = 0;
		TMOD = 0x02;
		TH0 = 0xCE;
		      TL0 = 0xCE;
					TR0 = 1;
		here: while(TF0==0);
		TF0 = 0;
		p = ~p;
		goto here;
	}

/* Q7. Write a program in Embedded C for 8051 microcontroller to find the 16 bit sum
of 10 bytes of data starting from memory location 3000H to 3009H and store the 16 bit sum at 3010H & 3011H.*/

#include<reg52.h>
xdata unsigned char a _at_ 0x3000;
xdata unsigned int sum _at_ 0x3010;
void main(){
	unsigned char i =0;
	unsigned char* ptr = &a;
	sum = 0;
	for(i=0;i<10;i++,ptr++){
		sum += *ptr;
	}
	here: goto here;
}

/* Q8. Write a program in Embedded C for 8051 microcontroller to generate 
a square wave of 6KHz on port pin P1.2.  Assume crystal of 12MHz. */

#include<reg52.h>
sbit P12=P1^2;
void main()
{
	P12=0;
	TMOD=0x02;
	TH0=TL0=0xAC;
	TR0=1;
	TF0=0;
	here:while(TF0==0);
	TF0=0;
	P12=~P12;
	goto here;
}

/* Q9. Design a circuit to show the interface of two LEDs (L1 & L2) and one Key (K1) 
to P1.0, P1.1 & P1.2 port lines of 8051.  Write a program in Embedded C for 8051 microcontroller 
such that the LED1 remains ON and LED2 remains OFF as long as K1 is not pressed and LED1 
remains OFF and LED2 remains ON as long as K1 is pressed */


#include<reg52.h>
sbit L1=P1^0;
sbit L2=P1^1;
sbit Key=P1^2;
void main(){
	L1=L2=0;
	Key = 1;
	while(1){
		if(Key==0){
			L1=1;
			L2=0;
		}
		if(Key==1){
			L1=0;
			L2=1;
		}
	}
}

/* Q10.  a. Write a program in Embedded C for 8051 microcontroller to generate a 
square wave of 10KHz on port pin P1.2 using Timer 0 in Mode 1 and using interrupt.  
Assume crystal of 12MHz. */

#include<reg52.h>
sbit p12=P1^2;
void main(){
	p12=0;
	IE=0x82; //EA=1, ET0=1 all others 0
	TMOD=0x01;
	TL0=0xCE;
	TH0=0xFF;
	TR0=1;
	here:goto here;
}
void isr_timer0() interrupt 1{
		TF0=0;
	  TR0 = 0;
		p12=~p12;
	  TL0=0xCE;
		TH0=0xFF;
		TR0 = 1;
}


/* Q11. Write a program in Embedded C for 8051 microcontroller to generate a 
square wave of 10KHz on port pin P1.2 using Timer 0 in Mode 2 and using interrupt.  
Assume crystal of 12MHz. */

#include<reg52.h>
sbit p12=P1^2;
void main(){
	p12=0;
	IE=0x82; //EA=1, ET0=1 all others 0
	TMOD=0x02;
	TL0=0xCE;
	TH0=0xCE;
	TR0=1;
	here:goto here;
}
void isr_timer0() interrupt 1{
		TF0=0;
		p12=~p12;
}


/* Q12.  Write a program in Embedded C for 8051 microcontroller to transmit the number 0x5A on serial port at baud 
rate of 1200 baud in an infinite loop.  Assume crystal of 11.0592MHz.*/


#include<reg52.h>
void main(){
	TMOD=0x20;
	TH1=TL1=0xE8;
	SCON=0x40;
	TR1=1;
	here:SBUF=0x5A;
	while(TI==0);
	TI=0;
	goto here; 
}


/* Q13.  Write a program in Embedded C for 8051 microcontroller to transmit the number 
0x5A on serial port at baud rate of 1200 baud in an infinite loop using interrupt.  
Assume crystal of 11.0592MHz. */   

#include<reg52.h>
void main(){
	IE=0x90; //EA=1, ET0=1 all others 0
	TMOD=0x20;
	TH1=TL1=0xE8;
	SCON=0x40;
	TR1=1;
	SBUF=0x5A;
	here: goto here;
}
void isr_serial() interrupt 4{
	SBUF=0x5A;
	TI=0;
}


/* Q14.  Write a program in Embedded C for 8051 microcontroller to transmit 10 numbers starting from location 2000h 
on serial port at baud rate of 9600 baud.  Assume crystal of 11.0592MHz */

#include<reg52.h>
xdata unsigned char num _at_ 0x2000;
void main()
{
	unsigned char* ptr =&num;
	unsigned char i=0;
	TMOD=0x20;
	TH1=TL1=0xFD;
	SCON=0x40;
	TR1=1;
	for(i=0;i<10;i++,	ptr++)
	{
		SBUF = *ptr;
		while(TI==0);
		TI=0;
	}
	here: goto here;
}


/* Q15.  Write a program in Embedded C for 8051 microcontroller to transmit 10 numbers starting 
from location 2000h on serial port at baud rate of 9600 baud  using interrupt.  
Assume crystal of 11.0592MHz.*/

#include<reg52.h>
xdata unsigned char num _at_ 0x2000;
xdata unsigned char i _at_ 0x4000;
unsigned char *ptr=&num;
void main()
{
	TMOD = 0x20;
	TH1=TL1=0xFD;
	SCON=0x40;
	TR1=1;
	IE=0x90;
	SBUF=*ptr;
	here: goto here;
}
void serial_isr() interrupt 4
{
		TI = 0;
		if(i==10){
			return;
		}
		i++;
		ptr++;
		SBUF=*ptr;
}


/* Q16.  Interface a 7 segment common cathode LED display to Port 1 on 8051.  
Write a program in Embedded C for 8051 microcontroller to display the numbers from 0 to 9 in an infinite loop on the LED 
display with delay of 500msec inbetween each count.  Assume crystal of 11.0592MHz. */

#include<reg52.h>
unsigned char dispcode[10] ={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void delay()
	{
		int c = 0;
		TMOD=0x02;
		TH0=TL0=0x92;
		TR0=1;
		here: while(TF0==0);
		TF0=0;
		c++;
		if(c>10*500){
			TR0=0;
			return;
		}
		goto here;
	}
void main()
{
	unsigned char i =0;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P1=dispcode[i];
			delay();
		}
	}
}




/* Q17.  Interface a common cathode 7 segment display with Port 1 and a key at Port 2.1.  
Write code in embedded C such that the count on the display is incremented every time the key is pressed.  
Further, once the count reaches 9 then it rolls over to 0.  Assume crystal of 12MHz*/

#include<reg52.h>
sbit key = P2^1;
unsigned char display[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char i = 0;
void main(){
	unsigned char *ptr;
	key = 1;
	while(1){
		ptr = &display[0];
		for(i=0;i<10;i++,ptr++){
			P1=*ptr;
			while(key==1);
			while(key==0);
		}
	}
}




/* Q18.  Write a program in Embedded C for 8051 microcontroller to 
receive 05 numbers on serial port at baud rate of 9600 baud  using interrupt 
and store the same starting from location 2000h   Assume crystal of 11.0592MHz. */

#include<reg52.h>
xdata unsigned char a _at_ 0x2000;
unsigned char i = 0;
unsigned char* ptr = &a;
void main(){
	TMOD = 0x20;
	TH1=TL1 = 0xFD;	
	SCON = 0x50;
	IE = 0x90;
	TR1 = 1;
	here: goto here;
}
void isr_in() interrupt 4{
		RI = 0;
		if(i==5){
			return;
		}
		i++;
		*ptr = SBUF;
		ptr++;
	}
