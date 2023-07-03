#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

BTNode* CreateBinary1()
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
BTNode* CreateBinary2()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node2->right = node7;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void BTtest1()
{
	BTNode* node1 = CreateBinary1();
	BTNode* node2 = CreateBinary2();

	PreOrder(node1);
	printf("\n");
	InOrder(node1);
	printf("\n");
	PostOrder(node1);
	printf("\n");

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(node1));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(node1));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(node1));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(node1));
	printf("BinaryTreeHeight:%d\n", BinaryTreeHeight(node2));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(node2, 3));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(node2, 4));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(node2, 2));
}

void BTtest2()
{
	BTNode* node1 = CreateBinary1();
	BTNode* node2 = CreateBinary2();

	BinaryTreeLevelOrder(node1);
	printf("%d\n", BinaryTreeComplete(node2));
}

int main()
{

	BTtest1();
	BTtest2();

	return 0;
}