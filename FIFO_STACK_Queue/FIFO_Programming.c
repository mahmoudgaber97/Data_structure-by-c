#include<stdio.h>
#include"FIFO_STACK.h"

FIFO_Status FIFO_EnumInti(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO,GDatatype u32buffer_lenth){
	
	
	 /*Base,Head,Tail pointers refere to first address of stack*/
	Sbuffer->u32Ptr_Base=FIFO;
	Sbuffer->u32Ptr_Head=Sbuffer->u32Ptr_Base; 
	Sbuffer->u32Ptr_Tail=Sbuffer->u32Ptr_Base;
	/*Get Lenth of buffer*/
	Sbuffer->u32Length=u32buffer_lenth;
	Sbuffer->u32Count=0;
	/*chack if buffer has erorr or not*/
	if(Sbuffer->u32Ptr_Base && Sbuffer->u32Length )
		return FIFO_No_Erorr;
	else
		return FIFO_Erorr;
}

/*chack if queue is full or not*/
FIFO_Status FIFO_EnumFull(FIFO_BUFFER_t* Sbuffer){
	/*chack FIFO is exsist or not.*/
		if(!(Sbuffer->u32Ptr_Base)||(!Sbuffer->u32Ptr_Head)||(!Sbuffer->u32Ptr_Tail))
		return FIFO_NULL;
	/*chack if queue is full or not*/
	if(Sbuffer->u32Count > Sbuffer->u32Length ){
		
		printf("its full");
		return FIFO_Full;
	}
	else
	return FIFO_No_Erorr;
}

/*TO ADD ELEMENTS FOR QUEUE*/
FIFO_Status FIFO_Enqueue(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO_DATA ){
	/*Chack if queue is full or not*/
	if((FIFO_EnumFull(Sbuffer))== FIFO_No_Erorr)
	{
		*(Sbuffer->u32Ptr_Head)=*FIFO_DATA;  /*ADD data to empty buffer element*/
	(Sbuffer->u32Count)++;
	/*if head pointer access to end of queue , return it to start point*/
		if((Sbuffer->u32Ptr_Head)>=(Sbuffer->u32Ptr_Base+Sbuffer->u32Length)){ 
			
			Sbuffer->u32Ptr_Head=Sbuffer->u32Ptr_Base;
			return FIFO_No_Erorr;
		}
		else 
			Sbuffer->u32Ptr_Head++;
		
	}

		return (FIFO_EnumFull(Sbuffer)); /*if buffer has erorr return erorr type*/
	
}


FIFO_Status FIFO_Dequeue(FIFO_BUFFER_t* Sbuffer,GDatatype* FIFO_DATA ){
	/*chack if pointers of Sbuffer refer to null or not*/
	if(!Sbuffer->u32Ptr_Base||!Sbuffer->u32Ptr_Head||!Sbuffer->u32Ptr_Tail)
		return FIFO_NULL;
	
	
	/*if counter is equal zero its mean queue is empty*/
	if(Sbuffer->u32Count==0)
		return FIFO_Empty;
	
	/*get next element when reading the data that refered by tail pointer*/
	*FIFO_DATA=*(Sbuffer->u32Ptr_Tail);
	printf("%d \n",*FIFO_DATA);
	Sbuffer->u32Count--;
	
	/*return tail to start point when it is referring to end*/
	if((Sbuffer->u32Ptr_Tail)>=(Sbuffer->u32Ptr_Base+Sbuffer->u32Length))
	{
		Sbuffer->u32Ptr_Tail=Sbuffer->u32Ptr_Base;	
	}
	
	else 
		Sbuffer->u32Ptr_Tail++;
	return FIFO_No_Erorr;
}
