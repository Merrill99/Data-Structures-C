#define _CRT_SECURE_NO_WARNINGS 1

#include"stcak.h"

void StackTest1()
{
	Stack st;
	STIniti(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	STPush(&st, 6);
	printf("size:%d\n", STSize(&st));

	while (!IsEmpty(&st))
	{
		//´òÓ¡Õ»¶¥ÔªËØ
		printf("%d ", STTop(&st));
		//³öÕ»
		STPop(&st);
	}
	printf("\n");
}

int main()
{
	StackTest1();
	return 0;
}