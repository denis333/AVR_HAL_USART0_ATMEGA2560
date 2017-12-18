/*
 * avr_lib.h
 *
 * Created: 12/13/2017 11:02:37 AM
 *  Author: denis
 */ 


#ifndef AVR_LIB_H_
#define AVR_LIB_H_

/*
typedef enum {ASYNCRONOUS, SYNCRONOUS, MASTER_SPI0, MASTER_SPI1, MASTER_SPI2, MASTER_SPI3}USART_MODE;
typedef enum {USART_0, USART_1, USART_2, USART_3}USART_NUMBER;
typedef enum {NONE, ODD, EVEN}USART_PARITY;
*/

/*An Usart_Struct is initialized when
HAL_USART_Init() API is called */

typedef struct
{
	USART_NUMBER    number;             //which usart to use from MCU
	int               baud;             //BAUD-check the fuses/datasheet for respective (F.osc) when setting this param.
	int          data_bits;             //format of frame (5..9) bits
	USART_PARITY    parity;             //check for parity
	int          stop_bits;             //Stop Bits
	USART_MODE        mode;		        //async or sync mode for work
	int     clock_polarity;             //clock plarity (XCKn),only for sync mode(1-falling edge,0-rising->output of TXd),in async mode it is ignored
}Usart_Struct;

void USART0_Init(USART_NUMBER,          //which usart to use from MCU
int,                   //BAUD-check the fuses/datasheet for respective (F.osc) when setting this param.
DATA_FRAME,                   //format of frame (5..9) bits
USART_PARITY,          //check for parity
STOP_BITS,                   //Stop Bits
USART_MODE,            //async or sync mode for work
Usart_Struct*,         //pointer to structure in which will pe placed our usart definition data
int);                  //clock polarity

void USART0_Transmit(unsigned int, Usart_Struct*);
unsigned int USART0_Receive(Usart_Struct*);



#endif /* AVR_LIB_H_ */