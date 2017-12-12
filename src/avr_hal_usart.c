/*
 * avr_hal_usart.c
 *
 * Created: 12/12/2017 11:25:29 AM
 *  Author: denis
 */ 
#include "avr_usart_hal.h"
#include <stdint.h>
#include <stdbool.h>

void USART_RX_Enable(USART_NUMBER un){
	switch(un)
	{
		case USART_0 : UCSR0B = (1 << RXEN0);
		break ;
		case USART_1 : UCSR1B = (1 << RXEN1);
		break;
		case USART_2 : UCSR2B = (1 << RXEN2);
		break;
		case USART_3 : UCSR3B = (1 << RXEN3);
		break;
	}
}
void USART_TX_Enable(USART_NUMBER un){
		switch(un)
		{
			case USART_0 : UCSR0B = (1 << TXEN0);
			break ;
			case USART_1 : UCSR1B = (1 << TXEN1);
			break;
			case USART_2 : UCSR2B = (1 << TXEN2);
			break;
			case USART_3 : UCSR3B = (1 << TXEN3);
			break;
		}
}
void USART_RX_Disable(USART_NUMBER un){
		switch(un)
		{
			case USART_0 : UCSR0B &= ~(1 << RXEN0);
			break ;
			case USART_1 : UCSR1B &= ~(1 << RXEN1);
			break;
			case USART_2 : UCSR2B &= ~(1 << RXEN2);
			break;
			case USART_3 : UCSR3B &= ~(1 << RXEN3);
			break;
		}
}
void USART_TX_Disable(USART_NUMBER un){
			switch(un)
			{
				case USART_0 : UCSR0B &= ~(1 << TXEN0);
				break ;
				case USART_1 : UCSR1B &= ~(1 << TXEN1);
				break;
				case USART_2 : UCSR2B &= ~(1 << TXEN2);
				break;
				case USART_3 : UCSR3B &= ~(1 << TXEN3);
				break;
			}
}
void USART_SetDataBits(USART_NUMBER un,uint8_t n){
			switch(un)
			{
				case USART_0 :
				{
					switch(n)
					{
						case 5 : UCSR0C &= ~((1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02));
						break;
						case 6 : 
						{
							UCSR0C &= ~((1 << UCSZ01) | (1 << UCSZ02));
							UCSR0C |= (1 << UCSZ00);
						}
						break;
						case 7 : 
						{
							UCSR0C &= ~((1 << UCSZ00) | (1 << UCSZ02));
							UCSR0C |= (1 << UCSZ01);
						}
						break;
						case 8 : 
						{
							UCSR0C &= ~((1 << UCSZ02));
							UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
						}
						break; 
						case 9 : UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02));
						break;
					}
				}
				break ;
				case USART_1 : 
				{
					switch(n)
					{
						case 5 : UCSR1C &= ~((1 << UCSZ10) | (1 << UCSZ11) | (1 << UCSZ12));
						break;
						case 6 :
						{
							UCSR1C &= ~((1 << UCSZ11) | (1 << UCSZ12));
							UCSR1C |= (1 << UCSZ10);
						}
						break;
						case 7 :
						{
							UCSR1C &= ~((1 << UCSZ10) | (1 << UCSZ12));
							UCSR1C |= (1 << UCSZ11);
						}
						break;
						case 8 :
						{
							UCSR1C &= ~((1 << UCSZ12));
							UCSR1C |= (1 << UCSZ10) | (1 << UCSZ11);
						}
						break;
						case 9 : UCSR1C |= ((1 << UCSZ10) | (1 << UCSZ11) | (1 << UCSZ12));
						break;
					}
				}
				break;
				case USART_2 : 
				{
					switch(n)
					{
						case 5 : UCSR2C &= ~((1 << UCSZ20) | (1 << UCSZ21) | (1 << UCSZ22));
						break;
						case 6 :
						{
							UCSR2C &= ~((1 << UCSZ21) | (1 << UCSZ22));
							UCSR2C |= (1 << UCSZ20);
						}
						break;
						case 7 :
						{
							UCSR2C &= ~((1 << UCSZ20) | (1 << UCSZ22));
							UCSR2C |= (1 << UCSZ21);
						}
						break;
						case 8 :
						{
							UCSR2C &= ~((1 << UCSZ22));
							UCSR2C |= (1 << UCSZ20) | (1 << UCSZ21);
						}
						break;
						case 9 : UCSR2C |= ((1 << UCSZ20) | (1 << UCSZ21) | (1 << UCSZ22));
						break;
					}
				}
				break;
				case USART_3 : 
				{
					switch(n)
					{
						case 5 : UCSR3C &= ~((1 << UCSZ30) | (1 << UCSZ31) | (1 << UCSZ32));
						break;
						case 6 :
						{
							UCSR3C &= ~((1 << UCSZ31) | (1 << UCSZ32));
							UCSR3C |= (1 << UCSZ30);
						}
						break;
						case 7 :
						{
							UCSR3C &= ~((1 << UCSZ30) | (1 << UCSZ32));
							UCSR3C |= (1 << UCSZ31);
						}
						break;
						case 8 :
						{
							UCSR3C &= ~((1 << UCSZ32));
							UCSR3C |= (1 << UCSZ30) | (1 << UCSZ31);
						}
						break;
						case 9 : UCSR3C |= ((1 << UCSZ30) | (1 << UCSZ31) | (1 << UCSZ32));
						break;
					}
				}
				break;
			}	
}
void USART_SetStopBits(USART_NUMBER un, uint8_t n){
			switch(un)
			{
				case USART_0 : 
				{
					if(n==1)      UCSR0C &= (1 << USBS0);
					else if(n==2) UCSR0C |= (1 << USBS0);
				}
				break ;
				case USART_1 : 
				{
					if(n==1)      UCSR1C &= (1 << USBS1);
					else if(n==2) UCSR1C |= (1 << USBS1);
				}
				break;
				case USART_2 :
				{
					if(n==1)      UCSR2C &= (1 << USBS2);
					else if(n==2) UCSR2C |= (1 << USBS2);
				}
				break;
				case USART_3 : 
				{
					if(n==1)      UCSR3C &= (1 << USBS3);
					else if(n==2) UCSR3C |= (1 << USBS3);
				}
				break;
			}	
}
void USART_SetBaudRate(USART_NUMBER un, uint8_t b){
			switch(un)
			{
				case USART_0 :
				{
					UBRR0H = (unsigned char)(b >> 8);
					UBRR0L = (unsigned char)b;
				}
				break ;
				case USART_1 :
				{
					UBRR1H = (unsigned char)(b >> 8);
					UBRR1L = (unsigned char)b;
				}
				break;
				case USART_2 : 
				{
					UBRR2H = (unsigned char)(b >> 8);
					UBRR2L = (unsigned char)b;
				}
				break;
				case USART_3 : 
				{
					UBRR3H = (unsigned char)(b >> 8);
					UBRR3L = (unsigned char)b;
				}
				break;
			}	
}
void USART_PutDataInBuffer(USART_NUMBER un, uint8_t data){
			switch(un)
			{
				case USART_0 : UDR0 = data;
				break ;
				case USART_1 : UDR1 = data;
				break;
				case USART_2 : UDR2 = data;
				break;
				case USART_3 : UDR3 = data;
				break;
			}	
}
void USART_DoubleTransmissionSpeed(USART_NUMBER un)
{
				switch(un)
				{
					case USART_0 : UCSR0A |= (1<<U2X0);
					break ;
					case USART_1 : UCSR1A |= (1<<U2X1);
					break;
					case USART_2 : UCSR2A |= (1<<U2X2);
					break;
					case USART_3 : UCSR3A |= (1<<U2X3);
					break;
				}
}
uint8_t USART_isDataReceived(USART_NUMBER un)
{
				switch(un)
				{
					case USART_0 : ( !(UCSR0A && (1 << RXC0))) ? return 1 : return 0;
					case USART_1 : ( !(UCSR1A && (1 << RXC1))) ? return 1 : return 0;
					case USART_2 : ( !(UCSR2A && (1 << RXC2))) ? return 1 : return 0;
					case USART_3 : ( !(UCSR3A && (1 << RXC3))) ? return 1 : return 0;
				}
}
uint8_t USART_isTransmitBufferEmpty(USART_NUMBER un)
{
				switch(un)
				{
					case USART_0 : ( !(UCSR0A && (1 << UDRE0))) ? return 1 : return 0;
					case USART_1 : ( !(UCSR1A && (1 << UDRE1))) ? return 1 : return 0;
					case USART_2 : ( !(UCSR2A && (1 << UDRE2))) ? return 1 : return 0;
					case USART_3 : ( !(UCSR3A && (1 << UDRE3))) ? return 1 : return 0;
				}	
}
void USART_Copy_9thBitToTransmit(USART_NUMBER un,uint8_t data)
{
				switch(un)
				{
					case USART_0 :
					{
						UCSR0B &= ~(1 << TXB80);
						if(data & 0x0100) UCSR0B |= (1<<TXB80);
					}
					case USART_1 :
					{
						UCSR1B &= ~(1 << TXB81);
						if(data & 0x0100) UCSR1B |= (1<<TXB81);						
					}
					case USART_2 :
					{
						UCSR2B &= ~(1 << TXB82);
						if(data & 0x0100) UCSR2B |= (1<<TXB82);						
					}
					case USART_3 : 
					{
						UCSR3B &= ~(1 << TXB83);
						if(data & 0x0100) UCSR3B |= (1<<TXB83);						
					}
				}
}
uint8_t USART_GetData(USART_NUMBER un){
				switch(un)
				{
					case USART_0 : return UDR0;
					case USART_1 : return UDR1;
					case USART_2 : return UDR2;
					case USART_3 : return UDR3;
				}	
}
uint8_t USART_GetResultHigh(USART_NUMBER un)
{
				switch(un)
				{
					case USART_0 : return UCSR0B;
					break ;
					case USART_1 : return UCSR0B;
					break;
					case USART_2 : return UCSR0B;
					break;
					case USART_3 : return UCSR0B;
					break;
				}
}
uint8_t USART_GetResultLow(USART_NUMBER un)
{
	return USART_GetData(un);	
}
uint8_t USART_GetStatus(USART_NUMBER un)
{
				switch(un)
				{
					case USART_0 : return UCSR0A;
					break ;
					case USART_1 : return UCSR1A;
					break;
					case USART_2 : return UCSR2A;
					break;
					case USART_3 : return UCSR3A;
					break;
				}
}
