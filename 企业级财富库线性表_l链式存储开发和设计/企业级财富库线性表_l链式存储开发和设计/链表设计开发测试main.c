#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"
typedef struct _teacher
{
   TlinkListNode *node;
   int age;
   char name[64];
}Teacher;

//测试程序也是一门技术
void main()
{
    Teacher t1,t2,t3;
	int i = 0;
	linklist *list = NULL;
	TlinkListNode *tlist = NULL;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	list = linkList_Create();

	 // linkList_Destroy(list);

	linkList_Insert(list,(TlinkListNode *)&t1,0);
	//printf("%d ",((Teacher *)LinkList_Get(list,0))->age);
	linkList_Insert(list,(TlinkListNode *)&t2,0);
	//printf("%d ",((Teacher *)LinkList_Get(list,0))->age);
	linkList_Insert(list,(TlinkListNode *)&t3,0);
	//printf("%d ",((Teacher *)LinkList_Get(list,2))->age);
	for ( i = 0; i<linkList_Length(list); i++)
	{
			tlist =  LinkList_Get(list, i);
			printf("%d ",((Teacher *)tlist)->age);
	}

	tlist =  LinkList_Delete( list,0);
	linkList_Clear(list);
	linkList_Destroy(list);
	system("pause");
}