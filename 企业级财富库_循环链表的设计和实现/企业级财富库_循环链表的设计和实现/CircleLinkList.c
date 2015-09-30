#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CircleLinkList.h"

//����һ��ѭ������Ľṹ�塶������ͨ����ṹ���������������һ���α꡷

typedef struct _tag_CircleLinkList
{
  //ѭ������ṹ���ͷ��㣨һ��ѭ������ڵ�ṹ�������
  TCircleLinkListNode Header;
  
  //ѭ������ṹ���α�ָ�����
  TCircleLinkListNode *slider;
  
 //ѭ������Ľڵ���������ȣ�
  int length;

}TCircleLinkList;

//�����ӿڵ�ʵ�ֲ��裨�ȴ��׮������һ�ѣ�Ȼ���ڴӼ򵥵�������һʵ�ָ���������

void* CircleLinkList_Create()
{
	int ret = 0;
	TCircleLinkList *tlist = NULL;
	//ΪTCircleLinkList�ṹ�����ͱ��������ڴ�
	tlist = (TCircleLinkList *)malloc(sizeof(TCircleLinkList));
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func linkList_Create err %d",ret);
		return NULL;
	}
	//�ṹ���Ա��ʼ��
	tlist->length = 0;
	tlist->slider = NULL;
	tlist->Header.next = NULL;
	return tlist;
}

//���٣�ֻ�裩����ͷ������ҵ��ڵ�����������ɲ��Ժ�������
void CircleLinkList_Destroy(CircleLinkList *list)
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
void CircleLinkList_Clear(CircleLinkList *list)
{
    //�����쳣����
	int ret = 0;
	//����һ��ָ��ѭ������ͷ����ָ��
	TCircleLinkList *tlist = NULL;
	tlist = (TCircleLinkList *)list;
	if ( list == NULL)
	{
		ret = -1;
		printf("func CircleLinkList_Clear err %d",ret);
		return ;
	}
	tlist->Header.next = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
}

//��ȡ����ĳ��ȣ�����ͷ���⣩
int CircleLinkList_Length(CircleLinkList *list)
{
  //�����쳣����
	int ret = 0;
	TCircleLinkList *tlist = NULL;
	tlist = (TCircleLinkList *)list;
	if (list == NULL)
	{
		ret =-1;
		printf("func CircleLinkList_Length err %d",ret);
		return ret;
	}
	return tlist->length;
}

//�������е�posλ�ò���һ���ڵ㣨pos��ֵ��0��ʼ��
int CircleLinkList_Insert(CircleLinkList *list,TCircleLinkListNode*node, int pos)
{
	//�����쳣����
	int ret = 0, i=0;	TCircleLinkList* sList = (TCircleLinkList*)list;
	TCircleLinkListNode* last = NULL;
	TCircleLinkListNode* current = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret =-1;
		printf("func CircleLinkList_Insert parameter err %d",ret);
		return ret;
	}
	
	{
	//	//������ʼ��
		current = (TCircleLinkListNode*)sList;
		//���ҵ�posλ�õ�ǰһ��λ��
		for(i=0; (i < pos); i++)
		{
			current = current->next;
	    }

	//	//current->next 0�Žڵ�ĵ�ַ
		node->next = current->next; //1
	    current->next = node; //2

	//	//����һ�β���ڵ�
		if( sList->length == 0 )
		{
			//�α������
		    sList->slider = node;
 	    }

	//	//��ͷ�巨
		if( current == (TCircleLinkListNode*)sList )
		{
			//��ȡָ�����һ��Ԫ�ص�ָ��
			 last = CircleLinkList_Get(sList, sList->length - 1); 
			//�ǵ����һ���ڵ��ڴ洢��һ���ڵ�ĵ�ַ
			 last->next = current->next; //3
		}
			sList->length++;
	}
	return 0;
}

//ɾ�������е�posλ���ϵĽڵ㣨pos��ֵ��0��ʼ��

