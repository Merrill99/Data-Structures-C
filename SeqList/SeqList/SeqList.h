#pragma once

#define SLDataType int 
//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SeqList
{
	SLDataType* data;//指向动态开辟的数组
	int size;//数组的个数
	int capacity;//数组容量的大小
}SeqList;

//接口
//顺序表的初始化
void SLIniti(SeqList* psl);
//检测容量,如果已满则进行增容
void CheckCapacity(SeqList* psl);
//顺序表的尾插
void SLPushBack(SeqList* psl, SLDataType x);
//顺序表的尾删
void SLPopBack(SeqList* psl);
//顺序表的头插
void SLPushFront(SeqList* psl, SLDataType x);
//顺序表的头删
void SLPopFront(SeqList* psl);
//顺序表任意位置的插入
void SLInsert(SeqList* psl, int pos, SLDataType x);
//顺序表任意位置的删除
void SLErase(SeqList* psl, int pos);
//顺序表的查找，返回找到元素的下标，找不到返回-1
int SLFind(SeqList* psl, SLDataType x);
//顺序表的修改
void SLModify(SeqList* psl, int pos, SLDataType x);
//顺序表的打印
void SLPrint(SeqList* psl);
//顺序表的销毁
void SLDestory(SeqList* psl);