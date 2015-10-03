#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//顺序表的设计
typedef struct _tag_seqlist
{
	//预先设定的顺序表的容量
	int capacity;
	//顺序表中实际节点的个数（长度）
	int length;
	//指向节点数据的指针
	unsigned int *node;

}Tseqlist;


//提示：void类型的指针可以接收任何数据类型的指针
SeqList* SeqList_Create(int capacity)
{
   int ret = 0;
   Tseqlist *seqlist = NULL;
   //为顺序表对象及其数据节点开辟内存空间
   seqlist = (Tseqlist *) malloc (sizeof(Tseqlist) + sizeof(unsigned int) * capacity);

   //异常处理
   if (capacity <= 0)
   {
	   ret =-1;
	    printf("func SeqList_Create Err %d",ret);
		return NULL;
   }
   //异常处理
   if (seqlist == NULL)
   {
	   ret = -2;
	   printf("func SeqList_Create Err %d",ret);
	   return NULL;
   }
   //让指针指向顺序表的数据节点
   seqlist->node = (unsigned int *)(seqlist +1);

   //顺序表成员初始化
   seqlist->length = 0;
   seqlist->capacity = capacity;
   return seqlist;
}

//销毁顺序表
void SeqList_Destroy(SeqList* list)
{
	//异常处理
	int ret = 0;
	if (list == NULL)
	{
		ret  = -1;
		printf("func SeqList_Destroy err %d",ret);
		return ;
	}
	//释放内存
	free(list);
}

//顺序表长度清0
void SeqList_Clear(SeqList* list)
{   
	int ret  = 0;
	Tseqlist *tlist = NULL;
	//先做异常处理
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return ;
	}
	//数据类型间的赋值需要类型转化
    tlist = (Tseqlist *)list;
	//将顺序表的长度清零
	tlist->length = 0;
}

int SeqList_Length(SeqList* list)
{
	int ret  = 0;
	Tseqlist *tlist = NULL;
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return ret;
	}
     tlist = (Tseqlist *)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	int ret  = 0;
	Tseqlist *tlist = NULL;
	if ( list == NULL)
	{
		ret =-1;
		printf("func SeqList_Clear err %d",ret);
		return  ret;
	}
	tlist = (Tseqlist *)list;
	return tlist->capacity;
}



//在顺序表的某个位置插入一个节点
//这个方法是一个常用的方法，必须熟记解题步骤
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0;
	int i = 0;
	//int tmp;
	//先做异常处理
	Tseqlist *tlist = (Tseqlist *)list;
	if (list == NULL || node == NULL || pos<0 || pos >=tlist->capacity)
	{
		ret  = -1;
		printf("func SeqList_Insert err %d",ret);
		return ret;
	}
	//异常处理
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}
	for (i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}

	tlist->node[pos] = (unsigned int )node;
	//顺序表的长度要记得++
	tlist->length++;
	return 0;
}

//根据位置获取顺序表节点值pos表示数组的下表，值从0开始
//采用SeqListNode*是不想让上从应用知道节点的具体数据类型
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
    //先进行异常处理
	Tseqlist *tlist = (Tseqlist *)list;
	if (list ==NULL || pos<0 || pos >= tlist->length)
	{
		ret = -1;
		printf("func SeqList_Get err %d",ret);
		return NULL;
	}
	return (SeqListNode*)tlist->node[pos];	
}

//根据位置获取删除节点的值
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	//先做异常处理
	int ret = 0;
	int i = 0;
	Tseqlist *tlist = (Tseqlist *)list;
	//定义一个SeqListNode*这种数据类型变量，用于存储删除节点的值
	SeqListNode *tmp = NULL;
	if (list == NULL || pos >= tlist->length)
	{
		ret = -1;
		printf("func SeqList_Delete err %d",ret);
		return NULL;
	}
	//将无符号整型数据转化为(SeqListNode *)类型的数据
	tmp = (SeqListNode *)tlist->node[pos];
	for (i = pos + 1; i < tlist->length; i++)
	{
      tlist->node[i-1] = tlist->node[i];
	}

	tlist->length--;
	return tmp;
}