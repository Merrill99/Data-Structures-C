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
		// 单趟排序
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
//				// 预排序
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
		// 保证gap最后一次是1
		// 也可写作gap /= 2
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			// 预排序
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
		// 如果mini和end重叠，进行修正
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
		// 一趟冒泡
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		// 如果冒一趟未发生交换，则证明有序，跳出循环
		if (1 == flag)
			break;
	}
}

void AdjustDown(int* a, int n, int parent)
{

	int child = parent * 2 + 1;
	while (child < n)
	{
		// （建大堆）如果右孩子大于左孩子，更新child
		// 并且右孩子存在
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
	// 从最后一个叶子节点的双亲节点开始向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// 排序
	for (int i = n - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

// 快速排序的优化，三数取中法
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
	// 得到keyi的位置与left交换
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	keyi = left;
	while (left < right)
	{
		// 右边先走，找小，遇小停止
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边找大，遇大停止
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
		// 右边找小
		while (left < right && a[right] >= key)
		{
			--right;
		}
		// 找到放入坑位中
		a[hole] = a[right];
		// 坑位更新
		hole = right;
		// 左边找大
		while (left < right && a[left] <= key)
		{
			++left;
		}
		// 找到放入坑位中
		a[hole] = a[left];
		// 坑位更新
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
		// cur始终向前走一步
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

	//区间:[left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);

}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	STIniti(&st);

	// 压入区间[left,right];
	STPush(&st, right);
	STPush(&st, left);
	while (!IsEmpty(&st))
	{
		// 出区间进行排序
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
