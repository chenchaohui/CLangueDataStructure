#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//定义一个老师类型的结构体
typedef struct _teacher
{
 char name[64];
 int age;
 int buf;
 }teacher;

void main()
{
	int ret = 0;
	//变量i用作循环之用
	int i = 0;
	//定义变量后编译器会为变量分配内存空间且编译器自动对变量进行管理
	teacher t1,t2,t3; 
	SeqList* list = NULL;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	//创建顺序表
	list = SeqList_Create(10);

	//向顺序表中插入数据（前插法）
	SeqList_Insert(list,(SeqListNode *)&t1,0);
	SeqList_Insert(list,(SeqListNode *)&t2,0);
	SeqList_Insert(list,(SeqListNode *)&t3,0);

	//输出顺序表中节点数据指向的内存空间中的数据
	for ( i = 0; i< SeqList_Length(list);i++)
	{
      teacher *tmp = (teacher *)SeqList_Get(list,i);
	  printf("%d ",tmp->age);
	}
	i = SeqList_Length(list);
	for (i = i-1; i >= 0; i--)
	{
       SeqList_Delete(list,i);
	}
	//测试是否删除正确
	for ( i = 0; i< SeqList_Length(list);i++)
	{
		teacher *tmp = (teacher *)SeqList_Get(list,i);
		printf("%d ",tmp->age);
	}
	SeqList_Destroy(list);

	system("pause");
}