#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void HeapIniti(Heap* php)
{
	assert(php);

	//��ʼ�ռ�Ϊ4
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

	//��������Ƿ�����������������
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
	//���ϵ�������
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
		// ��ѣ�˫��С�ں��ӽ��е���(��С�ѵķ����෴)
		// if (a[parent] < a[child])
		// С�ѣ�˫�״��ں�������е���
		if (a[parent] > a[child])
		{
			HeapSwap(&a[parent], &a[child]);
		}
		//�������ݵĹ����У����Ѿ��γɣ��������������ֱ������
		else
		{
			break;
		}
		//�����ӷŵ�˫�׵�λ���ϣ���������
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
	//�пգ�Ϊ������ɾ��
	assert(!HeapEmpty(php));

	//��βԪ�ؽ���
	HeapSwap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;

	//���µ���(�������鳤�ȣ�����Ҫ������Ԫ��λ��)
	AdjustDown(php->arr, php->size, 0);
	
}

// �������д��
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	//�ж����Һ��Ӵ��С��ѡ����С/����Ǹ�
//	int child = a[parent * 2 + 1] < a[parent * 2 + 2] ? (parent * 2 + 1) : (parent * 2 + 2);
//
//	//���ӽڵ���Ҷ�ڵ�ʱ����
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
	// ���跨
	// ���������ǽ�С(��)���Ǹ�
	int child = parent * 2 + 1;
	while (child < n)
	{
		// �Һ��Ӵ������Һ���С(��)�����ӣ�����child���±�
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		// �����븸�ױȽ�
		if (a[child] < a[parent])
		{
			HeapSwap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//����λ���Ѿ��Ƕѣ�������ֱ������
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	//�п�
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