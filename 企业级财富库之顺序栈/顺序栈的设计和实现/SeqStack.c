#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"
#include"seqlist.h"
//˳��ջ��һ�������˳���
//����˳��ջ
SeqStack* SeqStack_Create(int capacity)
{
	//����һ���ܹ��洢10���޷�������Ԫ�ص�˳���---����ָ5˳��ջ
	return SeqList_Create(10);   	
}

//����˳��ջ
void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

//���˳��ջ
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return;
}

//Ԫ����ջ
int SeqStack_Push(SeqStack* stack, void* item)     //�ڵײ�ָ�����item��ǿתΪ�޷����������ݴ���˳��ջ��
{
	return SeqList_Insert(stack,item,SeqList_Length(stack));
	
}

//Ԫ�س�ջ
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack,SeqList_Length(stack)-1);
}

//��ȡջ��Ԫ��
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack,SeqList_Length(stack)-1);
}

//��ȡջ��ʵ�ʴ�С
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

//��ȡջ���������
int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}

