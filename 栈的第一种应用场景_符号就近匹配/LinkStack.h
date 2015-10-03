//注意链式栈节点内存储的是指向链式节点类型的指针
#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;
//针对顺序栈设计的一套API

//创建顺序栈
LinkStack* LinkStack_Create();

//销毁顺序栈
void   LinkStack_Destroy(LinkStack* stack);

//清空顺序栈
void   LinkStack_Clear(LinkStack* stack);

//元素入栈
int   LinkStack_Push(LinkStack* stack, void* item);

//元素出栈
void*   LinkStack_Pop(LinkStack* stack);

//获取栈顶元素
void*   LinkStack_Top(LinkStack* stack);

//获取栈的实际大小
int   LinkStack_Size(LinkStack* stack);

#endif //_MY_SEQSTACK_H_
