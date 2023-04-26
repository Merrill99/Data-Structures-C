#pragma once

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
typedef struct SLTNode
{
	SListDataType data;
	struct SLTNode* next;
}SLTNode;


//������Ĵ�ӡ
void SLPrint(SLTNode* phead);
// ��̬����һ���ڵ�
SLTNode* BuySLTNode(SListDataType x);
//�������ͷ��
void SLPushFront(SLTNode** pphead, SListDataType x);
//�������β��
void SLPushBack(SLTNode** pphead, SListDataType x);
//�������ͷɾ
void SLPopFront(SLTNode** pphead);
//�������βɾ
void SLPopBack(SLTNode** pphead);
//������Ĳ���
SLTNode* SLFind(SLTNode* phead, SListDataType x);
//��pos֮ǰ����
void SLInsertBefore(SLTNode** pphead, SLTNode* pos, SListDataType x);
//��pos֮�����
void SLInsertAfter(SLTNode* pos, SListDataType x);
//��pos��ɾ��
void SLEarse(SLTNode** pphead, SLTNode* pos);
//��pos��ɾ�� 
void SLEarseAfter(SLTNode* pos);