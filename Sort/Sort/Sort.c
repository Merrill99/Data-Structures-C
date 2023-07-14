#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"stcak.h"

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
			if (tmp < a[end])
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
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
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
	for (int i = n - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

// ����������Ż�������ȡ�з�
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[right] < a[left])
			return right;
		else
			return left;
	}
	else //a[left] >= a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return right;
		else
			return left;
	}
}

int PartSort1(int* a, int left, int right)
{
	// �õ�keyi��λ����left����
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	keyi = left;
	while (left < right)
	{
		// �ұ����ߣ���С����Сֹͣ
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// ����Ҵ�����ֹͣ
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

int PartSort2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// �ұ���С
		while (left < right && a[right] >= key)
		{
			--right;
		}
		// �ҵ������λ��
		a[hole] = a[right];
		// ��λ����
		hole = right;
		// ����Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		// �ҵ������λ��
		a[hole] = a[left];
		// ��λ����
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int prev = left, cur = left + 1;
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			++prev;
			Swap(&a[cur], &a[prev]);
		}
		// curʼ����ǰ��һ��
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = PartSort3(a, left, right);

	//����:[left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);

}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	STIniti(&st);

	// ѹ������[left,right];
	STPush(&st, right);
	STPush(&st, left);
	while (!IsEmpty(&st))
	{
		// �������������
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort3(a, begin, end);

		// [begin,keyi-1] keyi [keyi+1,end];
		if (begin < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
		
	}

	STDestroy(&st);
}
