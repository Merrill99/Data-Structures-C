#define _CRT_SECURE_NO_WARNINGS 1

#include"stcak.h"

void STIniti(Stack* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->capacity = 0;
	//top 指向栈顶数据的下一个位置
	pst->top = 0;
}

void STPush(Stack* pst, STDataType x)
{
	assert(pst);
	
	if (pst->capacity == pst->top)
	{
		//(pst->capacity == 0) ? (pst->capacity = 4) : (pst->capacity *= 2);
		int newcapacity = pst->capacity == 0 ? pst->capacity = 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->arr, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}

	pst->arr[pst->top++] = x;
}

bool IsEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

void STPop(Stack* pst)
{
	assert(pst);
	//判空
	assert(!IsEmpty(pst));
	
	pst->top--;
}

STDataType STTop(Stack* pst)
{
	assert(pst);
	//判空
	assert(!IsEmpty(pst));

	return pst->arr[pst->top - 1];
}

int STSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

void STDestroy(Stack* pst)
{
	assert(pst);

	pst->capacity = 0;
	pst->top = 0;
	free(pst->arr);
}