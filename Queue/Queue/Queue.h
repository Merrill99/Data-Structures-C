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

//初始化队列 
void QueueInit(Queue* pq);
//队尾入队（尾插）
void QueuePush(Queue* pq, QDataType x);
//队头出队（头删）
void QueuePop(Queue* pq);
//获取队列头部元素 
QDataType QueueFront(Queue* pq);
//获取队列队尾元素 
QDataType QueueBack(Queue* pq);
//获取队列中有效元素个数 
int QueueSize(Queue* pq);
//判断链表是否为空
bool IsEmpty(Queue* pq);
//销毁队列 
void QueueDestroy(Queue* pq);
