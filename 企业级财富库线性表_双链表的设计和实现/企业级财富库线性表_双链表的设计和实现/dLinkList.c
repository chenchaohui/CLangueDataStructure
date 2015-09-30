#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dLinkList.h"
//����һ��˫����ṹ����������
typedef struct _tag_DLinkList
{
	TDLinkListNode header;    //Ϊ˫������һ��ͷ
	TDLinkListNode *slider;   //˫������α�
	int length;

}TDLinkList;

//Ϊʵ����һ����API�����ȱ����һ��׮
void* DLinkList_Create()
{
	TDLinkList *list = (TDLinkList *)malloc(sizeof(TDLinkList));
	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		printf("func DLinkList_Create malloc memory is failed %d",ret);
		return NULL;
	}
	list->header.next = NULL;
	list->header.pre = NULL;
	list->slider = NULL;
	list->length = 0;
	return list;
}

//���٣�ֻ�裩����ͷ������ҵ��ڵ�����������ɲ��Ժ�������
void DLinkList_Destroy(DLinkList *list)
{
	//�����쳣����
	int ret = 0;
	if (list == NULL)
	{   //�쳣���ѱ�־
		ret = -1;
		printf("func CircleLinkList_Destroy err %d",ret);
		return ;
	}
	free(list);
}

//��������������״̬
void DLinkList_Clear(DLinkList *list)
{
	//�����쳣����
	int ret = 0;
	//����һ��ָ��ѭ������ͷ����ָ��
	TDLinkList *tlist = NULL;
	tlist = (TDLinkList *)list;
	if ( list == NULL)
	{
		ret = -1;
		printf("func CircleLinkList_Clear err %d",ret);
		return ;
	}
    //��Ա����ȫ���ص������״̬
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
}

//��ȡ����ĳ��ȣ�����ͷ���⣩
int DLinkList_Length(DLinkList *list)
{
	//�����쳣����
	int ret = 0;
	TDLinkList *tlist = NULL;
	tlist = (TDLinkList  *)list;
	if (list == NULL)
	{
		ret =-1;
		printf("func CircleLinkList_Length err %d",ret);
		return ret;
	}
	//��������ĳ���
	return tlist->length;
}

//�������е�posλ�ò���һ���ڵ㣨pos��ֵ��0��ʼ��
int DLinkList_Insert(DLinkList *list,TDLinkListNode*node, int pos)
{
	//�����쳣����
	int ret = 0, i=0;	
	TDLinkList* sList = (TDLinkList*)list;
	//TDLinkListNode* last = NULL;
	TDLinkListNode* current = NULL;
	TDLinkListNode* pnext = NULL;
	if (list == NULL || node == NULL || pos < 0 || pos > sList->length)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return ret;
	}

	{
		//	//������ʼ��
		current = (TDLinkListNode*)sList;
		//���ҵ�posλ�õ�ǰһ��λ��
		for(i=0; i < pos; i++)
		{
			current = current->next;
		}                                     //��ʱcurrentָ�������λ�õ�ǰһ��λ��
		   pnext = current->next;

	 //��ͨ����ĺ��Ĵ��벽��1-2
		  current->next = node;
		  node->next= pnext;
     //��ͨ����ĺ��Ĵ��벽��3-4

	   if (pnext != NULL)                     //�������һ��λ����Ҫ�������ڵ�ǰ��ָ���Ա�������ڵ�Ĺ�ϵ����������Ҫ��������ϵ��
	   {
		      pnext->pre  = node;
			  node->pre = current;
	   }
	         
	     //����һ�β���ڵ㼴ֻ��ͷ����ͷ�巨
		if( sList->length == 0 )
		{
		   //�α������
			sList->slider = node;
			//node->pre = NULL;
		}	

		//ͷ�巨
		if( current == (TDLinkListNode*)sList)
		{
			//����Ӧ�Ĵ���
			node->pre = NULL;        		
		}

			sList->length++;
	}
	return 0;
}

//ɾ�������е�posλ���ϵĽڵ㣨pos��ֵ��0��ʼ��
TDLinkListNode *DLinkList_Delete(DLinkList *list,int pos)
{
	//�����쳣����
	int ret = 0, i=0;	
	TDLinkList* sList = (TDLinkList*)list;
	//TDLinkListNode* last = NULL;
	TDLinkListNode* current = NULL;
	TDLinkListNode* pnext = NULL;
	TDLinkListNode*tmp = NULL;
	if (list == NULL ||pos < 0 || pos >= sList->length)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return NULL;
	}

	{
		//	//������ʼ��
		current = (TDLinkListNode*)sList;
		//���ҵ�posλ�õ�ǰһ��λ��
		for(i=0; i < pos; i++)
		{
			current = current->next;
		}                                     //��ʱcurrentָ�������λ�õ�ǰһ��λ��

		tmp = current->next;                //pnext��ָ���ɾ���ڵ��ָ��
		pnext = tmp->next;

		//��ͨɾ���ĺ��Ĵ��벽��1
		current->next = pnext;

		//��ͨɾ���ĺ��Ĵ��벽��2
		//���ɾ���Ĳ������һ���ڵ㣨�Ǿ����м�ڵ������ĵ�һ���ڵ㣩
		if (pnext != NULL)                  
		{
			current = pnext->pre;
			if (current == (TDLinkListNode *)sList )
			{
				pnext->pre = NULL;
			}
		}
		//���ɾ���Ľڵ��������α�ָ��Ľڵ㣬���α���Ҫ����һ����λ
		if (sList->slider = tmp)
		{
			sList->slider = pnext;
		}
		sList->length--;
	}
	return tmp;
}

