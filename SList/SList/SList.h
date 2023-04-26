#pragma once

//头文件
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
typedef struct SLTNode
{
	SListDataType data;
	struct SLTNode* next;
}SLTNode;


//单链表的打印
void SLPrint(SLTNode* phead);
// 动态申请一个节点
SLTNode* BuySLTNode(SListDataType x);
//单链表的头插
void SLPushFront(SLTNode** pphead, SListDataType x);
//单链表的尾插
void SLPushBack(SLTNode** pphead, SListDataType x);
//单链表的头删
void SLPopFront(SLTNode** pphead);
//单链表的尾删
void SLPopBack(SLTNode** pphead);
//单链表的查找
SLTNode* SLFind(SLTNode* phead, SListDataType x);
//在pos之前插入
void SLInsertBefore(SLTNode** pphead, SLTNode* pos, SListDataType x);
//在pos之后插入
void SLInsertAfter(SLTNode* pos, SListDataType x);
//在pos上删除
void SLEarse(SLTNode** pphead, SLTNode* pos);
//在pos后删除 
void SLEarseAfter(SLTNode* pos);