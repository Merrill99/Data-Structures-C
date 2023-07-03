#pragma once

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;

BTNode* BuyNode(int x);
BTNode* CreateBinary1();
BTNode* CreateBinary2();
// ������ǰ�����
void PreOrder(BTNode* root);
// �������������
void InOrder(BTNode* root);
// �������������
void PostOrder(BTNode* root);
// �������Ľڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// �����������
int BinaryTreeHeight(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);