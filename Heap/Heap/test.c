#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void HeapTest()
{
	Heap hp;
	HeapIniti(&hp);

	HeapPush(&hp, 10);
	HeapPush(&hp, 56);
	HeapPush(&hp, 15);
	HeapPush(&hp, 25);
	HeapPush(&hp, 30);
	HeapPush(&hp, 70);

	for (int i = 0; i < hp.size; ++i)
	{
		printf("%d ", hp.arr[i]);
	}
	printf("\n");

	HeapPush(&hp, 40);
	for (int i = 0; i < hp.size; ++i)
	{
		printf("%d ", hp.arr[i]);
	}
	printf("\n");
	HeapPop(&hp);
	HeapPop(&hp);

	for (int i = 0; i < hp.size; ++i)
	{
		printf("%d ", hp.arr[i]);
	}
	printf("\n");

	int size = HeapSize(&hp);

	HeapDeastory(&hp);
}

int main()
{
	HeapTest();
	return 0;
}

