/*****************************************************************************/
/* Title        	: 	LCD Driver				                             */
/* File Name    	: 	LCD_config.h                                         */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Origin Date  	: 	21/09/2022                                           */
/* Version      	: 	2.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 		          *
*                 than one time.                               	 	          *
******************************************************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*Options : 1 - DIO_u8_PORTA
 * 			2 - DIO_u8_PORTB
 * 			3 - DIO_u8_PORTC
 * 			4 - DIO_u8_PORTD */

#define LCD_u8_CONTROL_PORT DIO_u8_PORTD

#define LCD_u8_RS_PIN		DIO_u8_PIN0
#define LCD_u8_RW_PIN		DIO_u8_PIN1
#define LCD_u8_EN_PIN		DIO_u8_PIN2


#define LCD_u8_DATA_PORT	DIO_u8_PORTB


/*Options : 1 - LCD_u8_MODE_8_BIT
 * 			2 - LCD_u8_MODE_4_BIT
 */

#define LCD_u8_MODE		LCD_u8_MODE_8_BIT
#endif
/*** !comment : End of gaurd [LCD_config.h] **********************************/
