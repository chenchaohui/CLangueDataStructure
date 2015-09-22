#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//����һ����ʦ���͵Ľṹ��
typedef struct _teacher
{
 char name[64];
 int age;
 int buf;
 }teacher;

void main()
{
	int ret = 0;
	//����i����ѭ��֮��
	int i = 0;
	//����������������Ϊ���������ڴ�ռ��ұ������Զ��Ա������й���
	teacher t1,t2,t3; 
	SeqList* list = NULL;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	//����˳���
	list = SeqList_Create(10);

	//��˳����в������ݣ�ǰ�巨��
	SeqList_Insert(list,(SeqListNode *)&t1,0);
	SeqList_Insert(list,(SeqListNode *)&t2,0);
	SeqList_Insert(list,(SeqListNode *)&t3,0);

	//���˳����нڵ�����ָ����ڴ�ռ��е�����
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
	//�����Ƿ�ɾ����ȷ
	for ( i = 0; i< SeqList_Length(list);i++)
	{
		teacher *tmp = (teacher *)SeqList_Get(list,i);
		printf("%d ",tmp->age);
	}
	SeqList_Destroy(list);

	system("pause");
}