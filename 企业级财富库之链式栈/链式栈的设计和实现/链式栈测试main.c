//ע����ʽջ�ڵ��ڴ洢����ָ����ʽ�ڵ����͵�ָ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"


void main()
{
	int ret = 0;
	int i=0, a[10], tmp = 0;
	LinkStack* stack = NULL;
	stack = LinkStack_Create();

	for (i=0; i<5; i++)
	{
		a[i] = i+1;
		ret = LinkStack_Push(stack, (void *)&a[i]);
	}

	tmp = * ((int *)LinkStack_Top(stack) );
	printf("zhanջ����%d\n", tmp);
	printf("length:%d \n", LinkStack_Size(stack));

	while(LinkStack_Size(stack) > 0)
	{
		tmp =  *((int *)LinkStack_Pop(stack) );
		printf("tmp:%d \n", tmp);
	}

	LinkStack_Destroy( stack);

	system("pause");
	return ;

}