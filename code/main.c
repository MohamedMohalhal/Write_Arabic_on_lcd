/*****************************************************************************/
/* Title        	: 	Write_Arabic_on_lcd							         */
/* File Name    	: 	main.c   		                                     */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version      	: 	1.0.0                                                */
/* Notes        	: 	None                                                 */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interface.h"

int main(void)
{


	DIO_voidInit();
	LCD_voidInit();


	uint8 arr_abdo[]=
	{
				0b01110,
				0b01110,
				0b00100,
				0b01110,
				0b10101,
				0b00100,
				0b01010,
				0b01010,

				0b00000,
				0b00000,
				0b01010,
				0b00000,
				0b00000,
				0b10001,
				0b01110,
				0b00000,

				0b01110,
				0b10001,
				0b10001,
				0b11111,
				0b11011,
				0b11011,
				0b11111,
				0b00000,

				0b00000,
				0b00000,
				0b01010,
				0b10101,
				0b10001,
				0b01110,
				0b00100,
				0b00000,

				0b00000,
				0b00000,
				0b00000,
				0b00001,
				0b00001,
				0b00001,
				0b11111,
				0b00000,

				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b01110,
				0b10001,
				0b01110,

				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b01110,
				0b00001,
				0b11111,
				0b00000,

				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b00000,
				0b01110,
				0b10001,
				0b01110
	};
	LCD_u8GoToXY(LCD_u8_LINE_2 , 1);
	LCD_vidWriteNumber(211);

	LCD_voidWriteExtraChar(LCD_u8_LINE_1 , 5 , &arr_abdo[0] , 7);
	while(1)
	{

	}
}
