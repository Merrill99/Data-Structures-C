#pragma once

//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//栈顶
	int capacity;//容量
}Stack;

//栈的初始化
void STIniti(Stack* pst);
//压栈
void STPush(Stack* pst, STDataType x);
//出栈
void STPop(Stack* pst);
//判空
bool IsEmpty(Stack* pst);
//获取栈顶元素 
STDataType STTop(Stack* pst);
// 获取栈中有效元素个数 
int STSize(Stack* pst);
//销毁栈
void STDestroy(Stack* pst);