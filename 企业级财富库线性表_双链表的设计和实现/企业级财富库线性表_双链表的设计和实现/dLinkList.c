#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dLinkList.h"
//定义一个双链表结构体数据类型
typedef struct _tag_DLinkList
{
	TDLinkListNode header;    //为双链表定义一个头
	TDLinkListNode *slider;   //双链表的游标
	int length;

}TDLinkList;

//为实现这一整套API，首先必须打一个桩
void* DLinkList_Create()
{
	TDLinkList *list = (TDLinkList *)malloc(sizeof(TDLinkList));
	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		printf("func DLinkList_Create malloc memory is failed %d",ret);
		return NULL;
	}
	list->header.next = NULL;
	list->header.pre = NULL;
	list->slider = NULL;
	list->length = 0;
	return list;
}

//销毁（只需）链表头，其它业务节点的声明周期由测试函数决定
void DLinkList_Destroy(DLinkList *list)
{
	//先做异常处理
	int ret = 0;
	if (list == NULL)
	{   //异常提醒标志
		ret = -1;
		printf("func CircleLinkList_Destroy err %d",ret);
		return ;
	}
	free(list);
}

//设置链表回最初的状态
void DLinkList_Clear(DLinkList *list)
{
	//先做异常处理
	int ret = 0;
	//定义一个指向循环链表头结点的指针
	TDLinkList *tlist = NULL;
	tlist = (TDLinkList *)list;
	if ( list == NULL)
	{
		ret = -1;
		printf("func CircleLinkList_Clear err %d",ret);
		return ;
	}
    //成员变量全部回到最初的状态
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
}

//获取链表的长度（链表头除外）
int DLinkList_Length(DLinkList *list)
{
	//先做异常处理
	int ret = 0;
	TDLinkList *tlist = NULL;
	tlist = (TDLinkList  *)list;
	if (list == NULL)
	{
		ret =-1;
		printf("func CircleLinkList_Length err %d",ret);
		return ret;
	}
	//返回链表的长度
	return tlist->length;
}

//向链表中的pos位置插入一个节点（pos的值从0开始）
int DLinkList_Insert(DLinkList *list,TDLinkListNode*node, int pos)
{
	//先做异常处理
	int ret = 0, i=0;	
	TDLinkList* sList = (TDLinkList*)list;
	//TDLinkListNode* last = NULL;
	TDLinkListNode* current = NULL;
	TDLinkListNode* pnext = NULL;
	if (list == NULL || node == NULL || pos < 0 || pos > sList->length)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return ret;
	}

	{
		//	//环境初始化
		current = (TDLinkListNode*)sList;
		//先找到pos位置的前一个位置
		for(i=0; i < pos; i++)
		{
			current = current->next;
		}                                     //此时current指向待插入位置的前一个位置
		   pnext = current->next;

	 //普通插入的核心代码步骤1-2
		  current->next = node;
		  node->next= pnext;
     //普通插入的核心代码步骤3-4

	   if (pnext != NULL)                     //若非最后一个位置则要处理后面节点前驱指针成员与待插入节点的关系（若是则不需要处理这层关系）
	   {
		      pnext->pre  = node;
			  node->pre = current;
	   }
	         
	     //若第一次插入节点即只有头结点的头插法
		if( sList->length == 0 )
		{
		   //游标的设置
			sList->slider = node;
			//node->pre = NULL;
		}	

		//头插法
		if( current == (TDLinkListNode*)sList)
		{
			//做相应的处理
			node->pre = NULL;        		
		}

			sList->length++;
	}
	return 0;
}

//删除链表中的pos位置上的节点（pos的值从0开始）
TDLinkListNode *DLinkList_Delete(DLinkList *list,int pos)
{
	//先做异常处理
	int ret = 0, i=0;	
	TDLinkList* sList = (TDLinkList*)list;
	//TDLinkListNode* last = NULL;
	TDLinkListNode* current = NULL;
	TDLinkListNode* pnext = NULL;
	TDLinkListNode*tmp = NULL;
	if (list == NULL ||pos < 0 || pos >= sList->length)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return NULL;
	}

	{
		//	//环境初始化
		current = (TDLinkListNode*)sList;
		//先找到pos位置的前一个位置
		for(i=0; i < pos; i++)
		{
			current = current->next;
		}                                     //此时current指向待插入位置的前一个位置

		tmp = current->next;                //pnext是指向待删除节点的指针
		pnext = tmp->next;

		//普通删除的核心代码步骤1
		current->next = pnext;

		//普通删除的核心代码步骤2
		//如果删除的不是最后一个节点（那就是中间节点或链表的第一个节点）
		if (pnext != NULL)                  
		{
			current = pnext->pre;
			if (current == (TDLinkListNode *)sList )
			{
				pnext->pre = NULL;
			}
		}
		//如果删除的节点正好是游标指向的节点，则游标需要下移一个单位
		if (sList->slider = tmp)
		{
			sList->slider = pnext;
		}
		sList->length--;
	}
	return tmp;
}

