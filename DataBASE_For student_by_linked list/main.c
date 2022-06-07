#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"TYPE.h"
#include"linked_list_config.h"


	
int main(){
	u8 u8ChasStudent;
	u32 u32numberElement;
	while(getch()!='E'){
		printf("\n chose from following list below : ");
		printf("\n 1: TO ADD FILE ");
		printf("\n 2: TO remove FILE ");
		printf("\n 3: show certain element");
		printf("\n 4: show all elements");
		printf("\n 5: remove all elemets");
		printf("\n 6: number of files on list");
		printf("\n 7: to get middel node in list");
		printf("\n 8: To reverse list");
		printf("\n 9: Enter 'E' to exit \n");
		
		scanf("%d",&u8ChasStudent);
		
		switch(u8ChasStudent){
		case 1:
		ADD_voidFile();
		break; 
		case 2:
		 Remove_u8Element();

		break;
		
		case 3:
		printf("enter number of user: ");
		scanf("%d",&u32numberElement);
		 Nth_node(u32numberElement);
		break;
		case 4:
		ViewAll_voidList();
		break;
		case 5:
		DeleteVoid_All();
		break;
		case 6:
		 Count_voidlist();
		break;
		case 7:
		Get_MiddelElement();
		break;
		case 8:
		Gt1Void_ReversNodes();
		break;
		case 9:
		ViewAll_voidList();
		break;
	}
	}
	
	return 0;
	
}