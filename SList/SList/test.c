#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListTest1()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);
	SLPushBack(&plist, 0);
	SLPushBack(&plist, -1);

	SLPrint(plist);
}

void SListTest2()
{
	SLTNode* plist = NULL;

	SLPushBack(&plist, 0);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);

	SLPrint(plist);
}

void SListTest3()
{ 
	SLTNode* plist = NULL;

	SLPushBack(&plist, 0);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);

	SLPopFront(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	
	
	SLPrint(plist);
}

void SListTest4()
{
	SLTNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);
	SLPopBack(&plist);
	SLTNode* pos = SLFind(plist, 1);
	SLInsertBefore(&plist, pos, 99);

	SLPrint(plist);

}

void SListTest5()
{
	SLTNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTNode* pos = SLFind(plist, 4);
	SLInsertAfter(pos, 5);
	SLEarse(&plist, pos);
	SLTNode* pos2 = SLFind(plist, 1);
	SLEarseAfter(pos2);

	SLPrint(plist);
	
}

int main()
{
	SListTest1();
	SListTest2();
	SListTest3();
	SListTest4();
	SListTest5();
	return 0;
}