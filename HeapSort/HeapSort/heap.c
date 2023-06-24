#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void HeapIniti(Heap* php)
{
	assert(php);

	//初始空间为4
	HPDataType* tmp = (HPDataType*)malloc(4 * sizeof(HPDataType));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->arr = tmp;
	php->size = 0;
	php->capacity = 4;
}

void HeapPush(Heap* php, HPDataType value)
{
	assert(php);

	//检测容量是否已满，满了则扩容
	if (php->capacity == php->size)
	{
		php->capacity *= 2;
		HPDataType* newarr = (HPDataType*)realloc(php->arr, php->capacity * sizeof(HPDataType));
		if (newarr == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->arr = newarr;
	}

	php->arr[php->size] = value;
	//向上调整建堆
	AdjustUp(php->arr, php->size);

	++php->size;
}

void HeapSwap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	
	while (child > 0)
	{
		// parent = (child+1)/2
		int parent = (child - 1) / 2;
		// 大堆，双亲小于孩子进行调整(与小堆的符号相反)
		// if (a[parent] < a[child])
		// 小堆，双亲大于孩子则进行调整
		if (a[parent] > a[child])
		{
			HeapSwap(&a[parent], &a[child]);
		}
		//插入数据的过程中，堆已经形成，所以如果不大于直接跳出
		else
		{
			break;
		}
		//将孩子放到双亲的位置上，继续调整
		child = parent;
	}
}

bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->size == 0;
}

void HeapPop(Heap* php)
{
	assert(php);
	//判空，为空则不能删除
	assert(!HeapEmpty(php));

	//首尾元素交换
	HeapSwap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;

	//向下调整(传入数组长度，传入要调整的元素位置)
	AdjustDown(php->arr, php->size, 0);
	
}

// 有问题的写法
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	//判断左右孩子大大小，选出较小/大的那个
//	int child = a[parent * 2 + 1] < a[parent * 2 + 2] ? (parent * 2 + 1) : (parent * 2 + 2);
//
//	//孩子节点是叶节点时结束
//	while (child < n)
//	{
//		HeapSwap(&a[child], &a[parent]);
//
//		parent = child;
//		child = a[parent * 2 + 1] > a[parent * 2 + 2] ? (parent * 2 + 1) : (parent * 2 + 2);
//	}
//}

void AdjustDown(HPDataType* a, int n, int parent)
{
	// 假设法
	// 假设左孩子是较小(大)的那个
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 右孩子存在且右孩子小(大)于左孩子，则变更child的下标
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		// 孩子与父亲比较
		if (a[child] < a[parent])
		{
			HeapSwap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//其余位置已经是堆，不符合直接跳出
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	//判空
	assert(!HeapEmpty(php));

	return php->arr[0];
}

int HeapSize(Heap* php)
{
	assert(php);

	return php->size;
}

void HeapDeastory(Heap* php)
{
	assert(php);

	free(php->arr);
	php->capacity = php->size = 0;
}