/*****************************************************************************/
/* Title        	: 	LCD Driver				                             */
/* File Name    	: 	LCD_private.h                                        */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Origin Date  	: 	21/09/2022                                           */
/* Version      	: 	2.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 		          *
*                 than one time.                               	 	          *
******************************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIAVRE_H


#define LCD_u8_MODE_8_BIT  1
#define LCD_u8_MODE_4_BIT	2


#define  LCD_SET_DDRAM_ROW0       128
#define  LCD_SET_DDRAM_ROW1       128 + 64

#define  DDRAM_TO_CGRAM           64
#define  CGRAM_TO_DDRAM           128

static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2);

#endif
/*** !comment : End of gaurd [LCD_private.h] **********************************/
