#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//˳�������
typedef struct _tag_seqlist
{
	//Ԥ���趨��˳��������
	int capacity;
	//˳�����ʵ�ʽڵ�ĸ��������ȣ�
	int length;
	//ָ��ڵ����ݵ�ָ��
	unsigned int *node;

}Tseqlist;


//��ʾ��void���͵�ָ����Խ����κ��������͵�ָ��
SeqList* SeqList_Create(int capacity)
{
   int ret = 0;
   Tseqlist *seqlist = NULL;
   //Ϊ˳�����������ݽڵ㿪���ڴ�ռ�
   seqlist = (Tseqlist *) malloc (sizeof(Tseqlist) + sizeof(unsigned int) * capacity);

   //�쳣����
   if (capacity <= 0)
   {
	   ret =-1;
	    printf("func SeqList_Create Err %d",ret);
		return NULL;
   }
   //�쳣����
   if (seqlist == NULL)
   {
	   ret = -2;
	   printf("func SeqList_Create Err %d",ret);
	   return NULL;
   }
   //��ָ��ָ��˳�������ݽڵ�
   seqlist->node = (unsigned int *)(seqlist +1);

   //˳����Ա��ʼ��
   seqlist->length = 0;
   seqlist->capacity = capacity;
   return seqlist;
}

//����˳���
void SeqList_Destroy(SeqList* list)
{
	//�쳣����
	int ret = 0;
	if (list == NULL)
	{
		ret  = -1;
		printf("func SeqList_Destroy err %d",ret);
		return ;
	}
	//�ͷ��ڴ�
	free(list);
}

//˳�������0
void SeqList_Clear(SeqList* list)
{   
	int ret  = 0;
	Tseqlist *tlist = NULL;
	//�����쳣����
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return ;
	}
	//�������ͼ�ĸ�ֵ��Ҫ����ת��
    tlist = (Tseqlist *)list;
	//��˳���ĳ�������
	tlist->length = 0;
}

int SeqList_Length(SeqList* list)
{
	int ret  = 0;
	Tseqlist *tlist = NULL;
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return ret;
	}
     tlist = (Tseqlist *)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	int ret  = 0;
	Tseqlist *tlist = NULL;
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return  ret;
	}
	tlist = (Tseqlist *)list;
	return tlist->capacity;
}



//��˳����ĳ��λ�ò���һ���ڵ�
//���������һ�����õķ�����������ǽ��ⲽ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	//int tmp;
	//�����쳣����
	Tseqlist *tlist = (Tseqlist *)list;
	if (list == NULL || node == NULL || pos<0 || pos >=tlist->capacity)
	{
		ret  = -1;
		printf("func SeqList_Insert err %d",ret);
		return ret;
	}
	//�쳣����
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}
	for (i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}

	tlist->node[pos] = (unsigned int )node;
	//˳���ĳ���Ҫ�ǵ�++
	tlist->length++;
	return 0;
}

//����λ�û�ȡ˳���ڵ�ֵpos��ʾ������±�ֵ��0��ʼ
//����SeqListNode*�ǲ������ϴ�Ӧ��֪���ڵ�ľ�����������
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
    //�Ƚ����쳣����
	Tseqlist *tlist = (Tseqlist *)list;
	if (list ==NULL || pos<0 || pos >= tlist->length)
	{
		ret = -1;
		printf("func SeqList_Get err %d",ret);
		return NULL;
	}
	return (SeqListNode*)tlist->node[pos];	
}

//����λ�û�ȡɾ���ڵ��ֵ
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	//�����쳣����
	int ret = 0;
	int i = 0;
	Tseqlist *tlist = (Tseqlist *)list;
	//����һ��SeqListNode*�����������ͱ��������ڴ洢ɾ���ڵ��ֵ
	SeqListNode *tmp = NULL;
	if (list == NULL || pos >= tlist->length)
	{
		ret = -1;
		printf("func SeqList_Delete err %d",ret);
		return NULL;
	}
	//���޷�����������ת��Ϊ(SeqListNode *)���͵�����
	tmp = (SeqListNode *)tlist->node[pos];
	for (i = pos + 1; i < tlist->length; i++)
	{
      tlist->node[i-1] = tlist->node[i];
	}

	tlist->length--;
	return tmp;
}