//��ȡ�����е�posλ���ϵĽڵ�ֵ��pos��ֵ��0��ʼ
TDLinkListNode *DLinkList_Get(DLinkList *list,int pos)
{
	//�����쳣����
	TDLinkList *tlist = (TDLinkList * )list;
	TDLinkListNode *current = NULL;
	TDLinkListNode * tmp = NULL;
	int i = 0;
	int ret = 0;

	//����������ݴ���
	if (tlist == NULL || pos < 0|| pos>= tlist->length )
	{ 
		ret = -1;
		printf("func CircleLinkList_Get parameter err %d or linklist has no this node",ret);
		return NULL;
	}

	//�������ֻ��ͷ���
	if ( tlist->length <=0 )
	{
		printf("����ֻ��ͷ��㣬��û��ҵ��ڵ�\n");
		return NULL;
	}
	//��ʼ������
	current = &tlist->header;
	//�ҵ�posλ�ü���ɾ���ڵ��ǰһ���ڵ�
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	//�ҵ���ɾ���ڵ��λ��
	tmp = current->next;
	return tmp;	
}

//API ADD ���ӵ�API����

//���ݽڵ�ĵ�ַɾ���ڵ��ֵ�����������Ҫ����DLinkList_Delete()�������
TDLinkListNode* DLinkList_DeleteNode(DLinkList* list, TDLinkListNode* node)
{
	//�����쳣����
	int ret = 0;
	int i = 0;
	TDLinkList *slist = (TDLinkList *)list;
	TDLinkListNode *current = NULL;
	TDLinkListNode *tmp = NULL;

	if (list == NULL || node == NULL)
	{
       ret = -1;
	   printf("func DLinkList_DeleteNode parameter err %d",ret);
	   return NULL;
	}
	if (DLinkList_Length(list) <=0 )
	{
		printf("this Dlinklist has no node yet\n");
		return NULL;
	}
	//������ʼ��
	current = (TDLinkListNode *)slist;
	for (i = 0; i < DLinkList_Length(list); i++)
	{
        if (current->next == node )
        {
			tmp = current->next;
			break;
        }
		current = current->next;
	}
	DLinkList_Delete(list,i);             //�ú����ڲ��Ѿ�������--������
	return node;
}

//�����α꣬ʹ��ص���ʼ״̬���������α��ֵ
TDLinkListNode* DLinkList_Reset(DLinkList* list)
{
	//�����쳣����
	int ret = 0;
	TDLinkList *tlist =(TDLinkList *)list;
	TDLinkListNode *tmp = NULL;
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Reset err %d",ret);
		return NULL;
	}
	tmp =  &tlist->header;
	//�α�λ�����»ص���ʼ����λ��
	tlist->slider = tmp->next;
	return tlist->slider;
}

//��ȡ��ǰ�α�ֵ
TDLinkListNode* DLinkList_Current(DLinkList* list)
{
	 //�����쳣����
	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Current err %d",ret);
		return NULL;
	}
	return tlist->slider;
}

//���α�ָ���ֵ����һ����λ��������ԭ�α��λ��
TDLinkListNode* DLinkList_Next(DLinkList* list)
{
	//�����쳣����
	int ret = -1;
	TDLinkList * tlist = (TDLinkList * )list;
	TDLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//��¼һ�µ�ǰ���α��ֵ
	tmp = tlist->slider;
	tlist->slider = tmp->next;
	//�������ֻ��ͷ���Ļ�����ô�α��ֵ����0
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;	
}

//���α���ǰ�ƶ�һ����λ������ԭ�α��λ��
TDLinkListNode* DLinkList_Pre(DLinkList* list)
{
	//�����쳣����
	int ret = -1;
	TDLinkList * tlist = (TDLinkList * )list;
	TDLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//��¼һ�µ�ǰ���α��ֵ
	tmp = tlist->slider;
	tlist->slider = tmp->pre;
	//�������ֻ��ͷ���Ļ�����ô�α��ֵ����0
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;	
}
