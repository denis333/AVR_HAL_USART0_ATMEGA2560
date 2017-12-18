/*
 * avr_usart_hal.h
 *
 * Created: 12/12/2017 11:25:42 AM
 *  Author: denis
 */ 


#ifndef AVR_HAL_USART_H_
#define AVR_HAL_USART_H_

typedef enum {ASYNCRONOUS, SYNCRONOUS, MASTER_SPI0, MASTER_SPI1, MASTER_SPI2, MASTER_SPI3} USART_MODE;
typedef enum {USART_0, USART_1, USART_2, USART_3} USART_NUMBER;
typedef enum {NONE, ODD, EVEN} USART_PARITY;
typedef enum {FIVE_BITS=5,SIX_BITS=6,SEVEN_BITS=7,EIGHT_BITS=8,NINE_BITS=9}DATA_FRAME;
typedef enum {ONE_STOP_BIT,TWO_STOP_BITS}STOP_BITS;

void USART0_RX_Enable(void);
void USART0_TX_Enable(void);
void USART0_RX_Disable(void);
void USART0_TX_Disable(void);

void USART0_SetDataBits(DATA_FRAME);
void USART0_SetStopBits(STOP_BITS);

void USART0_SetBaudRate(unsigned char);
void USART0_PutDataInBuffer(unsigned char);
void USART0_SetDoubleTransmissionSpeed(void);
unsigned char USART0_isDataReceived(void);
unsigned char USART0_isTransmitBufferEmpty(void);
void USART0_Copy_9thBitToTransmit(unsigned char);
unsigned char USART0_GetData(void);
unsigned char USART0_GetStatus(void);
unsigned char USART0_GetResultHigh(void);
unsigned char USART0_GetResultLow(void);
void USART0_TX_Complete(void);
void USART0_RX_Complete(void);
void USART0_Flush( void );
void USART0_Disable_Power_Reduction_Mode(void);
void USART0_Set_Parity(USART_PARITY);
void USART0_ENABLE_Mode_Of_Operation_Sync(void);
void USART0_ENABLE_Mode_Of_Operation_Async(void);

void USART0_Set_XCK_Polarity_Inverted(void);
void USART0_Set_XCK_Polarity_Default(void);
void USART0_ENABLE_Spi_Mode(void);

void USART0_Set_XCK_As_Output(void);
void USART0_Set_XCK_As_Input(void);
unsigned char USART0_Set_Bits_To_Register(unsigned char ch);
#endif /* AVR_USART_HAL_H_ */