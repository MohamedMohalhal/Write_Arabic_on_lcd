/*****************************************************************************/
/* Title        	: 	LCD Driver											 */
/* File Name    	: 	LCD_program.c                                        */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Origin Date  	: 	21/09/2022                                           */
/* Version      	: 	2.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* Delay DIRECTIVES ****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/
void LCD_voidInit(void)
{
	_delay_ms(35);
	/*FUNCTION SET*/
	LCD_voidSendCmnd(0b00111000);
	_delay_ms(40);
	LCD_voidSendCmnd(0b00001111);

	_delay_ms(40);
	LCD_voidSendCmnd(0x01);

	_delay_ms(2);

	LCD_voidSendCmnd(0b0000110);
}

void LCD_voidSendCmnd(uint8 Copy_u8Cmnd)
{
	/*STEp 1 RS = 0*/
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RS_PIN , DIO_u8_LOW) ;
	/* RW = 0*/
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RW_PIN , DIO_u8_LOW);
	/* Write command*/
	DIO_enuSetPortValue(LCD_u8_DATA_PORT , Copy_u8Cmnd);
	/*		 EN = 1 */
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_EN_PIN , DIO_u8_HIGH);
	_delay_ms(1);
	/*		 EN = 0 */
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_EN_PIN , DIO_u8_LOW);
}

void LCD_voidSendChar(uint8 Copy_u8Char)
{
	/*STEp 1 RS = 1*/
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH);
		/* RW = 0*/
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RW_PIN , DIO_u8_LOW);
		/* Write command*/
	DIO_enuSetPortValue(LCD_u8_DATA_PORT , Copy_u8Char);
		/*		 EN = 1 */
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_EN_PIN , DIO_u8_HIGH);
		_delay_ms(1);
		/*		 EN = 0 */
	DIO_enuSetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_EN_PIN , DIO_u8_LOW);
}

uint8 LCD_u8GoToXY(uint8 Copy_u8LineNumber ,uint8 Copy_u8Location)
{
	uint8 Local_u8Erorr = 0 ;

	if(Copy_u8Location <= 39)
	{
		switch(Copy_u8LineNumber)
		{
		case LCD_u8_LINE_1 : LCD_voidSendCmnd(LCD_SET_DDRAM_ROW0+Copy_u8Location);break ;
		case LCD_u8_LINE_2 : LCD_voidSendCmnd(LCD_SET_DDRAM_ROW1+Copy_u8Location);break ;
		default : Local_u8Erorr = 1 ;
		}
	}
	else
	{
		Local_u8Erorr = 1 ;
	}

	return Local_u8Erorr ;
}

void LCD_voidWriteString(uint8 * Copy_pu8String)
{
	uint8 Local_u8Counter = 0;

		while(0 != Copy_pu8String[Local_u8Counter])
		{
			LCD_voidSendChar(Copy_pu8String[Local_u8Counter]);
			Local_u8Counter++;
		}
}

void LCD_voidWriteExtraChar(uint8 Copy_u8LineNumber , uint8 Copy_u8Location , uint8 *Copy_u8ExtraChar ,uint8 Copy_u8NumberChar)
{
	uint8 Local_u8Iteration1, Local_u8Iteration2;

		/*DDRAM-->CGRAM*/
		LCD_voidSendCmnd(DDRAM_TO_CGRAM);

		for(Local_u8Iteration1 = 0 ; Local_u8Iteration1 < 64; Local_u8Iteration1++)
		{
			LCD_voidSendChar(Copy_u8ExtraChar[Local_u8Iteration1]);
		}

		/*CGRAM-->DDRAM*/
		LCD_voidSendCmnd(CGRAM_TO_DDRAM);
		LCD_u8GoToXY(Copy_u8LineNumber , Copy_u8Location) ;

		/*First eight character which saved at CGRAM*/
		for (Local_u8Iteration2 = 0; Local_u8Iteration2 <= Copy_u8NumberChar; Local_u8Iteration2++)
		{
			/* Write bytes of DDRAM */
			LCD_voidSendChar(Local_u8Iteration2);
			_delay_ms(5);
		}
}

void LCD_vidWriteNumber(sint32 Copy_u32Num)
{
	uint8 Local_u8Counter = 0, Local_u8Digits = 0, Local_u8Current;
		uint16 Local_u16CopyNumber = Copy_u32Num;

		if(0 == Copy_u32Num)
		{
			LCD_voidSendChar('0');
		}
		else
		{
			while(Local_u16CopyNumber)
			{
				Local_u16CopyNumber /= 10;
				Local_u8Digits++;
			}
			Local_u16CopyNumber = Copy_u32Num;

			for(Local_u8Counter = 0; Local_u8Counter < Local_u8Digits; Local_u8Counter++)
			{
				Local_u8Current = Local_u16CopyNumber / (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
				LCD_voidSendChar(Local_u8Current + '0');
				Local_u16CopyNumber %= (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
			}
		}
}


static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2)
{
	uint16 Local_u16Result = 1;
	uint8 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8Number2; Local_u8Counter++)
	{
		Local_u16Result *= Copy_u8Number1;
	}
	return Local_u16Result;
}
/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
