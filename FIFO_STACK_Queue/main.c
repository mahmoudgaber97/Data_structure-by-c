#include<stdio.h>
#include"FIFO_STACK.h"
#include"type.h"

#include"stdlib.h"
int main(){
	GDatatype FIFO_DBuffer_Lenth;
	GDatatype Memory[FIFO_Buffer_Lenth ];
	FIFO_BUFFER_t SBuffer1, SBuffer2;
	GDatatype Counter,Item;
	SBuffer2.u32Ptr_Base=(GDatatype*)malloc( FIFO_DBuffer_Lenth*sizeof(GDatatype));
	FIFO_EnumInti(&SBuffer1,Memory,FIFO_Buffer_Lenth);
	for(Counter=0;Counter<FIFO_Buffer_Lenth;Counter++){
		printf("enter your element %d====>  ",Counter+1);
		scanf("%d",&Item);
		FIFO_Enqueue(&SBuffer1,&Item);
	}
	for(Counter=0;Counter<FIFO_Buffer_Lenth;Counter++){
		printf("your element %d is ====>  ",Counter+1);
		FIFO_Dequeue(&SBuffer1,&Item);
	
	}
	
	

	return 0;
}