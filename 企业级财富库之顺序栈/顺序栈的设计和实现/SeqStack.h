#ifndef _MY_SEQSTACK_H_
#define _MY_SEQSTACK_H_

typedef void SeqStack;
//针对顺序栈设计的一套API

//创建顺序栈
SeqStack* SeqStack_Create(int capacity);

//销毁顺序栈
void SeqStack_Destroy(SeqStack* stack);

//清空顺序栈
void SeqStack_Clear(SeqStack* stack);

//元素入栈
int SeqStack_Push(SeqStack* stack, void* item);

//元素出栈
void* SeqStack_Pop(SeqStack* stack);

//获取栈顶元素
void* SeqStack_Top(SeqStack* stack);

//获取栈的实际大小
int SeqStack_Size(SeqStack* stack);

//获取栈的最大容量
int SeqStack_Capacity(SeqStack* stack);

#endif //_MY_SEQSTACK_H_