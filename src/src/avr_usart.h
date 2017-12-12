/*
 * avr-usart.h
 *
 *  Created on: Dec 23, 2015
 *      Author: Andrei Bragarenco
 */

#ifndef AVR_USART_H_
#define AVR_USART_H_


void USART_Init( unsigned int baud );
void USART_InitInt( unsigned int baud );

void USART_Transmit( unsigned char data );
void USART_Transmit_9bit( unsigned int data );
unsigned char USART_Receive( void );
unsigned int USART_Receive_9bit( void );

unsigned char USART_ReadUDR( void );
void USART_WriteUDR( unsigned char data );

void USART_EnableInt( void );
void usart_rx_complette(void);
void usart_tx_complette(void);






#endif /* AVR_USART_H_ */
