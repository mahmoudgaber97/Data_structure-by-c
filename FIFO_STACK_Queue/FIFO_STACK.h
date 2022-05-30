#ifndef LIFO_STACK_H_
#define LIFO_STACK_H_
#include"TYPE.h"

#define GDatatype   u8  /*u can configer by use ( u8 or u16 ,u32 ) and etc*/
#define Print_Data_Type  "%d" /*u can changes data accordding data type  */
typedef struct{
	
	GDatatype u32Length;
	GDatatype u32Count;
	GDatatype* u32Ptr_Base;
	GDatatype* u32Ptr_Head;
	GDatatype* u32Ptr_Tail;
	
	
}FIFO_BUFFER_t;
#define FIFO_Buffer_Lenth  7
typedef enum{
	FIFO_No_Erorr,
	FIFO_Full,
	FIFO_Empty,
	FIFO_NULL,
	FIFO_NOT_Empty,
	FIFO_Erorr
}FIFO_Status;

FIFO_Status FIFO_EnumInti(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO,GDatatype u32buffer_lenth);
FIFO_Status FIFO_EnumFull(FIFO_BUFFER_t* Sbuffer);
FIFO_Status FIFO_Enqueue(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO_DATA );
FIFO_Status FIFO_Dequeue(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO_DATA );


#endif
