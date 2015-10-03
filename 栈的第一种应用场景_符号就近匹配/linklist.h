#ifndef _MYLINKLIST_H
#define _MYLINKLIST_H
//ǧ��ǵ�typedef����һ��Ҫ����"�ֺ�;"
typedef void linklist;

//��������ڵ�
typedef struct _tag_linkListNode
{ 
	struct _tag_linkListNode *next;

}TlinkListNode;


//��������һ��API����
//����һ������
  linklist* linkList_Create();

//��������**
  void linkList_Destroy(linklist *list);

//������0
void linkList_Clear(linklist *list);	

//��ȡ�����ʵ�ʳ���
int linkList_Length(linklist *list);

//�������в���ڵ�
int linkList_Insert(linklist *list,TlinkListNode *node,int pos);

//��ȡָ��ĳ������ڵ��ָ��
TlinkListNode* LinkList_Get(linklist* list, int pos);

//ɾ�������е�ĳ���ڵ�
TlinkListNode* LinkList_Delete(linklist* list, int pos);

#endif