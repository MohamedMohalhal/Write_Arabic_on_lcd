/*****************************************************************************/
/* Title        	: 	BIT MATH File									     */
/* File Name    	: 	BIT_MATH.h  		                                 */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/08/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg , BitNo) ((Reg) |=   (1<<(BitNo)))
#define CLR_BIT(Reg , BitNo) ((Reg) &=  ~(1<<(BitNo)))
#define TGL_BIT(Reg , BitNo) ((Reg) ^=   (1<<(BitNo)))
#define GET_BIT(Reg , BitNo) (((Reg)>>(BitNo)) & 0x01)

#endif
