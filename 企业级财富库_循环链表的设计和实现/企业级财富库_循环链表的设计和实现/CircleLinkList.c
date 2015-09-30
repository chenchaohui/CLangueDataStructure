#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CircleLinkList.h"

//定义一个循环链表的结构体《它与普通链表结构体的区别是增加了一个游标》

typedef struct _tag_CircleLinkList
{
  //循环链表结构体的头结点（一个循环链表节点结构体变量）
  TCircleLinkListNode Header;
  
  //循环链表结构的游标指针变量
  TCircleLinkListNode *slider;
  
 //循环链表的节点个数（长度）
  int length;

}TCircleLinkList;

//各个接口的实现步骤（先打个桩，测试一把，然后在从简单到复杂逐一实现各个函数）

void* CircleLinkList_Create()
{
	int ret = 0;
	TCircleLinkList *tlist = NULL;
	//为TCircleLinkList结构体类型变量分配内存
	tlist = (TCircleLinkList *)malloc(sizeof(TCircleLinkList));
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func linkList_Create err %d",ret);
		return NULL;
	}
	//结构体成员初始化
	tlist->length = 0;
	tlist->slider = NULL;
	tlist->Header.next = NULL;
	return tlist;
}

//销毁（只需）链表头，其它业务节点的声明周期由测试函数决定
void CircleLinkList_Destroy(CircleLinkList *list)
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
void CircleLinkList_Clear(CircleLinkList *list)
{
    //先做异常处理
	int ret = 0;
	//定义一个指向循环链表头结点的指针
	TCircleLinkList *tlist = NULL;
	tlist = (TCircleLinkList *)list;
	if ( list == NULL)
	{
		ret = -1;
		printf("func CircleLinkList_Clear err %d",ret);
		return ;
	}
	tlist->Header.next = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
}

//获取链表的长度（链表头除外）
int CircleLinkList_Length(CircleLinkList *list)
{
  //先做异常处理
	int ret = 0;
	TCircleLinkList *tlist = NULL;
	tlist = (TCircleLinkList *)list;
	if (list == NULL)
	{
		ret =-1;
		printf("func CircleLinkList_Length err %d",ret);
		return ret;
	}
	return tlist->length;
}

//向链表中的pos位置插入一个节点（pos的值从0开始）
int CircleLinkList_Insert(CircleLinkList *list,TCircleLinkListNode*node, int pos)
{
	//先做异常处理
	int ret = 0, i=0;	TCircleLinkList* sList = (TCircleLinkList*)list;
	TCircleLinkListNode* last = NULL;
	TCircleLinkListNode* current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return ret;
	}
	
	{
	//	//环境初始化
		current = (TCircleLinkListNode*)sList;
		//先找到pos位置的前一个位置
		for(i=0; (i < pos); i++)
		{
			current = current->next;
	    }

	//	//current->next 0号节点的地址
		node->next = current->next; //1
	    current->next = node; //2

	//	//若第一次插入节点
		if( sList->length == 0 )
		{
			//游标的设置
		    sList->slider = node;
 	    }

	//	//若头插法
		if( current == (TCircleLinkListNode*)sList )
		{
			//获取指向最后一个元素的指针
			 last = CircleLinkList_Get(sList, sList->length - 1); 
			//是的最后一个节点内存储第一个节点的地址
			 last->next = current->next; //3
		}
			sList->length++;
	}
	return 0;
}

//删除链表中的pos位置上的节点（pos的值从0开始）

