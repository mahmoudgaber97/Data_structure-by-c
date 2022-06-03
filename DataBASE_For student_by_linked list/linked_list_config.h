#ifndef LINKED_LIST_CONFIG_H_
#define LINKED_LIST_CONFIG_H_
#include"TYPE.h"
#define DPRINTF(x);        printf(x);
struct sstudent_Data{
	u8 u8Hight;
	char name[100];
	u32 u32TotalDegree;
	u32 ID;
	};
struct SStudent_FILE{
	struct sstudent_Data SData_NestedS;
	struct SStudent_FILE* PSNextData;
	
	
};

void file_ViodData(struct SStudent_FILE* SPNewFile);
void ADD_voidFile(void);
u8 Remove_u8Element(void);
void ViewAll_voidList();
void DeleteVoid_All(void);
#endif