#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linked_list_config.h"



struct SStudent_FILE *SGPFirstElement=NULL;
void file_ViodData(struct SStudent_FILE* SPNewFile){
		
		DPRINTF(" enter name of student ");
		printf("\n");
		scanf("%s",SPNewFile->SData_NestedS.name);
		
		DPRINTF("\n enter ID  ");
		scanf("%d",&SPNewFile->SData_NestedS.ID);
		DPRINTF("\n enter Degree:   ");
		scanf("%d",&SPNewFile->SData_NestedS.u32TotalDegree);
		DPRINTF("\n enter Hight:   ");
		scanf("%d",&SPNewFile->SData_NestedS.u8Hight);
		
		
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
		printf("\n ID is %d",PCurrent_Element->SData_NestedS.ID);
		printf("\n name is %s",PCurrent_Element->SData_NestedS.name);
		printf("\n Dgree  is %d",PCurrent_Element->SData_NestedS.u32TotalDegree);
		printf("\n hight   is %d",PCurrent_Element->SData_NestedS.u8Hight);
	
		PCurrent_Element=PCurrent_Element->PSNextData;
	}
	}
	
}

void DeleteVoid_All(){
	struct SStudent_FILE* PCurrent_Element=SGPFirstElement;
	if(PCurrent_Element)
	DPRINTF("Student list is empty ");
    while(PCurrent_Element){
		PCurrent_Element=PCurrent_Element->PSNextData;
		free(PCurrent_Element);
		
	}
	
	
}