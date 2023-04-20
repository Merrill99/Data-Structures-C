#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SLIniti(SeqList* psl)
{
	//断言
	assert(psl);
	//开辟初始空间,给定初始空间为4
	SLDataType* tmp = (SLDataType*)malloc(4 * sizeof(SLDataType));
	//如果开辟失败
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->data = tmp;
	psl->size = 0;
	psl->capacity = 4;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(psl->data, 2 * psl->capacity *sizeof(SLDataType));
		//判断开辟失败
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->data = tmp;
		psl->capacity *= 2;
	}
}

void SLPushBack(SeqList* psl, SLDataType x)
{
	//assert(psl);
	////检查容量是否已满
	//CheckCapacity(psl);
	//psl->data[psl->size] = x;
	//psl->size++;
	
	//复用SLInsert
	SLInsert(psl, psl->size, x);
}

void SLPopBack(SeqList* psl)
{
	//assert(psl);
	////删空后不能再删除
	//assert(psl->size > 0);
	//psl->size--;

	//复用SLErase
	SLErase(psl, psl->size - 1);
}

void SLPushFront(SeqList* psl, SLDataType x)
{
	//assert(psl);
	////检查容量是否已满
	//CheckCapacity(psl);
	//int tmp = psl->size;
	//while (tmp)
	//{
	//	psl->data[tmp] = psl->data[tmp - 1];
	//	--tmp;
	//}
	//psl->data[0] = x;
	//psl->size++;

	//头插，复用SLInsert
	SLInsert(psl, 0, x);
}

void SLPopFront(SeqList* psl)
{
	//assert(psl);
	////删空后不能再删除
	//assert(psl->size > 0);
	//int tmp = 1;
	//while (tmp < psl->size)
	//{
	//	psl->data[tmp - 1] = psl->data[tmp];
	//	++tmp;
	//}
	//psl->size--;

	//复用SLErase
	SLErase(psl, 0);
}

void SLInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	//检查容量是否已满
	CheckCapacity(psl);
	int tmp = psl->size;
	while (tmp > pos)
	{
		psl->data[tmp] = psl->data[tmp - 1];
		tmp--;
	}
	psl->data[pos] = x;
	psl->size++;
}

void SLErase(SeqList* psl, int pos)
{
	assert(psl);
	//删空后不能再删除
	assert(pos >= 0 && pos < psl->size);
	int tmp = pos + 1;
	while (tmp < psl->size)
	{
		psl->data[tmp - 1] = psl->data[tmp];
		++tmp;
	}
	psl->size--;
}

void SLPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->data[i]);
	}
	printf("\n");
}

int SLFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		if (x == psl->data[i])
		{
			return i;
		}
	}
	return -1;
}

void SLModify(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);

	psl->data[pos] = x;
}

void SLDestory(SeqList* psl)
{
	assert(psl);
	psl->capacity = 0;
	psl->size = 0;
	free(psl->data);
	psl->data = NULL;
}