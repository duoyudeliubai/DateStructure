#include<stdio.h>
#include<stdlib.h>
void InsertSort1();
void InsertSort2();
void main()
{
	/*InsertSort1();*/
	InsertSort2();

	system("pause");
}

void InsertSort1()
{
	int a[10] = {1,2,3,4,6,7,8,9,10,5};
	int temp = a[9];
	int j = 9;
	
	while (j > 0&&temp<a[j-1])
	{
		a[j] = a[j - 1];
		j--;

		for (int i = 0; i < 10; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	a[j] = temp;

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort2()
{
	int arry[10] = { 10, 9, 3, 5, 4, 8, 7, 6, 2, 32 };
	
	for (int i = 1; i < 10; i++)
	{
		int j = i;
		int temp = arry[i];
		while (j>0&&temp<arry[j-1])
		{
			arry[j] = arry[j - 1];
			j--;
		}
		arry[j]=temp;

		/*for (int i = 0; i < 10; i++)
		{
			printf("%d ", arry[i]);
		}
		printf("\n");*/
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arry[i]);
	}
	printf("\n");

}