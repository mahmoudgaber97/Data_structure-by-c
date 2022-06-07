#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linked_list_config.h"

u32 u32Index=0;

struct SStudent_FILE *SGPFirstElement=NULL;
void file_ViodData(struct SStudent_FILE* SPNewFile){
		
		printf("enter name of student ");
		scanf("%s",SPNewFile->SData_NestedS.name);
		
		DPRINTF("\n enter ID  ");
		scanf("%d",&SPNewFile->SData_NestedS.ID);
		DPRINTF("\n enter Degree:   ");
		scanf("%d",&SPNewFile->SData_NestedS.u32TotalDegree);
		DPRINTF("\n enter Hight:   ");
		scanf("%d",&SPNewFile->SData_NestedS.u8Hight);
		u32Index++;
		SPNewFile->u32File_Index=u32Index;
		
		
	} 
	

	
	void ADD_voidFile(void){
		struct SStudent_FILE *pSLastFile,*PSNewFile;
	if(SGPFirstElement==NULL){
		PSNewFile=(struct SStudent_FILE*)malloc(sizeof(struct SStudent_FILE));
			SGPFirstElement=PSNewFile;
	}
	else
		
		PSNewFile=(struct SStudent_FILE*)malloc(sizeof(struct SStudent_FILE));
	    pSLastFile=SGPFirstElement;
	    while( pSLastFile->PSNextData)
			pSLastFile=pSLastFile->PSNextData;	
		file_ViodData(PSNewFile);
			pSLastFile->PSNextData=PSNewFile;
	        PSNewFile->PSNextData=NULL;
	
	}
	
	u8 Remove_u8Element(){
		
		u32 u32Get_ID;
		printf("Enter ID which requir to removes : ");
		scanf("%d",&u32Get_ID);
		if(SGPFirstElement) // check if list is empty or not
		{
			struct SStudent_FILE* PSelect_Student=SGPFirstElement;
			struct SStudent_FILE* Pprev_Student=NULL;
			while(PSelect_Student)/*Alwas its true but use to loop at linkedlist*/
			{
				if(PSelect_Student->SData_NestedS.ID==u32Get_ID){ /*if pointer points at block u want to remove it.*/
				if(Pprev_Student)                   /*if prevous pointer point to null its means first block is requir to remove*/
					Pprev_Student->PSNextData=PSelect_Student-> PSNextData; /*to store address of next block after deleting block*/
				else
			SGPFirstElement=PSelect_Student-> PSNextData;	/*makes first pointer (SGPFirstElement) point to next*/
			free(PSelect_Student); /*remove block was selected*/
			printf("student owns ID %d has been removed ",u32Get_ID);
			return 1;  /* to leaving function*/
				}
			
				Pprev_Student=PSelect_Student; /*maks priveous pointer flowes select pointer. */
				PSelect_Student=PSelect_Student->PSNextData;  /*check block*/
			}
			
			
			
			
		}
		
		printf("ID %d does not exist",u32Get_ID); 
		return 0; /*can not find it*/
	}


void ViewAll_voidList(){
	u8 u8Counter=1;
	
	struct SStudent_FILE* PCurrent_Element=SGPFirstElement;
	if(SGPFirstElement==NULL){
		DPRINTF("list is already empty ");
	}
	else{
	while(PCurrent_Element){
		printf("\n A number in list %d",u8Counter);
		printf("\n ID=====> %d",PCurrent_Element->SData_NestedS.ID);
		printf("\n name===> %s",PCurrent_Element->SData_NestedS.name);
		printf("\n Dgree==>%d",PCurrent_Element->SData_NestedS.u32TotalDegree);
		printf("\n hight=> %d",PCurrent_Element->SData_NestedS.u8Hight);
	u8Counter++;
		PCurrent_Element=PCurrent_Element->PSNextData;
	}
	}
	
}

void DeleteVoid_All(){
	struct SStudent_FILE* PCurrent_Element=SGPFirstElement;
	struct SStudent_FILE* PCurrent1_Element=SGPFirstElement->PSNextData;
	if(PCurrent_Element){
    while(PCurrent_Element){
		PCurrent1_Element=PCurrent_Element;
			free(PCurrent_Element);
		PCurrent_Element=PCurrent_Element->PSNextData;
	PCurrent1_Element=PCurrent1_Element->PSNextData;
		
	}
	DPRINTF("Student list is empty ");
	}
	else {
		
		printf("list alrady is empty ");
	}
	
	
}



