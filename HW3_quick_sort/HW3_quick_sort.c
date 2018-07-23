#include <stdio.h>

typedef struct vec
{
	int x;
}vec;

void Swap(vec *arr, int idx1, int idx2)
{
	int temp = arr[idx1].x;
	arr[idx1].x = arr[idx2].x;
	arr[idx2].x = temp;
}


int Partition(vec *arr, int left, int right)
{
	int pivot = arr[left].x;    // �ǹ��� ��ġ�� ���� ����! 
	int low = left + 1;
	int high = right;
	int i;

	while (low <= high)    // �������� ���� ������ �ݺ�
	{
		while (pivot > arr[low].x)
			low++;

		while (pivot < arr[high].x)
			high--;

		/*
		while(pivot >= arr[low] && low <= right)
		low++;

		while(pivot <= arr[high] && high >= (left+1))
		high--;
		*/

		if (low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
		printf("p1: ");
		for (i = left; i <= right; ++i) printf("%d ", arr[i].x);
		printf("\n");
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	printf("p2: ");
	for (i = left; i <= right; ++i) printf("%d ", arr[i].x);
	printf("\n");
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(vec *arr, int left, int right)
{
	int i;
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		for (i = left; i <= right; ++i) printf("%d ", arr[i].x);
		printf("\n");

		QuickSort(arr, left, pivot - 1);    // ���� ������ ����
		QuickSort(arr, pivot + 1, right);    // ������ ������ ����
	}
}

int main(void)
{
	vec arr[7] = {
		{ 3 }, { 2 }, { 4 }, { 1 }, { 7 }, { 6 }, { 5 }
	};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i<len; i++)
		printf("%d ", arr[i].x);

	printf("\n");
	return 0;
}
