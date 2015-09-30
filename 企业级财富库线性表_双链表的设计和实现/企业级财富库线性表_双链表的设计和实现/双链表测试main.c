#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dLinkList.h"
//定义一个业务节点结构体数据类型
typedef struct _teacher
{
	TDLinkListNode  node;
	int age;
}teacher;

//测试程序
void main()
{
	teacher t1,t2,t3,t4;
	DLinkList *list = NULL;
	TDLinkListNode *tlist = NULL;
	teacher *pt = NULL;
	int length;
	int i = 0;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;

	//创建一个双链表
	list = DLinkList_Create();

	//节点的插入
	
	
		DLinkList_Insert(list,(TDLinkListNode *)&t1,0);
		DLinkList_Insert(list,(TDLinkListNode *)&t2,1);
	    DLinkList_Insert(list,(TDLinkListNode *)&t3,2);
		DLinkList_Insert(list,(TDLinkListNode *)&t4,3);

	////节点的输出,首先获取双链表的长度
	length  = DLinkList_Length(list);
	for (i = 0; i<length; i++ )
	{
		pt = (teacher *)DLinkList_Get(list,i);
		printf("%d ",pt->age);
	}

	//链表节点的删除方法一（删除第一个节点）
	DLinkList_Delete(list,0);

	//链表节点删除方法二（再次删除链表的第一个节点）
	tlist = DLinkList_Get(list,0);
	DLinkList_DeleteNode(list,tlist);
	printf("\n");
	for (i = 0; i<2; i++ )
	{
		pt = (teacher *)DLinkList_Get(list,i);
		printf("%d ",pt->age);
	}
	//针对双链表的游标二进行的一系列操作   
	tlist = DLinkList_Reset(list);       //重置游标并返回游标的当前位置的指针
	tlist = DLinkList_Current(list);     //当前的游标的位置并返回游标的当前位置的指针
	tlist = DLinkList_Next(list);        //游标后移并返回游标的上一个位置的指针
	tlist = DLinkList_Pre(list);
	//使链表回到初始状态
	DLinkList_Clear(list);

	//销毁链表
	DLinkList_Destroy(list);
	system("pause");
}