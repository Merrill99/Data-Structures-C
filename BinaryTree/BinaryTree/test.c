#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

void BTTest1()
{
	BTNode* node = CreateBinary();

	PreOrder(node);
	printf("\n");
	InOrder(node);
	printf("\n");
	PostOrder(node);
	printf("\n");
}

int main()
{
	BTTest1();
	return 0;
}