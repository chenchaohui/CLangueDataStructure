#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����������ʽ�洢����������������������˫������
#define Max_Size 100
//��������
typedef struct BITNode
{
	int data;
	struct BITNode *lchild,*rchild;
}BITNode,*BTree;

//��������
typedef struct TriTNode
{
	 int data;
	 struct TriTNode *lchild,*rchild, *parent;
}TriTNode,*TriTree;

//˫������
typedef struct BPTNode
{
	int data;
	struct BPTNode *parent;
	char LRCTag;
}BPTNode;

typedef struct BPTree
{
 //����һ��˫������ڵ�ṹ�����͵�����
 BPTNode node[Max_Size];
 //�����ʵ�ʴ�С
 int size;
 //�洢���׽ڵ��������е��±�
 int root;
}BPTree;

/*************�������ĵݹ���ʽ�ı���***********/
//�������
void PreOrder(BITNode *T)
{
	if (T != NULL)
	{
		printf("%d ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//�������
void InOrder(BITNode *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%d ",T->data);
		InOrder(T->rchild);
	}
}

//�������
void PostOrder(BITNode *T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d ",T->data);
	}
}
/*************��������********************/


/***********�������Ҷ�ӽڵ�ĸ���********/
//ע�⣺��Ҷ�ӽڵ�ĸ������ֱ����������ȸ����и��������������

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
/****************����**********************/


/***********��������ĸ߶�*****************/
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
/****************����**********************/


/**********************�������Ŀ���********************/

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






/************************�������**********************/

void main()
{
	/*�����Զ�������Ĵ洢��ʽ����һ��������*/
	BITNode t1,t2,t3,t4,t5;
	BITNode *newnode = NULL;
	int count = 0;
	int height = 0;
//ע������������t1,t2,t3,t4,t5 5���ṹ�����ռ�õ��ڴ�ռ��ʼ��Ϊ0��������ڲ���ָ���Ա�����ĳ�ʼֵ����һ������ֵ�����ܻᵼ�³���������ʲ���������ڴ�ռ��ʼ���Ĳ���
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
	/*******************************�������*/
	printf("\n���������");
	PreOrder(&t1);
	printf("\n���������");
	InOrder(&t1);
	printf("\n���������");
	PostOrder(&t1);
	Count_Leaf(&t1,&count);
	printf("����Ҷ�ӽڵ�ĸ�����leaf = %d\n",count);

	height = Count_BTree_Height(&t1);
	printf("Tree Height = %d\n",height);

	newnode = copy_BiTree(&t1);
	printf("\n���������");
	PreOrder(newnode);
	printf("\n���������");
	InOrder(newnode);
	printf("\n���������");
	PostOrder(newnode);
	count = 0;
	Count_Leaf(newnode,&count);
	printf("����Ҷ�ӽڵ�ĸ�����leaf = %d\n",count);

	height = Count_BTree_Height(newnode);
	printf("Tree Height = %d\n",height);
	system("pause");
}