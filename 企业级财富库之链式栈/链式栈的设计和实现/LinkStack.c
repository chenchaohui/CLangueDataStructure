#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
#include"linklist.h"

typedef struct _tag_LinkStack
{
	TlinkListNode node;
	void *item;
}TLinkStack;


//创建链式栈
LinkStack* LinkStack_Create()
{
	return linkList_Create();
}

//销毁链式栈
void   LinkStack_Destroy(LinkStack* stack)
{
	//释放链栈根节点以外的所有节点
	LinkStack_Clear(stack);
	//释放链栈根节点
	linkList_Destroy(stack);
	return ;
}

//清空顺序栈
void   LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack)>0)
	{
		LinkStack_Pop(stack);
	}
	return;
}

//元素入栈(将链表的第一个节点当做栈顶，因为出栈的时候时间复杂度较低，采用头插法)
//分析一把：从下面函数的参数列表中可知：item是void类型的指针而int linkList_Insert(linklist *list,TlinkListNode *node,int pos);要插入的数据类型是TlinkListNode *数据类型
//所以需要把item包装到一个以TlinkListNode为首成员变量的一个结构体中，结构体的名称可以随意。
int  LinkStack_Push(LinkStack* stack, void* item)
{ 
	int ret =0;
	TLinkStack *tstack = (TLinkStack *)malloc(sizeof(TLinkStack));
	tstack->item = item;
	ret = linkList_Insert(stack,(TlinkListNode*)tstack,0);
	//如果没有插入成功则释放刚刚分配的内存
	if (ret != 0)
	{
		free(tstack);
		tstack = NULL;
	}
	return ret;
}

//元素出栈,以链表的第一个业务节点为栈顶元素，所以在链表的0位置处进行入栈和人出栈操作
void*   LinkStack_Pop(LinkStack* stack)
{
	void *myitem = NULL;
	TLinkStack *node = NULL;
	node = (TLinkStack *)LinkList_Delete(stack,0);
	if (node == NULL)
	{
		return NULL;
	}
	myitem = node->item;
	return myitem;
}

//获取栈顶元素
void*   LinkStack_Top(LinkStack* stack)
{
	TLinkStack *node = NULL;
	node = (TLinkStack *)LinkList_Get(stack,0);
	if (node == NULL)
	{
		return NULL;
	}
	return node->item;
}

//获取栈的实际大小
int   LinkStack_Size(LinkStack* stack)
{
  int len = 0;
  len = linkList_Length(stack); 
  if (len < 0)
  {
	  printf("\nfunc LinkStack_Size getSize failed\n");
	  return -1;
  }
  return len;
}

//这里说明一下所设计的顺序栈和链式栈的区别：
/*
  顺序栈是最后一个节点为栈顶节点，在栈顶进行入栈个出栈操作
  链式栈是第一个节点（头结点除外）为栈顶节点，在栈顶进行入栈个出栈操作
  为什么链式栈以第一个节点为栈顶节点？
  因为：在进行出栈操作的时候，以第一个节点为栈顶节点的时间复杂度较低。
        单链表的逆序访问的时间复杂度是O(n^2)
*/

