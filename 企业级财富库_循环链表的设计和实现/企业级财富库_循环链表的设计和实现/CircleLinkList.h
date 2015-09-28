#ifndef __MYCIRCLE_LINK_LIST__
#define __MYCIRCLE_LINK_LIST__

typedef void CircleLinkList;
//ѭ����������ͨ�����һ�����У���Ȼ������ͨ�����ȫ�����ܣ����һ������Լ�����Ĺ���
typedef struct _tag_CircleLinkListNode
{
	struct _tag_CircleLinkListNode *next;
}TCircleLinkListNode;

//����һ����API�ӿڡ�����de API��
//����һ��ѭ������ͷ
void* CircleLinkList_Create();

//���٣�ֻ�裩����ͷ������ҵ��ڵ�����������ɲ��Ժ�������
void CircleLinkList_Destroy(CircleLinkList *list);

//��������������״̬
void CircleLinkList_Clear(CircleLinkList *list);

//��ȡ����ĳ��ȣ�����ͷ���⣩
int CircleLinkList_Length(CircleLinkList *list);

//�������е�posλ�ò���һ���ڵ㣨pos��ֵ��0��ʼ��
int CircleLinkList_Insert(CircleLinkList *list,TCircleLinkListNode*node, int pos);

//ɾ�������е�posλ���ϵĽڵ㣨pos��ֵ��0��ʼ��
TCircleLinkListNode *CircleLinkList_Delete(CircleLinkList *list,int pos);

//��ȡ�����е�posλ���ϵĽڵ�ֵ
TCircleLinkListNode *CircleLinkList_Get(CircleLinkList *list,int pos);

//API ADD ���ӵ�API����

//���ݽڵ�ĵ�ַɾ���ڵ��ֵ
TCircleLinkListNode* CircleList_DeleteNode(CircleLinkList* list, TCircleLinkListNode* node);

 //�����α꣬ʹ��ص���ʼ״̬
TCircleLinkListNode* CircleList_Reset(CircleLinkList* list);

 //��ȡ��ǰ�α��ָ���ֵ
TCircleLinkListNode* CircleList_Current(CircleLinkList* list);

//���α�ָ���ֵ����һ����λ
TCircleLinkListNode* CircleList_Next(CircleLinkList* list);

//����һ����API�ӿ��Ѿ����

#endif