#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CircleLinkList.h"

//����һ��ҵ��ṹ��
typedef struct _tag_value
{
	TCircleLinkListNode node;
	int v;

}Tvalue;


void main01()
{
	int i = 0;
	Tvalue v1,v2,v3,v4,v5;
	CircleLinkList *list = NULL;
	Tvalue* tlist= NULL;
	TCircleLinkListNode *Pcn = NULL;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;


	//����һ��ѭ������ͷ
	list =  CircleLinkList_Create();
	
	//�������е�posλ�ò���һ���ڵ㣨pos��ֵ��0��ʼ��
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v1, 0);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v2, 1);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v3, 2);
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v4, 3);	
	CircleLinkList_Insert(list,(TCircleLinkListNode *)&v5, 4);

	//����ող���Ľڵ�
	 for ( i=0; i < CircleLinkList_Length(list); i++)
	 { 
		 //��ȡѭ�������еĵ�i���ڵ�
          tlist = (Tvalue*)CircleLinkList_Get(list, i);
		  printf("%d ",tlist->v);
	 }
	 printf("\n");
	 //ɾ�������е�posλ���ϵĽڵ㣨pos��ֵ��0��ʼ��
	// Pcn =  CircleLinkList_Delete(list, 0);
	 //Pcn =  CircleLinkList_Delete(list, 1);
	 //Pcn =  CircleLinkList_Delete(list, 2);

	// for ( i=0; i < CircleLinkList_Length(list); i++)
	// { 
		 //��ȡѭ�������еĵ�i���ڵ�
	//	 tlist = (Tvalue*)CircleLinkList_Get(list, i);
	//	 printf("%d ",tlist->v);
	// }
	 //������Ϊ2��4

	 //ɾ������ڵ�
	 Pcn =  CircleLinkList_Get(list, 0);
	 Pcn =  CircleList_DeleteNode(list, Pcn);

	 for ( i = 0; i < CircleLinkList_Length(list); i++)
	 { 
		 //��ȡѭ�������еĵ�i���ڵ�
		 tlist = (Tvalue*)CircleLinkList_Get(list, i);
		 printf("%d ",tlist->v);
	 }

	 ////�����α꣬ʹ��ص���ʼ״̬
	 //CircleList_Reset(list);

	 ////��ȡ��ǰ�α��ֵ
	 //CircleList_Current(list);

	 ////�α�����һ����λ
  //   CircleList_Next(list);


	 //��������������״̬(ѭ������ֻ��ͷ����״̬)
	 CircleLinkList_Clear(list);

	//���٣�ֻ�裩����ͷ������ҵ��ڵ�����������ɲ��Ժ�������
	 CircleLinkList_Destroy(list);



	//API ADD ���ӵ�API����






	



  system("pause");
}