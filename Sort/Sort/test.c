#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsertTestSort()
{
	//int a[] = { 2,3,1,4,5,6,8,9,7 };
	int a[] = { 9,8,6,7,1,2,3,4,5 };

	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

	/*ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));*/

	
}

void BubbleSortTest()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	PrintArray(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

void HeapSortTest()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	PrintArray(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

void QuickSortTest()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	int n = sizeof(a) / sizeof(a[0]);
	PrintArray(a, n);
	QuickSortNonR(a, 0, n - 1);
	PrintArray(a, n);

}

void MergeSortTest()
{
	//int a[] = { 6,1,2,7,3,4,5,8 };
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	int n = sizeof(a) / sizeof(a[0]);
	PrintArray(a, n);
	MergeSort(a, n);
	PrintArray(a, n);
}

void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSortNonR(a4, 0, N - 1);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	//InsertTestSort();
	//BubbleSortTest();
	//HeapSortTest();
	//QuickSortTest();
	MergeSortTest();
	//TestOP();

	return 0;
}