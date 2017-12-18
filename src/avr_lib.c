
#include "avr/io.h"
#include "avr_hal_usart.h"
#include "avr_lib.h"

void USART0_Init(USART_NUMBER     usartN,
					int           usartB,
					DATA_FRAME    usartD,
					USART_PARITY  usartP,
					STOP_BITS     usartS,
					USART_MODE    usartM,
					Usart_Struct* usartStr,
					int           usart_clock_pol)
{
	//Step 1:Init usart structure
	usartStr->number    = usartN;
	usartStr->baud      = usartB;
	usartStr->data_bits = usartD;
	usartStr->stop_bits = usartS;
	usartStr->parity    = usartP;
	usartStr->mode      = usartM;
	usartStr->clock_polarity = usart_clock_pol;
	//Step 2:Initialize usart registers
			USART0_Disable_Power_Reduction_Mode();
			
			/*MSSIP-configuration for usart in SPI mode----------------------*/
			if(usartStr->mode == MASTER_SPI0 || usartStr->mode == MASTER_SPI1)
			{   //clear UBRR
				USART0_SetBaudRate(0);
				USART0_ENABLE_Spi_Mode();
				USART0_Set_XCK_As_Output();

			 	if(usartStr->mode == MASTER_SPI1) USART0_Set_XCK_Polarity_Inverted();
			    USART0_RX_Enable();
			    USART0_TX_Enable();  
				/* Set baud rate. */
				/* IMPORTANT: The Baud Rate must be set after the transmitter is
				enabled */
				//UBRR0 = usartStr->baud;  
				USART0_SetBaudRate(usartStr->baud); 
				return;  
			}
			/*---------------------------------------------------------------*/
			USART0_RX_Enable();
			USART0_TX_Enable();
			
			USART0_SetBaudRate(usartStr->baud);
			USART0_SetDataBits(usartD);

			USART0_SetStopBits(usartS);
			USART0_Set_Parity(usartP);
			
			/*Set Async or Master SPI mode if it's needed*/ 
			if(usartStr->mode == SYNCRONOUS)
			{
				USART0_ENABLE_Mode_Of_Operation_Sync();
				
				/*Xck polarity*/
				if(usartStr->clock_polarity == 1) USART0_Set_XCK_Polarity_Inverted();
				else USART0_Set_XCK_Polarity_Default();
			}
		
} 

void USART0_Transmit(unsigned int data, Usart_Struct* us)
{

				while ( USART0_isTransmitBufferEmpty() == 0)
				{};
				if(us->data_bits == 9 && us->mode != MASTER_SPI0 && us->mode != MASTER_SPI1){
					/* Copy 9th bit to TXB8 */
					UCSR0B &= ~(1<<TXB80);
					if ( data & 0x0100 )
					UCSR0B |= (1<<TXB80);
				}
				/* Put data into buffer, sends the data*/
				USART0_PutDataInBuffer(data);
}

unsigned int USART0_Receive(Usart_Struct* us)
{ 
			 	unsigned char status, resh, resl;
				while ( USART0_isDataReceived() == 0)
				{};
			 	if(us->data_bits == 9 && us->mode != MASTER_SPI0 && us->mode != MASTER_SPI1)
			 	{
				 	/* Get status and 9th bit, then data */
				 	/* from buffer */
				status = USART0_GetStatus();
				resh = USART0_GetResultHigh();
				resl = USART0_GetResultLow();
				 	/* If error, return -1 */
				 	if ( status & USART0_Set_Bits_To_Register(FE0)|USART0_Set_Bits_To_Register(DOR0)|USART0_Set_Bits_To_Register(UPE0))
				 	return -1;
				 	/* Filter the 9th bit, then return */
				 	resh = (resh >> 1) & 0x01;
				 	return ((resh << 8) | resl);
			 	}
			 	/* Get and return received data from buffer */
			 	USART0_GetData();
}