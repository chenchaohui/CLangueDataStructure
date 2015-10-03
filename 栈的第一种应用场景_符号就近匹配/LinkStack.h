//ע����ʽջ�ڵ��ڴ洢����ָ����ʽ�ڵ����͵�ָ��
#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;
//���˳��ջ��Ƶ�һ��API

//����˳��ջ
LinkStack* LinkStack_Create();

//����˳��ջ
void   LinkStack_Destroy(LinkStack* stack);

//���˳��ջ
void   LinkStack_Clear(LinkStack* stack);

//Ԫ����ջ
int   LinkStack_Push(LinkStack* stack, void* item);

//Ԫ�س�ջ
void*   LinkStack_Pop(LinkStack* stack);

//��ȡջ��Ԫ��
void*   LinkStack_Top(LinkStack* stack);

//��ȡջ��ʵ�ʴ�С
int   LinkStack_Size(LinkStack* stack);

#endif //_MY_SEQSTACK_H_
