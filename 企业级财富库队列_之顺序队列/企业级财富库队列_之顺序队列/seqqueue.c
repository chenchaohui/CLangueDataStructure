#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"
#include"seqlist.h"

SeqQueue* SeqQueue_Create(int capacity)
{
	return  SeqList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return ;
}

void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return ;
}

int SeqQueue_Append(SeqQueue* queue, void* item)
{	
	//���õ���β�巢
	return SeqList_Insert(queue,item,SeqList_Length(queue));
}

void* SeqQueue_Retrieve(SeqQueue* queue)//
{
	//���õ�ɾ��ͷ���
	return SeqList_Delete(queue,0);
}

void* SeqQueue_Header(SeqQueue* queue)
{
  return SeqList_Get(queue,0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
  return SeqList_Capacity(queue);
}