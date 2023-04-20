#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListTest1()
{
	SeqList s;
	SLIniti(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);

	SLPrint(&s);

}

void SeqListTest2()
{
	SeqList s;
	SLIniti(&s);
	
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s); 
	SLPrint(&s);


}

void SeqListTest3()
{
	SeqList s;
	SLIniti(&s);

	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);

	SLPrint(&s);

	SLPushBack(&s, 99);
	SLPushFront(&s, 520);

	SLInsert(&s, 2, 1314);
	SLPrint(&s);

	SLErase(&s, 2);
	SLPopBack(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLDestory(&s);

}

void SeqListTest4()
{
	SeqList s;
	SLIniti(&s);

	SLPushFront(&s, 6);
	SLPushFront(&s, 5);
	SLPushFront(&s, 4);
	SLPushFront(&s, 3);
	SLPushFront(&s, 2);
	SLPushFront(&s, 1);

	SLPrint(&s);

	int pos = SLFind(&s, 6);
	printf("找到下标为：%d\n", pos);
	SLModify(&s, 2, 99);
	SLPrint(&s);

}

int main()
{
	//SeqListTest1();
	//SeqListTest2();
	//SeqListTest3();
	SeqListTest4();

	return 0;
}