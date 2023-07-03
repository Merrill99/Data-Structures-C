#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

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

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	// ���������ߣ���¼���Ƚ������������
	int left = BinaryTreeHeight(root->left);
	int right = BinaryTreeHeight(root->right);
	// ������Ƚ�����ǿ�����+1(+1�൱����һ�㵽�Լ��ĸ߶�)
	return left > right ? left + 1 : right + 1;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;
	// ת��Ϊ�����⣬��k-1��Ľڵ����
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
		return ret2;
	// δ�ҵ�
	return NULL;
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	
	if (root)
		QueuePush(&q, root);

	while (!IsEmpty(&q))
	{
		BTNode* head = QueueFront(&q);

		// ����
		QueuePop(&q);

		printf("%d ", head->data);

		// ����һ�����
		if (head->left)
			QueuePush(&q, head->left);
		if (head->right)
			QueuePush(&q, head->right);
	}
	printf("\n");
	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	//��Ϊ�������
	if (root)
		QueuePush(&q, root);
	while (!IsEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		// ����һ�����
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!IsEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return false;
	}
	return true;
	QueueDestroy(&q);
}