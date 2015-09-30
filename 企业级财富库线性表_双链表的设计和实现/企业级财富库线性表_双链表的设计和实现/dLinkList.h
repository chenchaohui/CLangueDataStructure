#ifndef __MYDLINKLIST_H__
#define __MYDLINKLIST_H__

typedef void DLinkList;
//循环链表是普通链表的一种特列，当然具有普通链表的全部功能，而且还具有自己扩充的功能
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}TDLinkListNode;

//定义一整套API接口《基本de API》
//创建一个循环链表头
void* DLinkList_Create();

//销毁（只需）链表头，其它业务节点的声明周期由测试函数决定
void DLinkList_Destroy(DLinkList *list);

//设置链表回最初的状态
void DLinkList_Clear(DLinkList *list);

//获取链表的长度（链表头除外）
int DLinkList_Length(DLinkList *list);

//向链表中的pos位置插入一个节点（pos的值从0开始）
int DLinkList_Insert(DLinkList *list,TDLinkListNode*node, int pos);

//删除链表中的pos位置上的节点（pos的值从0开始）
TDLinkListNode *DLinkList_Delete(DLinkList *list,int pos);

//获取链表中的pos位置上的节点值
TDLinkListNode *DLinkList_Get(DLinkList *list,int pos);


//API ADD 增加的API函数

//根据节点的地址删除节点的值
TDLinkListNode* DLinkList_DeleteNode(DLinkList* list, TDLinkListNode* node);

//重置游标，使其回到初始状态
TDLinkListNode* DLinkList_Reset(DLinkList* list);

//获取当前游标的指针的值
TDLinkListNode* DLinkList_Current(DLinkList* list);

//将游标指针的值下移一个单位
TDLinkListNode* DLinkList_Next(DLinkList* list);

TDLinkListNode* DLinkList_Pre(DLinkList* list);
//至此一整套API接口已经完成

#endif