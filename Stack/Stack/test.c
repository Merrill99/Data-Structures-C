#define _CRT_SECURE_NO_WARNINGS 1

#include"stcak.h"

void StackTest1(char* s)
{
	Stack st;
	STIniti(&st);

    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);
    STPush(&st, 4);

	while (!IsEmpty(&st))
	{
		//��ӡջ��Ԫ��
		printf("%d ", STTop(&st));
		//��ջ
		STPop(&st);
	}
	printf("\n");
}

bool isValid(char* s) {
    //����ջ
    Stack st;
    STIniti(&st);

    while (*s)
    {
        //������������ջ
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);
            ++s;
        }
        //���������ţ������ų�ջ�Ƚ�
        else
        {
            if (IsEmpty(&st))
                return false;
            char top = STTop(&st);
            //��ջ
            STPop(&st);
            //��ͬ������false
            if (*s == ')' && top != '(' ||
                *s == ']' && top != '[' ||
                *s == '}' && top != '{')
                return false;
        }
    }
    if (!IsEmpty(&st))
        return false;

    return true;

    STDestroy(&st);
}

int main()
{
	char s[] = "()";
	StackTest1(s);
    //isValid(s);
	return 0;
}