#pragma once

//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define LTDataType int

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//带头双向循环链表接口
//创建新节点
ListNode* BuyListNode(LTDataType x);
//初始化，并创建哨兵位节点
ListNode* IntiList();
//打印
void LTPrint(ListNode* phead);
//尾插
void LTPushBack(ListNode* phead, LTDataType x);
//头插
void LTPushFront(ListNode* phead, LTDataType x);
//判空
bool IsEmpty(ListNode* phead);
//尾删
void LTPopBack(ListNode* phead);
//头删
void LTPopFront(ListNode* phead);
//查找
ListNode* LTFind(ListNode* phead, LTDataType x);
//在pos位置前插入
void LTInsert(ListNode* pos, LTDataType x);
//删除pos位置
void LTEarse(ListNode* pos);
//销毁，需要手动置空，和free用法相似
void LTDestroy(ListNode* phead);