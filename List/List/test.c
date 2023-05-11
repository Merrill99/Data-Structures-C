#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void ListTest1()
{
	ListNode* plist = IntiList();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);

	LTPrint(plist);

	LTPushFront(plist, 9);
	LTPushFront(plist, 8);
	LTPushFront(plist, 7);
	LTPushFront(plist, 6);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);

	LTPrint(plist);

}

void ListTest2()
{
	ListNode* plist = IntiList();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);

	LTPrint(plist);
}

void ListTest3()
{
	ListNode* plist = IntiList();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	
	ListNode* pos = LTFind(plist, 3);
	LTInsert(pos, 30);
	LTEarse(pos);
	LTPrint(plist);
	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	ListTest1();
	ListTest2();
	ListTest3();
	return 0;
}