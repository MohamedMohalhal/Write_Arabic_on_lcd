/*****************************************************************************/
/* Title        	: 	DIO Driver											 */
/* File Name    	: 	DIO_interface.h                                      */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	20/09/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/******************************************************************************
* !comment : DIO Ports options Definitions.  			         	          *
******************************************************************************/
#define DIO_u8_PORTA             0
#define DIO_u8_PORTB             1
#define DIO_u8_PORTC             2
#define DIO_u8_PORTD             3

/******************************************************************************
* !comment : DIO Pins options Definition.  			         	          	  *
******************************************************************************/
#define DIO_u8_PIN0              0
#define DIO_u8_PIN1              1
#define DIO_u8_PIN2              2
#define DIO_u8_PIN3              3
#define DIO_u8_PIN4              4
#define DIO_u8_PIN5              5
#define DIO_u8_PIN6              6
#define DIO_u8_PIN7              7

/******************************************************************************
* !comment : DIO Pin Mode options Definitions.  			         	      *
******************************************************************************/
#define DIO_u8_OUTPUT            1
#define DIO_u8_INPUT             0

/******************************************************************************
* !comment : DIO Pin Value options Definition.  			         	      *
******************************************************************************/
#define DIO_u8_HIGH              1
#define DIO_u8_LOW               0



/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/
void DIO_voidInit         (void);

tenuErrorStatus  DIO_enuSetPinDirection (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 Copy_u8PinDirection);

tenuErrorStatus  DIO_enuSetPinValue     (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 Copy_u8PinValue);

tenuErrorStatus  DIO_enuGetPinValue     (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 * Copy_pu8ReturnedPinValue);

tenuErrorStatus  DIO_enuSetPortDirection(uint8 Copy_u8PortId, uint8 Copy_u8PortDirection);

tenuErrorStatus  DIO_enuSetPortValue    (uint8 Copy_u8PortId, uint8 Copy_u8PortValue);

tenuErrorStatus  DIO_enuGetPortValue    (uint8 Copy_u8PortId, uint8 * Copy_pu8ReturnedPortValue);


#endif
/*** !comment : End of gaurd [DIO_INTERFACE_H] *******************************/