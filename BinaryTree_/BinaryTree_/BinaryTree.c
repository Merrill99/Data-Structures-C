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
	// 根
	printf("%d ", root->data);
	// 左子树
	PreOrder(root->left);
	// 右子树
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// 左子树
	InOrder(root->left);
	// 根
	printf("%d ", root->data);
	// 右子树
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// 左子树
	PostOrder(root->left);
	// 右子树
	PostOrder(root->right);
	// 根
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

	// 继续向下走，记录并比较两棵树的深度
	int left = BinaryTreeHeight(root->left);
	int right = BinaryTreeHeight(root->right);
	// 返回深度较深的那棵树并+1(+1相当于上一层到自己的高度)
	return left > right ? left + 1 : right + 1;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;
	// 转化为子问题，求k-1层的节点个数
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
	// 未找到
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

		// 出队
		QueuePop(&q);

		printf("%d ", head->data);

		// 带下一层入队
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

	//不为空则入队
	if (root)
		QueuePush(&q, root);
	while (!IsEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		// 带下一层入队
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