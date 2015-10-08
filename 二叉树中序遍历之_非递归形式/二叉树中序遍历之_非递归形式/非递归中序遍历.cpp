#include<iostream>
#include"stack"
using namespace std;

typedef struct BITNode
{
	int data;
	struct BITNode *lchild,*rchild;
}BITNode,*BTree;

/***********二叉树中序遍历的非递归算法***********/
BITNode *GoFarLeft(BITNode *T,stack<BITNode *>&s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->lchild)
	{
		s.push(T); //如果T节点有左孩子，则将T节点入栈，反之则返回T
		T = T->lchild;
	}
	return T;
}

void InOrder2(BITNode *T)
{
   stack<BITNode *>s;
   BITNode *t = GoFarLeft(T,s);    //找到中序遍历的起点,经过但未访问的节点已经被存入栈中
   while (t)
   {
	  printf("%d ",t->data);
	  if (t->rchild)  //如果有右孩子
	  {
        t =  GoFarLeft(t->rchild,s);
	  }
	  else if (!s.empty())   //如果没有右孩子并且栈不为空
	  {
        t = s.top();
        s.pop();
	  }
	  else  //如果没有右孩子且栈为空
	  {
		  t = NULL;
	  }
   }
}

/********************算法结束********************/

void main()
{
	/*现在以二叉链表的存储形式创建一个二叉树*/
	BITNode t1,t2,t3,t4,t5,t6,t7,t8;
	BITNode *newnode = NULL;
	int count = 0;
	int height = 0;
	//注意事项：如果不对t1,t2,t3,t4,t5 5个结构体变量占用的内存空间初始化为0，则变量内部的指针成员变量的初始值就是一个垃圾值，可能会导致程序崩溃，故才有下面的内存空间初始化的步骤
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