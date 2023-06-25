#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

void CreateNDate()
{
	// ������
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

	// �����ݷ���minheap��
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//��С��,���µ�������
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(minheap, k, i);
	}

	//��n-k�����ͶѶ������ݽ��бȽ�
	while (!feof(fout))
	{
		int tmp = 0;
		fscanf(fout, "%d", &tmp);
		if (tmp > minheap[0])
			minheap[0] = tmp;
		AdjustDown(minheap, k, 0);
	}

	//��ӡ���ϵ�����
	for (int i = 0; i < k; ++i)
	{
		printf( "%d ", minheap[i]);
	}
	printf("\n");
	fclose(fout);
}

int main()
{
	//����N������
	//CreateNDate();
	PrintTopK(10);
	return 0;
}