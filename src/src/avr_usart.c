/*
 * avr-usart.c
 *
 *  Created on: Dec 23, 2015
 *      Author: Andrei Bragarenco
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr_usart.h>

void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRR0H = ( unsigned char)(baud>>8);
	UBRR0L = ( unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	 UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
void USART_InitInt( unsigned int baud )
{
	/* Set baud rate */
	UBRR0H = ( unsigned char)(baud>>8);
	UBRR0L = ( unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE1);
	/* Set frame format: 8data, 1stop bit */
	 UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

//void USART_Init( unsigned int ubrr){
///* Set baud rate */
//UBRR0H = (unsigned char)(ubrr>>8);
//UBRR0L = (unsigned char)ubrr;
///* Enable receiver and transmitter */
//UCSR0B = (1<<RXEN)|(1<<TXEN);
///* Set frame format: 8data, 2stop bit */
//UCSR0C = (1<<USBS)|(3<<UCSZ0);
//} // USART_Init
//
//void USART_Init(unsigned int ubbr){
//
// UBRR0H = (unsigned char)(ubbr>>8);
// UBRR0L = (unsigned char)ubbr;
//
// UCSR0B = (1<<TXEN0)|(1<<RXEN0);
// UCSR0C = (1<<USBS0)|(3<<UCSZ00);
//}

void USART_EnableInt( void ){
	UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0);

}

uint16_t USART0_tx_counter = 0;

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	USART0_tx_counter ++;
	UDR0 = data;
}
void USART_WriteUDR( unsigned char data )
{
	/* Put data into buffer, sends the data */
	USART0_tx_counter ++;
	UDR0 = data;
}


void USART_Transmit_9bit( unsigned int data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)))
	;
	/* Copy 9th bit to TXB8 */
	UCSR0B &= ~(1<<TXB80);
	if ( data & 0x0100 )
		UCSR0B |= (1<<TXB80);
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}
unsigned char USART_ReadUDR( void )
{
	/* Get and return received data from buffer */
	return UDR0;
}

unsigned int USART_Receive_9bit( void )
{
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSR0A;
	resh = UCSR0B;
	resl = UDR0;
	/* If error, return -1 */
	if ( status & ((1<<FE0)|(1<<DOR0)|(1<<PE0)) )
		return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

ISR(USART0_RXC_vect){
	usart_rx_complette();
}
ISR(USART0_TXC_vect){
	usart_tx_complette();
}

