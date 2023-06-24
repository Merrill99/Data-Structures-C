#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

//����һ�����ϵ�������
//void HeapSort(int* arr, int sz)
//{
//	//���ϵ�������
//	for (int i = 1; i < sz; ++i)
//	{
//		AdjustUp(arr, i);
//	}
//
//	int end = sz - 1;
//	
//	while (end > 0)
//	{
//		// ��endԪ�ؽ���������С�ķ���end��
//		HeapSwap(&arr[0], &arr[end]);
//		// ��end(end��Ϊ֮ǰԪ�صĸ���)֮ǰ��Ԫ�ؼ������µ����ɶѣ���ɾ���е���
//		AdjustDown(arr, end, 0);
//
//		--end;
//	}
//}

// �����������µ�������
void HeapSort(int* arr, int sz)
{
	// �����һ��Ҷ�ӽڵ�ĸ��׽ڵ㿪ʼ���µ���
	// sz - 1�����һ��Ҷ�ӽڵ㣬(sz-1-1)/2���丸�׽ڵ�
	for (int i = (sz - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, sz, i);
	}

	int end = sz - 1;
		
	while (end > 0)
	{
		// ��endԪ�ؽ���������С(��)�ķ���end��
		HeapSwap(&arr[0], &arr[end]);
		// ��end(end��Ϊ֮ǰԪ�صĸ���)֮ǰ��Ԫ�ؼ������µ����ɶѣ���ɾ���е���
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