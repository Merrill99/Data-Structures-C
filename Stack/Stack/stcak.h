#pragma once

//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//ջ��
	int capacity;//����
}Stack;

//ջ�ĳ�ʼ��
void STIniti(Stack* pst);
//ѹջ
void STPush(Stack* pst, STDataType x);
//��ջ
void STPop(Stack* pst);
//�п�
bool IsEmpty(Stack* pst);
//��ȡջ��Ԫ�� 
STDataType STTop(Stack* pst);
// ��ȡջ����ЧԪ�ظ��� 
int STSize(Stack* pst);
//����ջ
void STDestroy(Stack* pst);