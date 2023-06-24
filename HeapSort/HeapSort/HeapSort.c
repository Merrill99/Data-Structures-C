#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

//方法一：向上调整建堆
//void HeapSort(int* arr, int sz)
//{
//	//向上调整建堆
//	for (int i = 1; i < sz; ++i)
//	{
//		AdjustUp(arr, i);
//	}
//
//	int end = sz - 1;
//	
//	while (end > 0)
//	{
//		// 首end元素交换，将最小的放在end上
//		HeapSwap(&arr[0], &arr[end]);
//		// 将end(end即为之前元素的个数)之前的元素继续向下调整成堆（和删除有点像）
//		AdjustDown(arr, end, 0);
//
//		--end;
//	}
//}

// 方法二：向下调整建堆
void HeapSort(int* arr, int sz)
{
	// 从最后一个叶子节点的父亲节点开始向下调整
	// sz - 1是最后一个叶子节点，(sz-1-1)/2是其父亲节点
	for (int i = (sz - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, sz, i);
	}

	int end = sz - 1;
		
	while (end > 0)
	{
		// 首end元素交换，将最小(大)的放在end上
		HeapSwap(&arr[0], &arr[end]);
		// 将end(end即为之前元素的个数)之前的元素继续向下调整成堆（和删除有点像）
		AdjustDown(arr, end, 0);
	
		--end;
	}
}

int main()
{
	int arr[] = { 8,6,7,9,1,0,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, sz);
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}