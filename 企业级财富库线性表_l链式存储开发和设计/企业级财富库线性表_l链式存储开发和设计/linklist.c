#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"
//设计链表类
typedef struct _tagLinkList
{
	TlinkListNode header;
	int length;
}TLinkList;

//函数接口的实现,注意只有头结点在底层动态的分配了内存空间，其它上层业务节点是由测试程序决定的
linklist *linkList_Create()
{  
	int ret = 0;
	TLinkList *tlist = NULL;
	tlist = (TLinkList *)malloc(sizeof(TLinkList));
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func linkList_Create err %d",ret);
		return NULL;
	}
	tlist->length = 0;
	//tlist->header.next = NULL;
	return tlist;
}

//链表销毁**   
//这样的销毁不存在内存泄露么----不存在  因为在底层只分配了一个链表（TLinkList）数据类型的内存空间，其它节点（的生存周期）都是上层业务决定，其它节点待程序执行完成以后会自动释放，
//这样的好处就是实现了底层和上层业务的分离
void linkList_Destroy(linklist *list)
{
  //异常处理
  int ret = 0;
  if (list  == NULL)
  {
	  ret = -1;
	  printf("func linkList_Destroy err %d",ret);
	  return ;
  }
  free(list);
}

//链表清0
void linkList_Clear(linklist *list)
{
   //异常处理
	int ret = 0;
	TLinkList *tlist = (TLinkList *)list;
	if ( list == NULL)
	{
		ret  =-1;
      printf("func linkList_Clear parameter err %d",ret);
	  return;
	}
	//回到初始创建的状态，头结点以外的节点不要管，因为他们是由上层业务决定的
	tlist->length = 0;
	tlist->header.next = NULL;
}

//获取链表的实际长度
int linkList_Length(linklist *list)
{
	int ret = 0;
   TLinkList *tlist = ( TLinkList *)list;
   if (tlist == NULL)
   {
	   ret= -1;
	   printf("func linkList_Length parameter err %d",ret);
	   return ret;
   }
	return tlist->length;
}


//向链表中插入节点 业界默认pos表示下标，从0开始
int linkList_Insert(linklist *list,TlinkListNode *node,int pos)
{
	//先做异常处理
	int ret = 0;
	int i = 0;
	//指向当前链表节点的指针
	TlinkListNode *current = NULL;
	TLinkList *tlist  = (TLinkList *)list;
	if (list  == NULL || node == NULL ||pos < 0 || pos > tlist->length)
	{
       ret = -1;
	   printf("func linkList_Insert parameter err %d",ret);
	   return ret;
	}

	//核心代码 首先要找到pos位置
	//初始化环境,下面的扩散其实可以省略  current = &tlist->header;
	current = &(tlist->header);  //这样current就指向了header这个节点了
	//current = (TlinkListNode *)(tlist);    这两种方法也是可以的，建议用上面的那种
	//current = (TlinkListNode *)(list)
	//这样的算法的本质就是看图说话
	for (i = 0;i < pos && current->next != NULL;i++)
	{
		current = current->next;
	}
	//当current->next =NULL时，表示在链表的末尾插入一个节点
	//核心代码
	   node->next  = current->next;
	   current->next = node;
	   tlist->length++;
	   return 0;
}


//获取指向某个链表节点的指针
TlinkListNode* LinkList_Get(linklist* list, int pos)
{
	//先做异常处理
   int ret = 0; 
   int i = 0;
   TlinkListNode *current = NULL;
   TLinkList *tlist  = (TLinkList *)list;
   if ( list == NULL || pos < 0 || pos >= tlist->length)
   {
	   ret =-1;
	   printf("func LinkList_Get parameter err %d",ret);
	   return NULL;
   }
   //接下来就是找到节点
   //初始化环境
   current = &(tlist->header); 
   for (i = 0; i < pos; i++)
   {
	   current = current->next;
   }
   current = current->next;

	return current;
}


//删除链表中的某个节点
TlinkListNode* LinkList_Delete(linklist* list, int pos)
{
   //先做异常处理
	int ret  =0;
	int i = 0;
	TLinkList *tlist = (TLinkList *)list;
	TlinkListNode *current = NULL;
	TlinkListNode *tmp =NULL;
	if ( list == NULL || pos < 0 || pos >= tlist->length)
	{
		ret  = -1;
		printf("func LinkList_Delete parameter err %d",ret);
		return NULL;
	}

	//要找到待删除元素位置前一个位置
	//tmp = LinkList_Get(list,pos);
	//初始化环境
	 current = &(tlist->header); 
	 for ( i = 0; i < pos; i++)
	 {
		 current =current->next;
	 }
	 tmp = current->next;
	 current->next = current->next->next;
	 tlist->length--;
	return tmp;
}