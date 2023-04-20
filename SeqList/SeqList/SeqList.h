#pragma once

#define SLDataType int 
//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SeqList
{
	SLDataType* data;//ָ��̬���ٵ�����
	int size;//����ĸ���
	int capacity;//���������Ĵ�С
}SeqList;

//�ӿ�
//˳���ĳ�ʼ��
void SLIniti(SeqList* psl);
//�������,����������������
void CheckCapacity(SeqList* psl);
//˳����β��
void SLPushBack(SeqList* psl, SLDataType x);
//˳����βɾ
void SLPopBack(SeqList* psl);
//˳����ͷ��
void SLPushFront(SeqList* psl, SLDataType x);
//˳����ͷɾ
void SLPopFront(SeqList* psl);
//˳�������λ�õĲ���
void SLInsert(SeqList* psl, int pos, SLDataType x);
//˳�������λ�õ�ɾ��
void SLErase(SeqList* psl, int pos);
//˳���Ĳ��ң������ҵ�Ԫ�ص��±꣬�Ҳ�������-1
int SLFind(SeqList* psl, SLDataType x);
//˳�����޸�
void SLModify(SeqList* psl, int pos, SLDataType x);
//˳���Ĵ�ӡ
void SLPrint(SeqList* psl);
//˳��������
void SLDestory(SeqList* psl);