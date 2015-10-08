#include<iostream>
#include"stack"
using namespace std;

typedef struct BITNode
{
	int data;
	struct BITNode *lchild,*rchild;
}BITNode,*BTree;

/***********��������������ķǵݹ��㷨***********/
BITNode *GoFarLeft(BITNode *T,stack<BITNode *>&s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->lchild)
	{
		s.push(T); //���T�ڵ������ӣ���T�ڵ���ջ����֮�򷵻�T
		T = T->lchild;
	}
	return T;
}

void InOrder2(BITNode *T)
{
   stack<BITNode *>s;
   BITNode *t = GoFarLeft(T,s);    //�ҵ�������������,������δ���ʵĽڵ��Ѿ�������ջ��
   while (t)
   {
	  printf("%d ",t->data);
	  if (t->rchild)  //������Һ���
	  {
        t =  GoFarLeft(t->rchild,s);
	  }
	  else if (!s.empty())   //���û���Һ��Ӳ���ջ��Ϊ��
	  {
        t = s.top();
        s.pop();
	  }
	  else  //���û���Һ�����ջΪ��
	  {
		  t = NULL;
	  }
   }
}

/********************�㷨����********************/

void main()
{
	/*�����Զ�������Ĵ洢��ʽ����һ��������*/
	BITNode t1,t2,t3,t4,t5,t6,t7,t8;
	BITNode *newnode = NULL;
	int count = 0;
	int height = 0;
	//ע������������t1,t2,t3,t4,t5 5���ṹ�����ռ�õ��ڴ�ռ��ʼ��Ϊ0��������ڲ���ָ���Ա�����ĳ�ʼֵ����һ������ֵ�����ܻᵼ�³���������ʲ���������ڴ�ռ��ʼ���Ĳ���
	memset(&t1,0,sizeof(BITNode));
	memset(&t2,0,sizeof(BITNode));
	memset(&t3,0,sizeof(BITNode));
	memset(&t4,0,sizeof(BITNode));
	memset(&t5,0,sizeof(BITNode));
	memset(&t6,0,sizeof(BITNode));
	memset(&t7,0,sizeof(BITNode));
	memset(&t8,0,sizeof(BITNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	t6.data = 6;
	t7.data = 7;
	t8.data = 8;
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;
	t4.rchild = &t6;
	t6.lchild = &t7;
	t6.rchild = &t8;

	InOrder2(&t1);
	system("pause");
}