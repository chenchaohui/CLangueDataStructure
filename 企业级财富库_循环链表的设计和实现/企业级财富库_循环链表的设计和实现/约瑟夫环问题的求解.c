#include <stdio.h>
#include <stdlib.h>
#include "CircleLinkList.h"

struct Value
{
	TCircleLinkListNode header;
	int v;
};

void  main()
{
	int i = 0;
	CircleLinkList* list = CircleLinkList_Create();

	struct Value v1, v2, v3, v4, v5, v6, v7, v8;

	v1.v = 1;	v2.v = 2;	v3.v = 3;	v4.v = 4;	
	v5.v = 5;	v6.v = 6;	v7.v = 7;	v8.v = 8;

	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v1, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v2, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v3, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v4, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v5, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v6, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v7, CircleLinkList_Length(list));
	CircleLinkList_Insert(list, (TCircleLinkListNode*)&v8, CircleLinkList_Length(list));

	for(i = 0; i<CircleLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)CircleList_Next(list);
		printf("%d\n", pv->v);
	}

	printf("\n");

	CircleList_Reset(list);

	while( CircleLinkList_Length(list) > 0 )
	{
		struct Value* pv = NULL;
		for(i=1; i<3; i++)
		{
			CircleList_Next(list);
		}
		pv = (struct Value*)CircleList_Current(list);
		printf("%d\n", pv->v);
		CircleList_DeleteNode(list, (TCircleLinkListNode*)pv);
	}

	CircleLinkList_Destroy(list);

	system("pause");
	return ;
}
