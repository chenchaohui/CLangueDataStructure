#ifndef __MYCIRCLE_LINK_LIST__
#define __MYCIRCLE_LINK_LIST__

typedef void CircleLinkList;
//循环链表是普通链表的一种特列，当然具有普通链表的全部功能，而且还具有自己扩充的功能
typedef struct _tag_CircleLinkListNode
{
	struct _tag_CircleLinkListNode *next;
}TCircleLinkListNode;

//定义一整套API接口《基本de API》
//创建一个循环链表头
void* CircleLinkList_Create();

//销毁（只需）链表头，其它业务节点的声明周期由测试函数决定
void CircleLinkList_Destroy(CircleLinkList *list);

//设置链表回最初的状态
void CircleLinkList_Clear(CircleLinkList *list);

//获取链表的长度（链表头除外）
int CircleLinkList_Length(CircleLinkList *list);

//向链表中的pos位置插入一个节点（pos的值从0开始）
int CircleLinkList_Insert(CircleLinkList *list,TCircleLinkListNode*node, int pos);

//删除链表中的pos位置上的节点（pos的值从0开始）
TCircleLinkListNode *CircleLinkList_Delete(CircleLinkList *list,int pos);

//获取链表中的pos位置上的节点值
TCircleLinkListNode *CircleLinkList_Get(CircleLinkList *list,int pos);

//API ADD 增加的API函数

//根据节点的地址删除节点的值
TCircleLinkListNode* CircleList_DeleteNode(CircleLinkList* list, TCircleLinkListNode* node);

 //重置游标，使其回到初始状态
TCircleLinkListNode* CircleList_Reset(CircleLinkList* list);

 //获取当前游标的指针的值
TCircleLinkListNode* CircleList_Current(CircleLinkList* list);

//将游标指针的值下移一个单位
TCircleLinkListNode* CircleList_Next(CircleLinkList* list);

//至此一整套API接口已经完成

#endif