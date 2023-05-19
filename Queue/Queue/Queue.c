#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->front = pq->rear = NULL;
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
	if (pq->front == NULL)
	{
		pq->front = pq->rear = newnode;
		newnode->next = NULL;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = pq->rear->next;
		newnode->next = NULL;
	}
	//入队
	pq->rear->data = x;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!IsEmpty(pq));

	QNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;
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

	int size = 0;
	while (pq->front != pq->rear)
	{
		pq->front = pq->front->next;
		++size;
	}
	return size;
}

bool IsEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	while (!IsEmpty(pq))
	{
		QNode* next = pq->front->next;
		free(pq->front);
		pq->front = next;
	}
}