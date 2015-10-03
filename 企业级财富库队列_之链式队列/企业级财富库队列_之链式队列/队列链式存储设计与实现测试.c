#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "linkqueue.h"

void main()
{
	int i = 0, a[10], tmp = 0;
	LinkQueue *queue = NULL;
	
	queue =  LinkQueue_Create();

	for (i=0; i<5; i++)
	{
		a[i] = i+1;
		LinkQueue_Append(queue, (void *)&a[i]);
	}
	tmp = *((int *)LinkQueue_Header(queue));
	printf("头元素:%d\n", tmp);
	printf("队列长度:%d\n", LinkQueue_Length(queue));

	while (LinkQueue_Length(queue) > 0)
	{
		tmp = *((int *)LinkQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}

	LinkQueue_Destroy(queue);
	system("pause");
}