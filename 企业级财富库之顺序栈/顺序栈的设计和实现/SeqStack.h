#ifndef _MY_SEQSTACK_H_
#define _MY_SEQSTACK_H_

typedef void SeqStack;
//���˳��ջ��Ƶ�һ��API

//����˳��ջ
SeqStack* SeqStack_Create(int capacity);

//����˳��ջ
void SeqStack_Destroy(SeqStack* stack);

//���˳��ջ
void SeqStack_Clear(SeqStack* stack);

//Ԫ����ջ
int SeqStack_Push(SeqStack* stack, void* item);

//Ԫ�س�ջ
void* SeqStack_Pop(SeqStack* stack);

//��ȡջ��Ԫ��
void* SeqStack_Top(SeqStack* stack);

//��ȡջ��ʵ�ʴ�С
int SeqStack_Size(SeqStack* stack);

//��ȡջ���������
int SeqStack_Capacity(SeqStack* stack);

#endif //_MY_SEQSTACK_H_