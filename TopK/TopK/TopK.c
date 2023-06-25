#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	// 将数据放入minheap中
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//建小堆,向下调整建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(minheap, k, i);
	}

	//后n-k个数和堆顶的数据进行比较
	while (!feof(fout))
	{
		int tmp = 0;
		fscanf(fout, "%d", &tmp);
		if (tmp > minheap[0])
			minheap[0] = tmp;
		AdjustDown(minheap, k, 0);
	}

	//打印堆上的数据
	for (int i = 0; i < k; ++i)
	{
		printf( "%d ", minheap[i]);
	}
	printf("\n");
	fclose(fout);
}

int main()
{
	//创建N个数据
	//CreateNDate();
	PrintTopK(10);
	return 0;
}