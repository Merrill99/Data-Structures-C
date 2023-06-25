#define _CRT_SECURE_NO_WARNINGS 1

//头文件
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
// 二叉树前序遍历
void PreOrder(BTNode* root);
// 二叉树中序遍历
void InOrder(BTNode* root);
// 二叉树后序遍历
void PostOrder(BTNode* root);