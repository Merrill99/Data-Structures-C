#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->front = pq->rear = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	//创建链表，尾插
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//检查空间开辟失败的情况
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->front == NULL)
	{
		assert(pq->rear == NULL);

		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = pq->rear->next;
	}
	
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!IsEmpty(pq));

	//1、仅有一个节点时
	if (pq->front->next == NULL)
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	//2、有多个节点时
	else
	{
		//1、仅有一个节点使用此方法时，会使pq->rear变成野指针
		QNode* next = pq->front->next;
		free(pq->front);
		pq->front = next;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->front->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);

	return pq->rear->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool IsEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL && pq->rear == NULL;
	//return pq->size == 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->size = 0;
}