u8 Nth_node(u32 Number_Element){
	struct SStudent_FILE* SCurrent_File=SGPFirstElement;
	
	if(SGPFirstElement)/*chack empty*/
	{
		while(SCurrent_File)
		{
			if(SCurrent_File->u32File_Index==Number_Element){
				
		printf("\n ID is %d",SCurrent_File->SData_NestedS.ID);
		printf("\n name is %s",SCurrent_File->SData_NestedS.name);
		printf("\n Dgree  is %d",SCurrent_File->SData_NestedS.u32TotalDegree);
		printf("\n hight   is %d",SCurrent_File->SData_NestedS.u8Hight);
				
				return 1;
			}
			
			else 
				SCurrent_File=SCurrent_File->PSNextData;
				
			
		}
		
	}
	
	else printf("there are not files");
	return 0;
	
}

u8 Count_voidlist(){
	struct SStudent_FILE* PCurrent_Node=SGPFirstElement;
	u16 u16Counter=0;
	if(PCurrent_Node)
	{
		while(PCurrent_Node){
			 u16Counter++;
		PCurrent_Node=PCurrent_Node->PSNextData;
		
	}
	printf("number of nodes is equal=====> %d FILES", u16Counter);
	return 1;
}
	else{
		printf("there are not nodes!!!");
		return 0;
	}
	
}


u8 GetNumber_u8ReversNode(u32 u32NodeNumber){
	struct SStudent_FILE* PCurrent_LNode=SGPFirstElement;
	struct SStudent_FILE* SPPriv=SGPFirstElement;
	u32 u32Counter=1;
	while(PCurrent_LNode->PSNextData){
		PCurrent_LNode=PCurrent_LNode->PSNextData;
		
		u32Counter++;
	}
	
	
	while(SPPriv){
		SPPriv->u32File_Index=u32Counter;
		SPPriv=SPPriv->PSNextData;
		u32Counter--;
		
	}
	
	
	SPPriv=SGPFirstElement;
	while(SPPriv)
	{
	
		
	   if(SPPriv->u32File_Index==u32NodeNumber){
		printf("\n ID is %d",SPPriv->SData_NestedS.ID);
		printf("\n name is %s",SPPriv->SData_NestedS.name);
		printf("\n Dgree  is %d",SPPriv->SData_NestedS.u32TotalDegree);
		printf("\n hight   is %d",SPPriv->SData_NestedS.u8Hight);
		return 1;
	   }
	 SPPriv=SPPriv->PSNextData;
}
printf("this index does not exist ");
return 0;
}


u8 Get_MiddelElement(void){
	
	struct SStudent_FILE* PCurrent_LNode=SGPFirstElement;
	
	u32 u32Counter=1;
	u32 u32Avg1,u32Avg2;
	
	if(SGPFirstElement!=NULL){
	while(PCurrent_LNode->PSNextData){
		PCurrent_LNode=PCurrent_LNode->PSNextData;
		
		u32Counter++;
	}
	if(u32Counter&1) /*Odd Number*/{
	u32Avg1=(u32Counter+1)/2;
	printf("element is =====\n");
	GetNumber_u8ReversNode(u32Avg1);
	return 2;
	}
	else
	{
		u32Avg1=u32Counter/2;
		u32Avg2=u32Avg1+1;
		printf("meddel elements are two ");
		printf("first one is ====\n");
		GetNumber_u8ReversNode(u32Avg1);
		printf("second one is ====\n");
		GetNumber_u8ReversNode(u32Avg2);
		return 1;
	}
	}
	
	printf("DATA BASE IS EMPTY !!!");
	return 0;
	
}

/*
void GtVoid_ReversNodes(){
	
	struct SStudent_FILE* PSteprev=SGPFirstElement; 
	PSteprev->PSNextData=NULL;
	struct SStudent_FILE* PStepCurrent=SGPFirstElement->PSNextData; 
	struct SStudent_FILE* PstepNext=PStepCurrent->PSNextData;
	PSteprev->PSNextData=NULL; 
	while(PstepNext->PSNextData)
	{
		
		PstepNext->PSNextData=PStepCurrent;
		PStepCurrent->PSNextData=PSteprev;
		
	
		PSteprev+=3;
		PStepCurrent+=3;
		PstepNext+=3;
		
		
	}
	
	PstepNext=SGPFirstElement;
	 ViewAll_voidList();
}
*/
void Gt1Void_ReversNodes(){
	
	struct SStudent_FILE* Pprevious=SGPFirstElement; /*point to first node in linkedlist*/
	struct SStudent_FILE* Phead=SGPFirstElement;   /*point to first node in linkedlist*/
	struct SStudent_FILE* Pcurrent=SGPFirstElement->PSNextData; /*point to second node */
	struct SStudent_FILE* PNext;          
			Pprevious->PSNextData=NULL; 
	
	while(Pcurrent){
	PNext=Pcurrent->PSNextData;
	Pcurrent->PSNextData=Pprevious;
	Pprevious=Pcurrent;
	Pcurrent=PNext;
	
}
SGPFirstElement=Pprevious;

 ViewAll_voidList();
}


