


#include"TYPE.h"
#include"LIFO_STACK.h"






#include"LIFO_STACK.h"



/*This function using to chack status of LIFO stack.*/

LIFO_Status LIFO_Enum_STATUSItem(LIFO_BUFFER_t* BUFFER){
	
	
	/*chack if LIFO AVALIBAL OR NOT*/
	if(!BUFFER||!BUFFER-> u32Ptr_Base||!BUFFER->u32Ptr_Head)
		return LIFO_NULL;
	/*chacking if LIFOstack is full or not*/
	if(BUFFER->u32Ptr_Head >=(BUFFER->u32Ptr_Base+BUFFER->u32Length))
		return LIFO_Full;
	else 
		return LIFO_NOT_Empty;
}
/*This function using to ADD items on LIFO stack.*/

LIFO_Status  LIFO_Enum_AddItem(LIFO_BUFFER_t* BUFFER,u8 u8Item){
	/* chack status of LIFO stack.*/
	if((LIFO_Enum_STATUSItem(BUFFER))!=LIFO_NOT_Empty)
		return (LIFO_Enum_STATUSItem(BUFFER));  /*RETURN STAT*/
	/*ADD NEW ITEM*/
	else{
		*(BUFFER->u32Ptr_Head)=u8Item;
		BUFFER -> u32Ptr_Head++ ;
		BUFFER->u32Count++;
		return LIFO_No_Erorr;

}
}

	LIFO_Status  LIFO_Enum_GetItem(LIFO_BUFFER_t* BUFFER,u8* u8Item){

			/*chack if LIFO AVALIBAL OR NOT*/
			if(!BUFFER||!BUFFER->u32Ptr_Base||!BUFFER->u32Ptr_Head)
				return LIFO_NULL;
			/*chack if LIFO IS EMPTY OR NOT*/
			if(BUFFER->u32Ptr_Base==BUFFER->u32Ptr_Head)
				return LIFO_Empty;

			/*GET ITEM*/
			  BUFFER->u32Ptr_Head--;
		*u8Item=*(BUFFER->u32Ptr_Head);
			  BUFFER->u32Count--;
			return LIFO_NO_Erorr;

		}
