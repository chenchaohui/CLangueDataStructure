#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void *item;
}TLinkQueueNode;
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue); //注意这个地方不要调用错误了
	LinkList_Destroy(queue);
	return ;
}

void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	return ;
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueueNode *node = NULL;
	if (queue==NULL || item == NULL)
	{
		return -2;
	}
	//把形参item转成linklist的业务节点
	node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (node == NULL)
	{
		return -1;
	}
	node->item = item;
	//尾叉法
	ret = LinkList_Insert(queue, (LinkListNode*)node, LinkList_Length(queue));
	if (ret != 0)
	{
		free(node);
	}
	return 0;
}

void* LinkQueue_Retrieve(LinkQueue* queue)
{
	void *myItem = NULL;
	TLinkQueueNode *node = NULL;
	if (queue == NULL)
	{
		return NULL;
	}
	node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (node == NULL)
	{
		return NULL;
	}
	myItem = node->item;
	if (node != NULL)
	{
		free(node); //注意这个地方别忘记了释放内存，因为insert的时候分配了内存
	}
	return myItem;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	void *myItem = NULL;
	TLinkQueueNode *node = NULL;
	if (queue == NULL)
	{
		return NULL;
	}
	node = (TLinkQueueNode *)LinkList_Get(queue, 0);
	if (node == NULL)
	{
		return NULL;
	}
	myItem = node->item;
	
	return myItem;
}

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}