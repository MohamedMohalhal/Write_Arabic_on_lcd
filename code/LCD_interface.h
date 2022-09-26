/*****************************************************************************/
/* Title        	: 	LCD Driver				                             */
/* File Name    	: 	LCD_intarface.h                                      */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Origin Date  	: 	21/09/2022                                           */
/* Version      	: 	2.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 		          *
*                 than one time.                               	 	          *
******************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H




#define LCD_u8_LINE_1	1
#define LCD_u8_LINE_2	2


void LCD_voidInit(void);
void LCD_voidSendCmnd(uint8 Copy_u8Cmnd);
void LCD_voidSendChar(uint8 Copy_u8Char);
uint8 LCD_u8GoToXY(uint8 Copy_u8LineNumber ,uint8 Copy_u8Location);
void LCD_voidWriteString(uint8 * Copy_pu8String);
void LCD_voidWriteExtraChar(uint8 Copy_u8LineNumber , uint8 Copy_u8Location ,  uint8 *Copy_u8ExtraChar , uint8 Copy_u8NumberChar);
void LCD_vidWriteNumber(sint32 Copy_u32Num);

#endif
/*** !comment : End of gaurd [LCD_intarface.h] **********************************/
