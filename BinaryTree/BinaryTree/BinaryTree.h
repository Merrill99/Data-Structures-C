#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>

typedef int BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;

BTNode* BuyNode(int x);
BTNode* CreateBinary();
// ������ǰ�����
void PreOrder(BTNode* root);
// �������������
void InOrder(BTNode* root);
// �������������
void PostOrder(BTNode* root);