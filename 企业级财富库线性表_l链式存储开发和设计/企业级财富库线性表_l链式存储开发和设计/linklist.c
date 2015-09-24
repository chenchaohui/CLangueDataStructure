#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"
//���������
typedef struct _tagLinkList
{
	TlinkListNode header;
	int length;
}TLinkList;

//�����ӿڵ�ʵ��,ע��ֻ��ͷ����ڵײ㶯̬�ķ������ڴ�ռ䣬�����ϲ�ҵ��ڵ����ɲ��Գ��������
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

//��������**   
//���������ٲ������ڴ�й¶ô----������  ��Ϊ�ڵײ�ֻ������һ������TLinkList���������͵��ڴ�ռ䣬�����ڵ㣨���������ڣ������ϲ�ҵ������������ڵ������ִ������Ժ���Զ��ͷţ�
//�����ĺô�����ʵ���˵ײ���ϲ�ҵ��ķ���
void linkList_Destroy(linklist *list)
{
  //�쳣����
  int ret = 0;
  if (list  == NULL)
  {
	  ret = -1;
	  printf("func linkList_Destroy err %d",ret);
	  return ;
  }
  free(list);
}

//������0
void linkList_Clear(linklist *list)
{
   //�쳣����
	int ret = 0;
	TLinkList *tlist = (TLinkList *)list;
	if ( list == NULL)
	{
		ret  =-1;
      printf("func linkList_Clear parameter err %d",ret);
	  return;
	}
	//�ص���ʼ������״̬��ͷ�������Ľڵ㲻Ҫ�ܣ���Ϊ���������ϲ�ҵ�������
	tlist->length = 0;
	tlist->header.next = NULL;
}

//��ȡ�����ʵ�ʳ���
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


//�������в���ڵ� ҵ��Ĭ��pos��ʾ�±꣬��0��ʼ
int linkList_Insert(linklist *list,TlinkListNode *node,int pos)
{
	//�����쳣����
	int ret = 0;
	int i = 0;
	//ָ��ǰ����ڵ��ָ��
	TlinkListNode *current = NULL;
	TLinkList *tlist  = (TLinkList *)list;
	if (list  == NULL || node == NULL ||pos < 0 || pos > tlist->length)
	{
       ret = -1;
	   printf("func linkList_Insert parameter err %d",ret);
	   return ret;
	}

	//���Ĵ��� ����Ҫ�ҵ�posλ��
	//��ʼ������,�������ɢ��ʵ����ʡ��  current = &tlist->header;
	current = &(tlist->header);  //����current��ָ����header����ڵ���
	//current = (TlinkListNode *)(tlist);    �����ַ���Ҳ�ǿ��Եģ����������������
	//current = (TlinkListNode *)(list)
	//�������㷨�ı��ʾ��ǿ�ͼ˵��
	for (i = 0;i < pos && current->next != NULL;i++)
	{
		current = current->next;
	}
	//��current->next =NULLʱ����ʾ�������ĩβ����һ���ڵ�
	//���Ĵ���
	   node->next  = current->next;
	   current->next = node;
	   tlist->length++;
	   return 0;
}


//��ȡָ��ĳ������ڵ��ָ��
TlinkListNode* LinkList_Get(linklist* list, int pos)
{
	//�����쳣����
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
   //�����������ҵ��ڵ�
   //��ʼ������
   current = &(tlist->header); 
   for (i = 0; i < pos; i++)
   {
	   current = current->next;
   }
   current = current->next;

	return current;
}


//ɾ�������е�ĳ���ڵ�
TlinkListNode* LinkList_Delete(linklist* list, int pos)
{
   //�����쳣����
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

	//Ҫ�ҵ���ɾ��Ԫ��λ��ǰһ��λ��
	//tmp = LinkList_Get(list,pos);
	//��ʼ������
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