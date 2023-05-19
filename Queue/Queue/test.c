#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueTest1()
{
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!IsEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		//³ö¶Ó
		QueuePop(&q);
	}
	printf("\n");
	//Ïú»Ù
	QueueDestroy(&q);
}

int main()
{
	QueueTest1();
	return 0;
}