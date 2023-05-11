#pragma once

//ͷ�ļ��İ���
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

//��ͷ˫��ѭ������ӿ�
//�����½ڵ�
ListNode* BuyListNode(LTDataType x);
//��ʼ�����������ڱ�λ�ڵ�
ListNode* IntiList();
//��ӡ
void LTPrint(ListNode* phead);
//β��
void LTPushBack(ListNode* phead, LTDataType x);
//ͷ��
void LTPushFront(ListNode* phead, LTDataType x);
//�п�
bool IsEmpty(ListNode* phead);
//βɾ
void LTPopBack(ListNode* phead);
//ͷɾ
void LTPopFront(ListNode* phead);
//����
ListNode* LTFind(ListNode* phead, LTDataType x);
//��posλ��ǰ����
void LTInsert(ListNode* pos, LTDataType x);
//ɾ��posλ��
void LTEarse(ListNode* pos);
//���٣���Ҫ�ֶ��ÿգ���free�÷�����
void LTDestroy(ListNode* phead);