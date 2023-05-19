#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

//��ʼ������ 
void QueueInit(Queue* pq);
//��β��ӣ�β�壩
void QueuePush(Queue* pq, QDataType x);
//��ͷ���ӣ�ͷɾ��
void QueuePop(Queue* pq);
//��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq);
//��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq);
//��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq);
//�ж������Ƿ�Ϊ��
bool IsEmpty(Queue* pq);
//���ٶ��� 
void QueueDestroy(Queue* pq);
