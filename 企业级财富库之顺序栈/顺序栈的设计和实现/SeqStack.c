#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"
#include"seqlist.h"
//顺序栈是一种特殊的顺序表
//创建顺序栈
SeqStack* SeqStack_Create(int capacity)
{
	//创建一个能够存储10个无符号整型元素的顺序表---这里指5顺序栈
	return SeqList_Create(10);   	
}

//销毁顺序栈
void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

//清空顺序栈
void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return;
}

//元素入栈
int SeqStack_Push(SeqStack* stack, void* item)     //在底层指针变量item被强转为无符号整型数据存入顺序栈中
{
	return SeqList_Insert(stack,item,SeqList_Length(stack));
	
}

//元素出栈
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack,SeqList_Length(stack)-1);
}

//获取栈顶元素
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack,SeqList_Length(stack)-1);
}

//获取栈的实际大小
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

//获取栈的最大容量
int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}