//获取链表中的pos位置上的节点值，pos的值从0开始
TDLinkListNode *DLinkList_Get(DLinkList *list,int pos)
{
	//先做异常处理
	TDLinkList *tlist = (TDLinkList * )list;
	TDLinkListNode *current = NULL;
	TDLinkListNode * tmp = NULL;
	int i = 0;
	int ret = 0;

	//如果参数传递错误
	if (tlist == NULL || pos < 0|| pos>= tlist->length )
	{ 
		ret = -1;
		printf("func CircleLinkList_Get parameter err %d or linklist has no this node",ret);
		return NULL;
	}

	//如果链表只有头结点
	if ( tlist->length <=0 )
	{
		printf("链表只有头结点，还没有业务节点\n");
		return NULL;
	}
	//初始化环境
	current = &tlist->header;
	//找到pos位置即待删除节点的前一个节点
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	//找到待删除节点的位置
	tmp = current->next;
	return tmp;	
}

//API ADD 增加的API函数

//根据节点的地址删除节点的值，这个函数需要调用DLinkList_Delete()这个函数
TDLinkListNode* DLinkList_DeleteNode(DLinkList* list, TDLinkListNode* node)
{
	//先做异常处理
	int ret = 0;
	int i = 0;
	TDLinkList *slist = (TDLinkList *)list;
	TDLinkListNode *current = NULL;
	TDLinkListNode *tmp = NULL;

	if (list == NULL || node == NULL)
	{
       ret = -1;
	   printf("func DLinkList_DeleteNode parameter err %d",ret);
	   return NULL;
	}
	if (DLinkList_Length(list) <=0 )
	{
		printf("this Dlinklist has no node yet\n");
		return NULL;
	}
	//环境初始化
	current = (TDLinkListNode *)slist;
	for (i = 0; i < DLinkList_Length(list); i++)
	{
        if (current->next == node )
        {
			tmp = current->next;
			break;
        }
		current = current->next;
	}
	DLinkList_Delete(list,i);             //该函数内部已经包含了--操作；
	return node;
}

//重置游标，使其回到初始状态，并返回游标的值
TDLinkListNode* DLinkList_Reset(DLinkList* list)
{
	//先做异常处理
	int ret = 0;
	TDLinkList *tlist =(TDLinkList *)list;
	TDLinkListNode *tmp = NULL;
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Reset err %d",ret);
		return NULL;
	}
	tmp =  &tlist->header;
	//游标位置重新回到初始化的位置
	tlist->slider = tmp->next;
	return tlist->slider;
}

//获取当前游标值
TDLinkListNode* DLinkList_Current(DLinkList* list)
{
	 //先做异常处理
	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Current err %d",ret);
		return NULL;
	}
	return tlist->slider;
}

//将游标指针的值下移一个单位，并返回原游标的位置
TDLinkListNode* DLinkList_Next(DLinkList* list)
{
	//先做异常处理
	int ret = -1;
	TDLinkList * tlist = (TDLinkList * )list;
	TDLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//记录一下当前的游标的值
	tmp = tlist->slider;
	tlist->slider = tmp->next;
	//如果链表只有头结点的话，那么游标的值就是0
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;	
}

//将游标向前移动一个单位并返回原游标的位置
TDLinkListNode* DLinkList_Pre(DLinkList* list)
{
	//先做异常处理
	int ret = -1;
	TDLinkList * tlist = (TDLinkList * )list;
	TDLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//记录一下当前的游标的值
	tmp = tlist->slider;
	tlist->slider = tmp->pre;
	//如果链表只有头结点的话，那么游标的值就是0
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;	
}
