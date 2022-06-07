#ifndef LINKED_LIST_CONFIG_H_
#define LINKED_LIST_CONFIG_H_
#include"TYPE.h"
#define DPRINTF(x);        printf(x);
struct sstudent_Data{
	u8 name[100];
	u32 ID;
	u32 u32TotalDegree;
	u8 u8Hight;
	
	
	};
struct SStudent_FILE{
	struct sstudent_Data SData_NestedS;
	u32 u32File_Index;
	struct SStudent_FILE* PSNextData;
	
	
	
};

void file_ViodData(struct SStudent_FILE* SPNewFile);
void ADD_voidFile(void);/*add element*/
u8 Remove_u8Element(void); /*remove elemet*/
void ViewAll_voidList(); /*show all elemets*/
void DeleteVoid_All(void); /*remove all elemets*/
u8 Nth_node(u32 Number_Element); /*show certain element*/
u8 Count_voidlist(void);/*number of files on list*/
u8 GetNumber_u8ReversNode(u32 u32NodeNumber); /*to get node number reversely*/
u8 Get_MiddelElement(void); /*to get middel node in list*/
u8 Reverse_nodes(void);
/*void GtVoid_ReversNodes();*/
void Gt1Void_ReversNodes();/*To reverse list*/
#endif