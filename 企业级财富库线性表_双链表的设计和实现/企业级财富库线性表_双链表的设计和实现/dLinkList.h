#ifndef __MYDLINKLIST_H__
#define __MYDLINKLIST_H__

typedef void DLinkList;
//ѭ����������ͨ�����һ�����У���Ȼ������ͨ�����ȫ�����ܣ����һ������Լ�����Ĺ���
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}TDLinkListNode;

//����һ����API�ӿڡ�����de API��
//����һ��ѭ������ͷ
void* DLinkList_Create();

//���٣�ֻ�裩����ͷ������ҵ��ڵ�����������ɲ��Ժ�������
void DLinkList_Destroy(DLinkList *list);

//��������������״̬
void DLinkList_Clear(DLinkList *list);

//��ȡ����ĳ��ȣ�����ͷ���⣩
int DLinkList_Length(DLinkList *list);

//�������е�posλ�ò���һ���ڵ㣨pos��ֵ��0��ʼ��
int DLinkList_Insert(DLinkList *list,TDLinkListNode*node, int pos);

//ɾ�������е�posλ���ϵĽڵ㣨pos��ֵ��0��ʼ��
TDLinkListNode *DLinkList_Delete(DLinkList *list,int pos);

//��ȡ�����е�posλ���ϵĽڵ�ֵ
TDLinkListNode *DLinkList_Get(DLinkList *list,int pos);


//API ADD ���ӵ�API����

//���ݽڵ�ĵ�ַɾ���ڵ��ֵ
TDLinkListNode* DLinkList_DeleteNode(DLinkList* list, TDLinkListNode* node);

//�����α꣬ʹ��ص���ʼ״̬
TDLinkListNode* DLinkList_Reset(DLinkList* list);

//��ȡ��ǰ�α��ָ���ֵ
TDLinkListNode* DLinkList_Current(DLinkList* list);

//���α�ָ���ֵ����һ����λ
TDLinkListNode* DLinkList_Next(DLinkList* list);

TDLinkListNode* DLinkList_Pre(DLinkList* list);
//����һ����API�ӿ��Ѿ����

#endif