#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	return newnode;
}

ListNode* IntiList()
{
	ListNode* head = BuyListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void LTPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	printf("guard<=>");
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	//创建新节点
	ListNode* newnode = BuyListNode(x);
	//记录尾
	ListNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void LTPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* newnode = BuyListNode(x);
	//记录头
	ListNode* head = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = head;
	head->prev = newnode;
}

bool IsEmpty(ListNode* phead)
{
	assert(phead);

	return (phead->next != phead);
}

void LTPopBack(ListNode* phead)
{
	assert(phead);
	assert(IsEmpty(phead));

	//记录尾和尾的前一个
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;

	phead->prev = tailprev;
	tailprev->next = phead;

	free(tail);
}

void LTPopFront(ListNode* phead)
{
	assert(phead);
	assert(IsEmpty(phead));

	//记录头和头的后一个
	ListNode* head = phead->next;
	ListNode* headnext = head->next;

	phead->next = headnext;
	headnext->prev = phead;

	free(head);
}

ListNode* LTFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	//记录pos位置的前一个
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTEarse(ListNode* pos)
{
	assert(pos);

	//记录pos位置的前后
	ListNode* posprev = pos->prev;
	ListNode* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void LTDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//释放哨兵位
	free(phead);
}