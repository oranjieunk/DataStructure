#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	int data, bb[20], i;

	for (i = 0; i < 20; i++) bb[i] = (int)((double)rand() / RAND_MAX*5.0 + 1.0);

	for (i = 0; i < 20; i++) printf("%d\n", bb[i]);
	ListInit(&list);
	//SetSortRule(&list, compare);

	LRemoveD(&list);
	qsort(bb, 20, sizeof(int), compAsc);
	for (i = 0; i<20; i++) LInsert(&list, bb[i]);

	// ���� �� �����ִ� ������ ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n-��������-\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");


	return 0;
}
