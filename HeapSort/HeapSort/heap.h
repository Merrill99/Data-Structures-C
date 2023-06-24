#pragma once

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int capacity;//����
	int size;//���ݸ���
}Heap;

//��ʼ��
void HeapIniti(Heap* php);
//����Ԫ��
void HeapPush(Heap* php, HPDataType value);
//���ϵ����㷨(�Ӻ��ӽڵ㿪ʼ����)
void AdjustUp(HPDataType* a, int child);
//�ѵ�ɾ��
void HeapPop(Heap* php);
//���µ����㷨(�Ӹ��ڵ㿪ʼ����)
void AdjustDown(HPDataType* a, int n, int parent);
//ȡ�Ѷ���Ԫ��
HPDataType HeapTop(Heap* php);
//�п�
bool HeapEmpty(Heap* php);
//����
void HeapDeastory(Heap* php);
//�ѵĳ���
int HeapSize(Heap* php);
//����
void HeapSwap(HPDataType* p1, HPDataType* p2);