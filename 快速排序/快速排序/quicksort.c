#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
//单线程 快速排序最快  多线程希尔排序
void swap(int* pi,int* pj)
{
	int temp = 0;
	temp=*pi;
	*pi = *pj;
	*pj = temp;
}

void show(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", p[i]);
	}
	printf("\n");
}
//do while 实现快速排序
//void quicksort1(int arr[], int left, int right)
//{
//	int i = left;
//	int j = right+1;
// if (i<j)
//	{
//		do
//		{
//			do{
//				i++;
//			} while (arr[i] <= arr[left] && i <= right);
//
//
//			do
//			{
//				j--;
//			} while (arr[j]>arr[left] && j >= left);
//
//			if (i<j)
//			{
//				swap(&arr[i], &arr[j]);
//			}
//
//			show(arr, SIZE);
//
//		} while (i<j);
//
//		swap(&arr[left], &arr[j]);
//
//		quicksort2(arr, left, j-1);
//		quicksort2(arr, j+1, right);
//		show(arr, SIZE);
//	}
//	
//}

// while 实现快速排序
void quicksort2(int arr[], int left, int right)
{
	int i = 0;
	i = left + 1;
	int j = right;
	if (i < j)
	{
		while (i<j)
		{
			while (arr[i]<=arr[left]&&i<=right)
			{
				i++;
			}
			while (arr[j]>=arr[left]&&j>left)
			{
				j--;
			}
			if (i<j)
			{
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[left], &arr[j]);
		quicksort2(arr, left, j - 1);
		quicksort2(arr, j+1, right);
		
	}


}
void main()
{
	int arr[SIZE] = { 10,9,8,17,6,5,4,3,2,1,0 };
	quicksort2(arr, 0, SIZE-1 );
	show(arr, SIZE);

	system("pause");
}
