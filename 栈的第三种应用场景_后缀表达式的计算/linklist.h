#ifndef _MYLINKLIST_H
#define _MYLINKLIST_H
//千万记得typedef后面一定要加上"分号;"
typedef void linklist;

//声明链表节点
typedef struct _tag_linkListNode
{ 
	struct _tag_linkListNode *next;

}TlinkListNode;


//接下来是一套API函数
//创建一个链表
  linklist* linkList_Create();

//链表销毁**
  void linkList_Destroy(linklist *list);

//链表清0
void linkList_Clear(linklist *list);	

//获取链表的实际长度
int linkList_Length(linklist *list);

//向链表中插入节点
int linkList_Insert(linklist *list,TlinkListNode *node,int pos);

//获取指向某个链表节点的指针
TlinkListNode* LinkList_Get(linklist* list, int pos);

//删除链表中的某个节点
TlinkListNode* LinkList_Delete(linklist* list, int pos);

#endif