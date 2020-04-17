/*
 * seven segment intrupt.c
 *
 * Created: 4/17/2020 2:35:58 AM
 * Author : ahmad
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define toggel_bit(var,bit)		var^=(1<<bit)
#define set_bit(var,bit)		var|=(1<<bit)
#define clear_bit(var,bit)		var&=~(1<<bit)
#define seg_dd		DDRA
#define seg_con_dd	DDRB
#define E1		1
#define E2		2
#define seg_port	PORTA
#define seg_con_port	PORTB
#define led_port		PORTC
#define led_dd			DDRC

		volatile unsigned char count =0;
		void toggel_led(void);
ISR(INT0_vect){
	  toggel_led();
		count++;
		_delay_ms(10000);
		if(count==9){
			count=0;
			_delay_ms(10000);
		}
}
void toggel_led(void){
	toggel_bit(led_port,2);
	_delay_ms(1000);
}
void sevensegment(void){
		set_bit(seg_con_port,E1);
		set_bit(seg_con_port,E2);
		_delay_ms(1000);
		

		switch (count)
		{
			case 0:
			seg_port = 0x00;
			_delay_ms(10000);
			break;
			case 1:
			seg_port = 0x10;
			_delay_ms(10000);
			break;
			case 2:
			seg_port = 0x20;
			_delay_ms(10000);
			break;
			case 3:
			seg_port = 0x30;
			_delay_ms(10000);
			break;
			case 4:
			seg_port = 0x40;
			_delay_ms(10000);
			break;
			case 5:
			seg_port = 0x50;
			_delay_ms(10000);
			break;
			case 6:
			seg_port = 0x60;
			_delay_ms(10000);
			break;
			case 7:
			seg_port = 0x70;
			_delay_ms(10000);
			break;
			case 8:
			seg_port = 0x80;
			_delay_ms(10000);
			break;
			case 9:
			seg_port = 0x90;
			_delay_ms(10000);
			break;
			default:
			seg_con_port = 0x00;
			break;
		}
}

int main(void)
{
	set_bit(led_dd,1);
	set_bit(GICR,INT0);
	clear_bit(MCUCR,ISC00);
	set_bit(MCUCR,ISC01);
	sei();
	
	/* Replace with your application code */
	while (1)  {
		sevensegment();
		ISR(INT0_vect);
	}
}


