#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "seqqueue.h"

void main()
{
	int i = 0, a[10], tmp = 0;
	SeqQueue*  queue = NULL;

	queue = SeqQueue_Create(10);

	for (i=0; i<5; i++)
	{
		a[i] = i+1;
		SeqQueue_Append(queue, (void *)&a[i]);
	}

	tmp = *((int *)SeqQueue_Header(queue));
	printf("���е�ͷԪ��:%d \n", tmp);
	printf("���е�length:%d \n", SeqQueue_Length(queue));
	printf("���е�cap:%d \n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0)
	{
		tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}
	SeqQueue_Destroy(queue);
	system("pause");
}