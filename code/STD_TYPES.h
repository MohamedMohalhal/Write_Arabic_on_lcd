/*****************************************************************************/
/* Title        	: 	STD TYPES File									     */
/* File Name    	: 	STD_TYPES.h  		                                 */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/08/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

 #ifndef   STD_TYPES_H
 #define   STD_TYPES_H
 
 
typedef  unsigned char      uint8    ;
typedef  unsigned short int uint16   ;
typedef  unsigned long  int uint32   ;
typedef  signed char        sint8    ;
typedef  signed short  int  sint16   ;
typedef  signed long   int  sint32   ;
typedef  float              float32  ;
typedef  double             float64  ;
typedef  long double        float128 ;


typedef enum {
	ERORR_STD_TYPES_OK,
	ERORR_STD_TYPES_NOK,
	ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ,
	ERORR_STD_TYPES_NOK_PARAM_NULL_POINTER  ,
	ERORR_STD_TYPES_NOK_CONFIG_ERROR  
}tenuErrorStatus;
#define  NULL_PTR    ((void *)0)

#endif 
/*** !comment : End of gaurd [STD_TYPES_H] ***********************************/


