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
	//pphead�ĵ�ַ������Ϊ��
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLPushBack(SLTNode** pphead, SListDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	//�ж��Ƿ�Ϊ������
	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	//��β
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
	//pphead�ĵ�ַ��pphead������Ϊ��
	//Ϊ������ɾ��
	assert(pphead && *pphead);

	SLTNode* tmp = *pphead;
	*pphead = tmp->next;
	free(tmp);
}

void SLPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* tail = *pphead;
	//��������ʣһ��Ԫ��
	if (tail->next == NULL)
	{
		*pphead = NULL;
		free(tail);
		return;
	}
	//��β�Լ�β��ǰһ��
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
	//���Ҫ�����λ��Ϊ�׸�Ԫ��֮ǰ�������ͷ��
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		//�ҵ�posλ�õ�ǰһ��
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
	//���posΪ���һλ������ɾ��
	assert(pos->next);

	SLTNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}