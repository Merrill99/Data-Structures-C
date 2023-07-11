#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		// ��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp > a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//void ShellSort(int* a, int n)
//{ 
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int j = 0; j < gap; ++j)
//		{
//			for (int i = j; i < n - gap; i += gap)
//			{
//				// Ԥ����
//				int end = i;
//				int tmp = a[end + gap];
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		// ��֤gap���һ����1
		// Ҳ��д��gap /= 2
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			// Ԥ����
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = end;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[maxi], &a[end]);
		// ���mini��end�ص�����������
		if (mini == end)
		{
			mini = maxi;
		}
		Swap(&a[mini], &a[begin]);
		++begin;
		--end;
	}
}

void BubbleSort(int* a, int n)
{
	int flag = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		// һ��ð��
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		// ���ðһ��δ������������֤����������ѭ��
		if (1 == flag)
			break;
	}
}

void AdjustDown(int* a, int n, int parent)
{

	int child = parent * 2 + 1;
	while (child < n)
	{
		// ������ѣ�����Һ��Ӵ������ӣ�����child
		// �����Һ��Ӵ���
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
	
}

void HeapSort(int* a, int n)
{
	// �����һ��Ҷ�ӽڵ��˫�׽ڵ㿪ʼ���µ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// ����
	for (int i = n - 1; i >= 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}