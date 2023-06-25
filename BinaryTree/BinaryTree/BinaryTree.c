#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

BTNode* BuyNode(int x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

BTNode* CreateBinary()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	// ��
	printf("%d ", root->data);
	// ������
	PreOrder(root->left);
	// ������
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	// ������
	InOrder(root->left);
	// ��
	printf("%d ", root->data);
	// ������
	InOrder(root->right);
}

void PostOrder(BTNode* root) 
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// ������
	PostOrder(root->left);
	// ������
	PostOrder(root->right);
	// ��
	printf("%d ", root->data);
}