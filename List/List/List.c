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

	//�����½ڵ�
	ListNode* newnode = BuyListNode(x);
	//��¼β
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
	//��¼ͷ
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

	//��¼β��β��ǰһ��
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

	//��¼ͷ��ͷ�ĺ�һ��
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

	//��¼posλ�õ�ǰһ��
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

	//��¼posλ�õ�ǰ��
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
	//�ͷ��ڱ�λ
	free(phead);
}