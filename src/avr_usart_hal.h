/*
 * avr_usart_hal.h
 *
 * Created: 12/12/2017 11:25:42 AM
 *  Author: denis
 */ 


#ifndef AVR_USART_HAL_H_
#define AVR_USART_HAL_H_

typedef enum {ASYNCRONOUS, SYNCRONOUS, MASTER_SPI0, MASTER_SPI1, MASTER_SPI2, MASTER_SPI3} USART_MODE;
typedef enum {USART_0, USART_1, USART_2, USART_3} USART_NUMBER;
typedef enum {NONE, ODD, EVEN} USART_PARITY;


void USART_RX_Enable(USART_NUMBER,uint8_t);
void USART_TX_Enable(USART_NUMBER,uint8_t);
void USART_RX_Disable(USART_NUMBER,uint8_t);
void USART_TX_Disable(USART_NUMBER ,uint8_t);
void USART_SetDataBits(USART_NUMBER,uint8_t);
void USART_SetStopBits(USART_NUMBER,uint8_t);
void USART_SetBaudRate(USART_NUMBER,uint8_t);
void USART_PutDataInBuffer(USART_NUMBER,uint8_t);
void USART_DoubleTransmissionSpeed(USART_NUMBER);
uint8_t USART_isDataReceived(USART_NUMBER);
uint8_t USART_isTransmitBufferEmpty(USART_NUMBER);
#endif /* AVR_USART_HAL_H_ */