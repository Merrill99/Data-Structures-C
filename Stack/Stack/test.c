#define _CRT_SECURE_NO_WARNINGS 1

#include"stcak.h"

void StackTest1(char* s)
{
	Stack st;
	STIniti(&st);

	while (*s)
	{
		//遇见左括号入栈
		if (*s == '(' || *s == '[' || *s == '{')
		{
			STPush(&st, *s);
			++s;
		}
	}
	printf("size:%d\n", STSize(&st));

	while (!IsEmpty(&st))
	{
		//打印栈顶元素
		printf("%c ", STTop(&st));
		//出栈
		STPop(&st);
	}
	printf("\n");
}

bool isValid(char* s) {
    //创建栈
    Stack st;
    STIniti(&st);

    while (*s)
    {
        //遇见左括号入栈
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);
            ++s;
        }
        //遇见右括号，左括号出栈比较
        else
        {
            if (IsEmpty(&st))
                return false;
            char top = STTop(&st);
            //出栈
            STPop(&st);
            //不同，返回false
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
	//StackTest1(s);
    isValid(s);
	return 0;
}