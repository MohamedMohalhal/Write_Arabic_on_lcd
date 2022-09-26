/*****************************************************************************/
/* Title        	: 	DIO Driver								 			 */
/* File Name   		: 	DIO_program.c                                        */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version          : 	2.0.0                                                */
/* Origin Date  	: 	20/09/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
************************************ MCAL *************************************
******************************************************************************/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/
void DIO_voidInit         (void)
{
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
						   DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
						   DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);

	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
						   DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
						   DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);						   

	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
						   DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
											                    
	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
						   DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
											 
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
						   DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
											 
	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
						   DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}

tenuErrorStatus  DIO_enuSetPinDirection (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 Copy_u8PinDirection)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && ((Copy_u8PinDirection == DIO_u8_OUTPUT) || (Copy_u8PinDirection == DIO_u8_INPUT)))
		{
			switch (Copy_u8PortId)
			{
				case DIO_u8_PORTA:
					switch (Copy_u8PinDirection)
					{
						case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);break;
						case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);break;
					}
				break;
				case DIO_u8_PORTB:
					switch (Copy_u8PinDirection)
					{
						case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);break;
						case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);break;
					}
				break;
				case DIO_u8_PORTC:
					switch (Copy_u8PinDirection)
					{
						case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);break;
						case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);break;
					}
				break;
				case DIO_u8_PORTD:
					switch (Copy_u8PinDirection)
					{
						case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);break;
						case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);break;
					}
				break;
					default :Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}

		return Local_enuErrorState;
}

tenuErrorStatus  DIO_enuSetPinValue     (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 Copy_u8PinValue)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
		if(Copy_u8PinId <= DIO_u8_PIN7)
		{
			switch (Copy_u8PortId)
			{
				case DIO_u8_PORTA:
					switch (Copy_u8PinValue)
					{
						case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);break;
						case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);break;
						default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
					}
				break;
				case DIO_u8_PORTB:
					switch (Copy_u8PinValue)
					{
						case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);break;
						case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);break;
						default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
					}
				break;
				case DIO_u8_PORTC:
					switch (Copy_u8PinValue)
					{
						case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);break;
						case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);break;
						default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
					}
				break;
				case DIO_u8_PORTD:
					switch (Copy_u8PinValue)
					{
						case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);break;
						case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);break;
						default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
					}
				break;
					default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
			}

		}
		else
		{
			Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}
		return Local_enuErrorState;

}

tenuErrorStatus  DIO_enuGetPinValue     (uint8 Copy_u8PortId, uint8 Copy_u8PinId ,uint8 * Copy_pu8ReturnedPinValue)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
		uint8 Local_u8PinValue;
		if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_pu8ReturnedPinValue != NULL_PTR))
		{
			switch (Copy_u8PortId)
			{
				case DIO_u8_PORTA:
					Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);
					if(Local_u8PinValue == 0)
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
					}
					else
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
					}
				break;
				case DIO_u8_PORTB:
					Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);
					if(Local_u8PinValue == 0)
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
					}
					else
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
					}
				break;
				case DIO_u8_PORTC:
					Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);
					if(Local_u8PinValue == 0)
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
					}
					else
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
					}
				break;
				case DIO_u8_PORTD:
					Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);
					if(Local_u8PinValue == 0)
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
					}
					else
					{
						*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
					}
				break;
				default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_NULL_POINTER ;
		}
		return Local_enuErrorState;

}

tenuErrorStatus  DIO_enuSetPortDirection(uint8 Copy_u8PortId, uint8 Copy_u8PortDirection)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
		if((Copy_u8PortDirection == DIO_u8_OUTPUT) || (Copy_u8PortDirection == DIO_u8_INPUT))
		{
			switch (Copy_u8PortId)
			{
				case DIO_u8_PORTA:
					switch (Copy_u8PortDirection)
					{
						case DIO_u8_OUTPUT:DIO_u8_DDRA_REG = 0xff;break;
						case DIO_u8_INPUT :DIO_u8_DDRA_REG = 0x00;break;
					}
				break;
				case DIO_u8_PORTB:
					switch (Copy_u8PortDirection)
					{
						case DIO_u8_OUTPUT:DIO_u8_DDRB_REG = 0xff;break;
						case DIO_u8_INPUT :DIO_u8_DDRB_REG = 0x00;break;
					}
				break;
				case DIO_u8_PORTC:
					switch (Copy_u8PortDirection)
					{
						case DIO_u8_OUTPUT:DIO_u8_DDRC_REG = 0xff;break;
						case DIO_u8_INPUT :DIO_u8_DDRC_REG = 0x00;break;
					}
				break;
				case DIO_u8_PORTD:
					switch (Copy_u8PortDirection)
					{
						case DIO_u8_OUTPUT:DIO_u8_DDRD_REG = 0xff;break;
						case DIO_u8_INPUT :DIO_u8_DDRD_REG = 0x00;break;
					}
				break;
				default : Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}
		return Local_enuErrorState;

}

tenuErrorStatus  DIO_enuSetPortValue    (uint8 Copy_u8PortId, uint8 Copy_u8PortValue)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:DIO_u8_PORTA_REG = Copy_u8PortValue;break;
			case DIO_u8_PORTB:DIO_u8_PORTB_REG = Copy_u8PortValue;break;
			case DIO_u8_PORTC:DIO_u8_PORTC_REG = Copy_u8PortValue;break;
			case DIO_u8_PORTD:DIO_u8_PORTD_REG = Copy_u8PortValue;break;
			default :  Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}
		return Local_enuErrorState;

}

tenuErrorStatus  DIO_enuGetPortValue    (uint8 Copy_u8PortId, uint8 * Copy_pu8ReturnedPortValue)
{
	tenuErrorStatus  Local_enuErrorState = ERORR_STD_TYPES_OK ;
		if( Copy_pu8ReturnedPortValue != NULL_PTR)
		{
			switch (Copy_u8PortId)
			{
				case DIO_u8_PORTA: *Copy_pu8ReturnedPortValue = DIO_u8_PINA_REG;break;
				case DIO_u8_PORTB: *Copy_pu8ReturnedPortValue = DIO_u8_PINB_REG;break;
				case DIO_u8_PORTC: *Copy_pu8ReturnedPortValue = DIO_u8_PINC_REG;break;
				case DIO_u8_PORTD: *Copy_pu8ReturnedPortValue = DIO_u8_PIND_REG;break;
				default : Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}
		return Local_enuErrorState;

}

/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/

