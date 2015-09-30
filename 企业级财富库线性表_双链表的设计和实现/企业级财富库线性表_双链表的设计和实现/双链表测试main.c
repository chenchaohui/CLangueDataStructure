#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dLinkList.h"
//����һ��ҵ��ڵ�ṹ����������
typedef struct _teacher
{
	TDLinkListNode  node;
	int age;
}teacher;

//���Գ���
void main()
{
	teacher t1,t2,t3,t4;
	DLinkList *list = NULL;
	TDLinkListNode *tlist = NULL;
	teacher *pt = NULL;
	int length;
	int i = 0;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;

	//����һ��˫����
	list = DLinkList_Create();

	//�ڵ�Ĳ���
	
	
		DLinkList_Insert(list,(TDLinkListNode *)&t1,0);
		DLinkList_Insert(list,(TDLinkListNode *)&t2,1);
	    DLinkList_Insert(list,(TDLinkListNode *)&t3,2);
		DLinkList_Insert(list,(TDLinkListNode *)&t4,3);

	////�ڵ�����,���Ȼ�ȡ˫����ĳ���
	length  = DLinkList_Length(list);
	for (i = 0; i<length; i++ )
	{
		pt = (teacher *)DLinkList_Get(list,i);
		printf("%d ",pt->age);
	}

	//����ڵ��ɾ������һ��ɾ����һ���ڵ㣩
	DLinkList_Delete(list,0);

	//����ڵ�ɾ�����������ٴ�ɾ������ĵ�һ���ڵ㣩
	tlist = DLinkList_Get(list,0);
	DLinkList_DeleteNode(list,tlist);
	printf("\n");
	for (i = 0; i<2; i++ )
	{
		pt = (teacher *)DLinkList_Get(list,i);
		printf("%d ",pt->age);
	}
	//���˫������α�����е�һϵ�в���   
	tlist = DLinkList_Reset(list);       //�����α겢�����α�ĵ�ǰλ�õ�ָ��
	tlist = DLinkList_Current(list);     //��ǰ���α��λ�ò������α�ĵ�ǰλ�õ�ָ��
	tlist = DLinkList_Next(list);        //�α���Ʋ������α����һ��λ�õ�ָ��
	tlist = DLinkList_Pre(list);
	//ʹ����ص���ʼ״̬
	DLinkList_Clear(list);

	//��������
	DLinkList_Destroy(list);
	system("pause");
}