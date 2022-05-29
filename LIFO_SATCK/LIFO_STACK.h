#ifndef LIFO_STACK_H_
#define LIFO_STACK_H_
#include"TYPE.h"
typedef struct{
	
	u32 u32Length;
	u32 u32Count;
	u8* u32Ptr_Base;
	u8* u32Ptr_Head;
	
	
}LIFO_BUFFER_t;
#define LIFO_Buffer_Lenth  5
typedef enum{
	LIFO_No_Erorr,
	LIFO_Full,
	LIFO_Empty,
	LIFO_NULL,
	LIFO_NOT_Empty,
	LIFO_NO_Erorr
}LIFO_Status;

LIFO_Status  LIFO_Enum_STATUSItem(LIFO_BUFFER_t* BUFFER);
LIFO_Status LIFO_Enum_AddItem(LIFO_BUFFER_t* BUFFER,u8 u8Item);
LIFO_Status  LIFO_Enum_GetItem(LIFO_BUFFER_t* BUFFER,u8* u8Item);
#endif
