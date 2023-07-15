#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// ��ӡ
void PrintArray(int* a, int n);
// ����
void Swap(int* p1, int* p2);
// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
// ������
void HeapSort(int* a, int n);
// ����������Ż�������ȡ�з�
int GetMidIndex(int* a, int left, int right);
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// ��������ǵݹ��
void QuickSortNonR(int* a, int left, int right);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);