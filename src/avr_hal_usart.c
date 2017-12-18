/*
 * avr_hal_usart.c
 *
 * Created: 12/12/2017 11:25:29 AM
 *  Author: denis
 */ 
#include "avr_hal_usart.h"
#include <avr/io.h>
#include "stdint.h"

void USART0_RX_Enable(void)
{
	UCSR0B = (1 << RXEN0);
}
void USART0_TX_Enable(void)
{
	UCSR0B = (1 << TXEN0);
}
void USART0_RX_Disable(void)
{
	UCSR0B &= ~(1 << RXEN0);
}
void USART0_TX_Disable(void)
{
	UCSR0B &= ~(1 << TXEN0);
}

void USART0_SetDataBits(DATA_FRAME n){
	switch(n)
		{
			case FIVE_BITS : UCSR0C &= ~((1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02));
			break;
			case SIX_BITS : 
			{
				UCSR0C &= ~((1 << UCSZ01) | (1 << UCSZ02));
				UCSR0C |= (1 << UCSZ00);
			}
			break;
			case SEVEN_BITS : 
			{
				UCSR0C &= ~((1 << UCSZ00) | (1 << UCSZ02));
				UCSR0C |= (1 << UCSZ01);
			}
			break;
			case EIGHT_BITS : 
			{
				UCSR0C &= ~((1 << UCSZ02));
				UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
			}
			break; 
			case NINE_BITS : UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02));
			break;
		}
}
void USART0_SetStopBits(STOP_BITS sb){

	if(sb == ONE_STOP_BIT)       UCSR0C &= (1 << USBS0);
	else if(sb == TWO_STOP_BITS) UCSR0C |= (1 << USBS0);
			
}
void USART0_SetBaudRate(unsigned char b)
{
	UBRR0H = (unsigned char)(b >> 8);
	UBRR0L = (unsigned char)b;

}

void USART0_PutDataInBuffer(unsigned char data)
{
	UDR0 = data;
}
void USART0_SetDoubleTransmissionSpeed(void)
{
	UCSR0A |= (1<<U2X0);
}

unsigned char USART0_isDataReceived(void)
{
	if( !(UCSR0A && (1 << RXC0))) return 1;
	return 0;
}
unsigned char USART0_isTransmitBufferEmpty(void)
{
	if( !(UCSR0A && (1 << UDRE0)))  return 1;
	return 0;
}
void USART0_Copy_9thBitToTransmit(unsigned char data)
{
	UCSR0B &= ~(1 << TXB80);
	if(data & 0x0100) UCSR0B |= (1<<TXB80);
					
}
unsigned char USART0_GetData(void)
{
	return UDR0;
}
unsigned char USART0_GetResultHigh(void)
{
	return UCSR0B;
}
unsigned char USART0_GetResultLow(void)
{
	return USART0_GetData();	
}
unsigned char USART0_GetStatus(void)
{
	return UCSR0A;
}

void USART0_TX_Complete(void)
{
	while ((UCSR0A & (1 << TXC0)) == 0);
}
void USART0_RX_Complete(void)
{
	while ( !(UCSR0A & (1<<RXC0)) );
}

void USART0_Flush( void )
{
	unsigned char dummy;
	while ( UCSR0A & (1<<RXC0) ) dummy = UDR0;
}
void USART0_Disable_Power_Reduction_Mode(void)
{
	PRR0 &= (1 << PRUSART0);  
}
void USART0_Set_Parity(USART_PARITY up)
{
	if(up == ODD)       UCSR0C |= (1 << UPM01) | (1 << UPM00);
	else if(up == EVEN) UCSR0C |= (1 << UPM01);
}
void USART0_ENABLE_Mode_Of_Operation_Sync(void)
{
	UCSR0C |= (1 << UMSEL00);
}
void USART0_ENABLE_Mode_Of_Operation_Async(void)
{
	UCSR0C &= ~(1 << UMSEL00);
}
void USART0_Set_XCK_Polarity_Default(void)
{
	UCSR0C &= ~(1 << UCPOL0);
}
void USART0_Set_XCK_Polarity_Inverted(void)
{
	UCSR0C |= (1 << UCPOL0);
}
void USART0_ENABLE_Spi_Mode(void)
{
	UCSR0C |= (1 << UMSEL00) | (1 << UMSEL01);
}
void USART0_Set_XCK_As_Output(void)
{
	DDRE |= (1 << PE2); 
}
void USART0_Set_XCK_As_Input(void)
{
	DDRE &= ~(1 << PE2);
}

unsigned char USART0_Set_Bits_To_Register(unsigned char ch)
{
	return (1 << ch);
}