/*
分析一把：
  （1）如果链表没有业务节点（也就是说链表只有头结点）如何处理
  （2）如果链表只有一个节点，那么删除的节点既是第一个节点，又是游标指向的节点
  （3）如果链表有多个节点
        a:删除的是第一个节点
		b:删除的游标指向的节点
		c:删除的是普通节点
*/
TCircleLinkListNode *CircleLinkList_Delete(CircleLinkList *list,int pos)
{
	//异常处理
	int ret = 0;
	int i = 0;
	TCircleLinkList *tlist = (TCircleLinkList *)list;
	TCircleLinkListNode* current = (TCircleLinkListNode* )list;
	TCircleLinkListNode* last = NULL;
	TCircleLinkListNode *tmp = NULL;
	//参数错误
	if ( tlist == NULL || pos < 0 || pos >= CircleLinkList_Length(list) )
	{
		ret =-1;
		printf("func CircleLinkList_Delete parameter err %d",ret);
		return NULL;
	}
	//如果链表本身只有头结点
	if (tlist->length <=0 )
	{
		return NULL;
	}	
		for(i=0; i<pos; i++)
		{
			current = current->next;   //current指向待删除节点的前一个节点
		}

		//若删除第一个元素
		if( current == (TCircleLinkListNode*)list )
		{
			last = (TCircleLinkListNode*)CircleLinkList_Get(tlist, tlist->length - 1);
		}

		//求要删除的元素tmp指向要删除的节点
		//------------------------------
		//核心代码
		tmp = current->next;
		current->next = tmp->next;
		tlist->length--;
		//------------------------------------
		//虚线上边表示删除节点，虚线下边表示删除节点后的一些细节的处理
		//删除第一个节点节点后的细节处理
		if( last != NULL )
		{
			tlist->Header.next = tmp->next;
			last->next = tmp->next;
		}

		//删除游标所在位置上的语速后的细节处理
		if( tlist->slider == tmp )
		{
			tlist->slider = tmp->next;
		}

		//删除只有一个节点的链表的后续处理
		if( tlist->length == 0 )
		{
			tlist->Header.next = NULL;
			tlist->slider = NULL;
		}
	return tmp;
}
/*注意在插入个删除节点的过程中药记得把链表的长度*/


//获取链表中的pos位置上的节点值
TCircleLinkListNode *CircleLinkList_Get(CircleLinkList *list,int pos)
{
	//先做异常处理
	TCircleLinkList *Ptclln = (TCircleLinkList *)list;
	TCircleLinkListNode *current = NULL;
	TCircleLinkListNode * tmp = NULL;
	int i = 0;
	int ret = 0;

	//如果参数传递错误
	if (Ptclln == NULL || pos < 0|| pos>= Ptclln->length )
	{ 
		ret = -1;
		printf("func CircleLinkList_Get parameter err %d or linklist has no node",ret);
		return NULL;
	}

	//如果链表只有头结点
	if ( Ptclln->length <=0 )
	{
		return NULL;
	}
	//初始化环境
	current = &Ptclln->Header;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	  tmp = current->next;
	return tmp;
}

//API ADD 增加的API函数

TCircleLinkListNode* CircleList_DeleteNode(CircleLinkList* list, TCircleLinkListNode* node)
{
  //先做异常处理
	int ret = 0;
	TCircleLinkList *tlist  =(TCircleLinkList *)list;
	TCircleLinkListNode *current = NULL;
	TCircleLinkListNode *tmp = NULL;
	int i = 0;
	if ( tlist == NULL || node == NULL || tlist->length <=0)
	{
		ret = -1;
		printf("func CircleList_DeleteNode err %d",ret);
		return NULL;
	}
	current = &tlist->Header;
	for (i=0; i< tlist->length; i++)
	{

		if (current->next == node)
		{
           tmp =current->next;
		   break;
		}
		current = current->next;
	}
	if ( tmp != NULL)
	{
         CircleLinkList_Delete(list,i);
		 //注意 这个地方使用的是函数CircleLinkList_Delete(list,i)，这个函数内部本身就包含了对链表长度的变化即函数内部包含了tlist->length--;
		 //tlist->length--;
	}
	
	return tmp;
}
//重置游标的位置
TCircleLinkListNode* CircleList_Reset(CircleLinkList* list)
{
  //先做异常处理
	int ret = 0;
	TCircleLinkList *tlist =(TCircleLinkList *)list;
	TCircleLinkListNode *tmp = NULL;
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Reset err %d",ret);
		return NULL;
	}

	tmp =  &tlist->Header;
	tlist->slider = tmp->next;
	return tlist->slider;
}

//TCircleLinkListNode* CircleList_Current(CircleLinkList* list)
//{
//  //先做异常处理
//	int ret = 0;
//	TCircleLinkList *tlist = (TCircleLinkList *)list;
//	if (tlist == NULL)
//	{
//		ret = -1;
//		printf("func CircleList_Current err %d",ret);
//		return NULL;
//	}
//	return tlist->slider;
//}

TCircleLinkListNode* CircleList_Current(CircleLinkList* list) // O(1)
{
	TCircleLinkList* sList = (TCircleLinkList*)list;
	TCircleLinkListNode* ret = NULL;

	if( sList != NULL )
	{
		ret = sList->slider;
	}

	return ret;
}
//点钱游标的位置下移，并返回前一个游标的位置
TCircleLinkListNode* CircleList_Next(CircleLinkList* list)
{
	//先做异常处理
	int ret = -1;
	TCircleLinkList * tlist = (TCircleLinkList * )list;
    TCircleLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//记录一下当前的游标的值
	tmp = tlist->slider;
	tlist->slider = tmp->next;
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

