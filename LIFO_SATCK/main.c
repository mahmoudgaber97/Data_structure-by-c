#include"TYPE.h"
#include"LIFO_STACK.h"
#include"stdio.h"
#include"stdlib.h"


int main(){
	
	u32 u32Counter;
	u8 u8Temp;
	u8 u8Static_BUFFER[ LIFO_Buffer_Lenth];
	LIFO_BUFFER_t Sfrist_BUFFER,Ssecond_BUFFER;
	Sfrist_BUFFER.u32Ptr_Base=(u8*)malloc(LIFO_Buffer_Lenth); /*creating dynamic array*/
	Sfrist_BUFFER.u32Ptr_Head=Sfrist_BUFFER.u32Ptr_Base;    /*making base pointer and head pointer point to first location ion the stack*/
	Sfrist_BUFFER.u32Length=LIFO_Buffer_Lenth; /*lenth is equal 5 and u can change it by scanf(); dut to its can change @run time*/
	Sfrist_BUFFER.u32Count=0;
	for(u32Counter=0;u32Counter<LIFO_Buffer_Lenth;u32Counter++){
		
		LIFO_Enum_AddItem(&Sfrist_BUFFER,u32Counter);
		printf("%d\n",u32Counter);
		Sfrist_BUFFER.u32Count++;
	}
	for(u32Counter=0;u32Counter<LIFO_Buffer_Lenth;u32Counter++){
		
		LIFO_Enum_GetItem(&Sfrist_BUFFER,&u8Temp);
		printf("%d\n",u8Temp);
		Sfrist_BUFFER.u32Count--;
	}
	
	Ssecond_BUFFER.u32Ptr_Base=u8Static_BUFFER;
	Ssecond_BUFFER.u32Ptr_Head=Ssecond_BUFFER.u32Ptr_Base;
	Ssecond_BUFFER.u32Length=LIFO_Buffer_Lenth;
	Ssecond_BUFFER.u32Count=0;
	
	for(u32Counter=0;u32Counter<LIFO_Buffer_Lenth;u32Counter++){
		
		LIFO_Enum_AddItem(&Sfrist_BUFFER,u32Counter);
		printf("%d\n",u32Counter);
		Sfrist_BUFFER.u32Count++;
	}
	for(u32Counter=0;u32Counter<LIFO_Buffer_Lenth;u32Counter++){
		
		LIFO_Enum_GetItem(&Sfrist_BUFFER,&u8Temp);
		printf("%d\n",u8Temp);
		Sfrist_BUFFER.u32Count--;
	}
	return 0;
}


/*very important hit to compile this file at notepad++ write gcc LIFO_STACK_Programming.C MAIN.C -O I.EXE*/