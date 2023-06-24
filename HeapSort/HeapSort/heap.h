#pragma once

//头文件
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int capacity;//容量
	int size;//数据个数
}Heap;

//初始化
void HeapIniti(Heap* php);
//插入元素
void HeapPush(Heap* php, HPDataType value);
//向上调整算法(从孩子节点开始调整)
void AdjustUp(HPDataType* a, int child);
//堆的删除
void HeapPop(Heap* php);
//向下调整算法(从父节点开始调整)
void AdjustDown(HPDataType* a, int n, int parent);
//取堆顶的元素
HPDataType HeapTop(Heap* php);
//判空
bool HeapEmpty(Heap* php);
//销毁
void HeapDeastory(Heap* php);
//堆的长度
int HeapSize(Heap* php);
//交换
void HeapSwap(HPDataType* p1, HPDataType* p2);