/*
����һ�ѣ�
  ��1���������û��ҵ��ڵ㣨Ҳ����˵����ֻ��ͷ��㣩��δ���
  ��2���������ֻ��һ���ڵ㣬��ôɾ���Ľڵ���ǵ�һ���ڵ㣬�����α�ָ��Ľڵ�
  ��3����������ж���ڵ�
        a:ɾ�����ǵ�һ���ڵ�
		b:ɾ�����α�ָ��Ľڵ�
		c:ɾ��������ͨ�ڵ�
*/
TCircleLinkListNode *CircleLinkList_Delete(CircleLinkList *list,int pos)
{
	//�쳣����
	int ret = 0;
	int i = 0;
	TCircleLinkList *tlist = (TCircleLinkList *)list;
	TCircleLinkListNode* current = (TCircleLinkListNode* )list;
	TCircleLinkListNode* last = NULL;
	TCircleLinkListNode *tmp = NULL;
	//��������
	if ( tlist == NULL || pos < 0 || pos >= CircleLinkList_Length(list) )
	{
		ret =-1;
		printf("func CircleLinkList_Delete parameter err %d",ret);
		return NULL;
	}
	//���������ֻ��ͷ���
	if (tlist->length <=0 )
	{
		return NULL;
	}	
		for(i=0; i<pos; i++)
		{
			current = current->next;   //currentָ���ɾ���ڵ��ǰһ���ڵ�
		}

		//��ɾ����һ��Ԫ��
		if( current == (TCircleLinkListNode*)list )
		{
			last = (TCircleLinkListNode*)CircleLinkList_Get(tlist, tlist->length - 1);
		}

		//��Ҫɾ����Ԫ��tmpָ��Ҫɾ���Ľڵ�
		//------------------------------
		//���Ĵ���
		tmp = current->next;
		current->next = tmp->next;
		tlist->length--;
		//------------------------------------
		//�����ϱ߱�ʾɾ���ڵ㣬�����±߱�ʾɾ���ڵ���һЩϸ�ڵĴ���
		//ɾ����һ���ڵ�ڵ���ϸ�ڴ���
		if( last != NULL )
		{
			tlist->Header.next = tmp->next;
			last->next = tmp->next;
		}

		//ɾ���α�����λ���ϵ����ٺ��ϸ�ڴ���
		if( tlist->slider == tmp )
		{
			tlist->slider = tmp->next;
		}

		//ɾ��ֻ��һ���ڵ������ĺ�������
		if( tlist->length == 0 )
		{
			tlist->Header.next = NULL;
			tlist->slider = NULL;
		}
	return tmp;
}
/*ע���ڲ����ɾ���ڵ�Ĺ�����ҩ�ǵð�����ĳ���*/


//��ȡ�����е�posλ���ϵĽڵ�ֵ
TCircleLinkListNode *CircleLinkList_Get(CircleLinkList *list,int pos)
{
	//�����쳣����
	TCircleLinkList *Ptclln = (TCircleLinkList *)list;
	TCircleLinkListNode *current = NULL;
	TCircleLinkListNode * tmp = NULL;
	int i = 0;
	int ret = 0;

	//����������ݴ���
	if (Ptclln == NULL || pos < 0|| pos>= Ptclln->length )
	{ 
		ret = -1;
		printf("func CircleLinkList_Get parameter err %d or linklist has no node",ret);
		return NULL;
	}

	//�������ֻ��ͷ���
	if ( Ptclln->length <=0 )
	{
		return NULL;
	}
	//��ʼ������
	current = &Ptclln->Header;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	  tmp = current->next;
	return tmp;
}

//API ADD ���ӵ�API����

TCircleLinkListNode* CircleList_DeleteNode(CircleLinkList* list, TCircleLinkListNode* node)
{
  //�����쳣����
	int ret = 0;
	TCircleLinkList *tlist  =(TCircleLinkList *)list;
	TCircleLinkListNode *current = NULL;
	TCircleLinkListNode *tmp = NULL;
	int i = 0;
	if ( tlist == NULL || node == NULL || tlist->length <=0)
	{
		ret = -1;
		printf("func CircleList_DeleteNode err %d",ret);
		return NULL;
	}
	current = &tlist->Header;
	for (i=0; i< tlist->length; i++)
	{

		if (current->next == node)
		{
           tmp =current->next;
		   break;
		}
		current = current->next;
	}
	if ( tmp != NULL)
	{
         CircleLinkList_Delete(list,i);
		 //ע�� ����ط�ʹ�õ��Ǻ���CircleLinkList_Delete(list,i)����������ڲ�����Ͱ����˶������ȵı仯�������ڲ�������tlist->length--;
		 //tlist->length--;
	}
	
	return tmp;
}
//�����α��λ��
TCircleLinkListNode* CircleList_Reset(CircleLinkList* list)
{
  //�����쳣����
	int ret = 0;
	TCircleLinkList *tlist =(TCircleLinkList *)list;
	TCircleLinkListNode *tmp = NULL;
	if ( tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Reset err %d",ret);
		return NULL;
	}

	tmp =  &tlist->Header;
	tlist->slider = tmp->next;
	return tlist->slider;
}

//TCircleLinkListNode* CircleList_Current(CircleLinkList* list)
//{
//  //�����쳣����
//	int ret = 0;
//	TCircleLinkList *tlist = (TCircleLinkList *)list;
//	if (tlist == NULL)
//	{
//		ret = -1;
//		printf("func CircleList_Current err %d",ret);
//		return NULL;
//	}
//	return tlist->slider;
//}

TCircleLinkListNode* CircleList_Current(CircleLinkList* list) // O(1)
{
	TCircleLinkList* sList = (TCircleLinkList*)list;
	TCircleLinkListNode* ret = NULL;

	if( sList != NULL )
	{
		ret = sList->slider;
	}

	return ret;
}
//��Ǯ�α��λ�����ƣ�������ǰһ���α��λ��
TCircleLinkListNode* CircleList_Next(CircleLinkList* list)
{
	//�����쳣����
	int ret = -1;
	TCircleLinkList * tlist = (TCircleLinkList * )list;
    TCircleLinkListNode * tmp = NULL;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Next err %d ",ret);
		return NULL;
	}
	//��¼һ�µ�ǰ���α��ֵ
	tmp = tlist->slider;
	tlist->slider = tmp->next;
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

