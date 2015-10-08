#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//二叉树的链式存储：包括二叉链表，三叉链表，双亲链表
#define Max_Size 100
//二叉链表
typedef struct BITNode
{
	int data;
	struct BITNode *lchild,*rchild;
}BITNode,*BTree;

//三叉链表
typedef struct TriTNode
{
	 int data;
	 struct TriTNode *lchild,*rchild, *parent;
}TriTNode,*TriTree;

//双亲链表
typedef struct BPTNode
{
	int data;
	struct BPTNode *parent;
	char LRCTag;
}BPTNode;

typedef struct BPTree
{
 //定义一个双亲链表节点结构体类型的数组
 BPTNode node[Max_Size];
 //数组的实际大小
 int size;
 //存储父亲节点在数组中的下表
 int root;
}BPTree;

/*************二叉树的递归形式的遍历***********/
//先序遍历
void PreOrder(BITNode *T)
{
	if (T != NULL)
	{
		printf("%d ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序遍历
void InOrder(BITNode *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%d ",T->data);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BITNode *T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d ",T->data);
	}
}
/*************遍历结束********************/


/***********求二叉树叶子节点的个数********/
//注意：求叶子节点的个数三种遍历方法（先根，中根，后根）均可以

void Count_Leaf(BITNode *T,int *count)
{
	if ( T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			(*count)++;
		}
		Count_Leaf(T->lchild,count);
		Count_Leaf(T->rchild,count);
	}
}
/****************求完**********************/


/***********求二叉树的高度*****************/
int Count_BTree_Height(BITNode *T)
{
	int depval = 0,depl = 0, depr = 0;
	if ( T == NULL)
	{
		return depval;
	}
	depl = Count_BTree_Height(T->lchild);
	depr = Count_BTree_Height(T->rchild);
	depval = 1 + ((depl>depr)?depl:depr);
	return depval;
}
/****************求完**********************/


/**********************二叉树的拷贝********************/

BITNode *copy_BiTree(BITNode * T)
{
   BITNode *newNode = NULL, *newlptr = NULL, *newrptr = NULL;
   if (  T== NULL )
   {
	   return NULL;
   }
   if ( T->lchild !=NULL)
   {
     newlptr = copy_BiTree(T->lchild);
   }
   else
   {
	   newlptr = NULL;
   }
   if ( T->rchild !=NULL)
   {
	   newrptr = copy_BiTree(T->rchild);
   }
   else
   {
	   newrptr = NULL;
   }
   newNode = (BITNode *)malloc(sizeof(BITNode));
   newNode->lchild = newlptr;
   newNode->rchild = newrptr;
   newNode->data = T->data;
   return newNode;
}






/************************拷贝完成**********************/

void main()
{
	/*现在以二叉链表的存储形式创建一个二叉树*/
	BITNode t1,t2,t3,t4,t5;
	BITNode *newnode = NULL;
	int count = 0;
	int height = 0;
//注意事项：如果不对t1,t2,t3,t4,t5 5个结构体变量占用的内存空间初始化为0，则变量内部的指针成员变量的初始值就是一个垃圾值，可能会导致程序崩溃，故才有下面的内存空间初始化的步骤
	memset(&t1,0,sizeof(BITNode));
	memset(&t2,0,sizeof(BITNode));
	memset(&t3,0,sizeof(BITNode));
	memset(&t4,0,sizeof(BITNode));
	memset(&t5,0,sizeof(BITNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;
	/*******************************创建完成*/
	printf("\n先序遍历：");
	PreOrder(&t1);
	printf("\n中序遍历：");
	InOrder(&t1);
	printf("\n后序遍历：");
	PostOrder(&t1);
	Count_Leaf(&t1,&count);
	printf("树的叶子节点的个数是leaf = %d\n",count);

	height = Count_BTree_Height(&t1);
	printf("Tree Height = %d\n",height);

	newnode = copy_BiTree(&t1);
	printf("\n先序遍历：");
	PreOrder(newnode);
	printf("\n中序遍历：");
	InOrder(newnode);
	printf("\n后序遍历：");
	PostOrder(newnode);
	count = 0;
	Count_Leaf(newnode,&count);
	printf("树的叶子节点的个数是leaf = %d\n",count);

	height = Count_BTree_Height(newnode);
	printf("Tree Height = %d\n",height);
	system("pause");
}