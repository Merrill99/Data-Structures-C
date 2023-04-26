#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SLPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SListDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushFront(SLTNode** pphead, SListDataType x)
{
	//pphead的地址本身不能为空
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLPushBack(SLTNode** pphead, SListDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	//判断是否为空链表
	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	//找尾
	SLTNode* tail = *pphead;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = newnode;
	newnode->next = NULL;
}

void SLPopFront(SLTNode** pphead)
{
	//pphead的地址和pphead都不能为空
	//为空则不能删除
	assert(pphead && *pphead);

	SLTNode* tmp = *pphead;
	*pphead = tmp->next;
	free(tmp);
}

void SLPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* tail = *pphead;
	//如果链表仅剩一个元素
	if (tail->next == NULL)
	{
		*pphead = NULL;
		free(tail);
		return;
	}
	//找尾以及尾的前一个
	while (tail->next->next)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}

SLTNode* SLFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLInsertBefore(SLTNode** pphead, SLTNode* pos, SListDataType x)
{
	SLTNode* prev = *pphead;
	SLTNode* newnode = BuySLTNode(x);
	//如果要插入的位置为首个元素之前，则进行头插
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		//找到pos位置的前一个
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SLInsertAfter(SLTNode* pos, SListDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLEarse(SLTNode** pphead, SLTNode* pos)
{
	SLTNode* prev = *pphead;
	SLTNode* tmp = pos;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(tmp);
}

void SLEarseAfter(SLTNode* pos)
{
	//如果pos为最后一位，则不能删除
	assert(pos->next);

	SLTNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}