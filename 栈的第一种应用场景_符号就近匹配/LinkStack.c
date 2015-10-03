#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"
#include"linklist.h"

typedef struct _tag_LinkStack
{
	TlinkListNode node;
	void *item;
}TLinkStack;


//������ʽջ
LinkStack* LinkStack_Create()
{
	return linkList_Create();
}

//������ʽջ
void   LinkStack_Destroy(LinkStack* stack)
{
	//�ͷ���ջ���ڵ���������нڵ�
	LinkStack_Clear(stack);
	//�ͷ���ջ���ڵ�
	linkList_Destroy(stack);
	return ;
}

//���˳��ջ
void   LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack)>0)
	{
		LinkStack_Pop(stack);
	}
	return;
}

//Ԫ����ջ(������ĵ�һ���ڵ㵱��ջ������Ϊ��ջ��ʱ��ʱ�临�ӶȽϵͣ�����ͷ�巨)
//����һ�ѣ������溯���Ĳ����б��п�֪��item��void���͵�ָ���int linkList_Insert(linklist *list,TlinkListNode *node,int pos);Ҫ���������������TlinkListNode *��������
//������Ҫ��item��װ��һ����TlinkListNodeΪ�׳�Ա������һ���ṹ���У��ṹ������ƿ������⡣
int  LinkStack_Push(LinkStack* stack, void* item)
{ 
	int ret =0;
	TLinkStack *tstack = (TLinkStack *)malloc(sizeof(TLinkStack));
	tstack->item = item;
	ret = linkList_Insert(stack,(TlinkListNode*)tstack,0);
	//���û�в���ɹ����ͷŸոշ�����ڴ�
	if (ret != 0)
	{
		free(tstack);
		tstack = NULL;
	}
	return ret;
}

//Ԫ�س�ջ,������ĵ�һ��ҵ��ڵ�Ϊջ��Ԫ�أ������������0λ�ô�������ջ���˳�ջ����
void*   LinkStack_Pop(LinkStack* stack)
{
	void *myitem = NULL;
	TLinkStack *node = NULL;
	node = (TLinkStack *)LinkList_Delete(stack,0);
	if (node == NULL)
	{
		return NULL;
	}
	myitem = node->item;
	return myitem;
}

//��ȡջ��Ԫ��
void*   LinkStack_Top(LinkStack* stack)
{
	TLinkStack *node = NULL;
	node = (TLinkStack *)LinkList_Get(stack,0);
	if (node == NULL)
	{
		return NULL;
	}
	return node->item;
}

//��ȡջ��ʵ�ʴ�С
int   LinkStack_Size(LinkStack* stack)
{
  int len = 0;
  len = linkList_Length(stack); 
  if (len < 0)
  {
	  printf("\nfunc LinkStack_Size getSize failed\n");
	  return -1;
  }
  return len;
}

//����˵��һ������Ƶ�˳��ջ����ʽջ������
/*
  ˳��ջ�����һ���ڵ�Ϊջ���ڵ㣬��ջ��������ջ����ջ����
  ��ʽջ�ǵ�һ���ڵ㣨ͷ�����⣩Ϊջ���ڵ㣬��ջ��������ջ����ջ����
  Ϊʲô��ʽջ�Ե�һ���ڵ�Ϊջ���ڵ㣿
  ��Ϊ���ڽ��г�ջ������ʱ���Ե�һ���ڵ�Ϊջ���ڵ��ʱ�临�ӶȽϵ͡�
        �������������ʵ�ʱ�临�Ӷ���O(n^2)
*/

