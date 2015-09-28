#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CircleLinkList.h"

//定义一个业务结构体
typedef struct _tag_value
{
	TCircleLinkListNode node;
	int v;

}Tvalue;


void main01()
{
	int i = 0;
	Tvalue v1,v2,v3,v4,v5;
	CircleLinkList *list = NULL;
	Tvalue* tlist= NULL;
	TCircleLinkListNode *Pcn = NULL;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;


	//创建一个循环链表头
	list =  CircleLinkList_Create();
	
	//向链表中的pos位置插入一个节点（pos的值从0开始）
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v1, 0);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v2, 1);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v3, 2);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v4, 3);	
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v5, 4);

	//输出刚刚插入的节点
	 for ( i=0; i < CircleLinkList_Length(list); i++)
	 { 
		 //获取循环链表中的第i个节点
          tlist = (Tvalue*)CircleLinkList_Get(list, i);
		  printf("%d ",tlist->v);
	 }
	 printf("\n");
	 //删除链表中的pos位置上的节点（pos的值从0开始）
	// Pcn =  CircleLinkList_Delete(list, 0);
	 //Pcn =  CircleLinkList_Delete(list, 1);
	 //Pcn =  CircleLinkList_Delete(list, 2);

	// for ( i=0; i < CircleLinkList_Length(list); i++)
	// { 
		 //获取循环链表中的第i个节点
	//	 tlist = (Tvalue*)CircleLinkList_Get(list, i);
	//	 printf("%d ",tlist->v);
	// }
	 //输出结果为2，4

	 //删除链表节点
	 Pcn =  CircleLinkList_Get(list, 0);
	 Pcn =  CircleList_DeleteNode(list, Pcn);

	 for ( i = 0; i < CircleLinkList_Length(list); i++)
	 { 
		 //获取循环链表中的第i个节点
		 tlist = (Tvalue*)CircleLinkList_Get(list, i);
		 printf("%d ",tlist->v);
	 }

	 ////重置游标，使其回到初始状态
	 //CircleList_Reset(list);

	 ////获取当前游标的值
	 //CircleList_Current(list);

	 ////游标下移一个单位
  //   CircleList_Next(list);


	 //设置链表回最初的状态(循环链表只有头结点的状态)
	 CircleLinkList_Clear(list);

	//销毁（只需）链表头，其它业务节点的声明周期由测试函数决定
	 CircleLinkList_Destroy(list);



	//API ADD 增加的API函数






	



  system("pause");
}