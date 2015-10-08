#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode 
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//按给定的先序序列建立二叉链表
BiTNode* BiTree_Creat12()
{
	BiTNode *tmp = NULL;
	char ch;
	printf("\n请输入字符: ");
	scanf("%c", &ch);
	if (ch == ' ')
	{
		return NULL;
	}
	else
	{
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch; //生成根结点
		tmp->lchild = BiTree_Creat12();//构建左子树
		tmp->rchild = BiTree_Creat12();//构建右子数
		return tmp;
	}
}

void main20()
{
	int nCount = 0, depthval = 0;
	BiTNode * my = BiTree_Creat12();
	printf("\n非递归算法c++访问\n");
	InOrder(my);
	printf("\n");
	system("pause");
}
