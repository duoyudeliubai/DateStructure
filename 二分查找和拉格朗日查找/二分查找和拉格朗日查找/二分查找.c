#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 20428
void binarysearch(int array[N], int num);
void lagrangesearch(int array[N], int num);
void main()
{
	int array[N];
	int num = 0;
	array[0] = 1;
	for (int i = 1; i < N; i++)
	{
		array[i] = array[i - 1] + 2;		
	}
	for (int j = 0; j < N; j++)
	{
		printf(" %d  ", array[j]);
	}
	
	printf("\n请输入要查的整数：\n");
	while ((scanf("%d", &num))!=0)
	{
		/*scanf("%d", &num);*/
		/*search( array[N],num);*///数组 取得是首地址  传递array[N]  会产生错误
		lagrangesearch(array, num);
		
		printf("\n请输入下一个要查的整数（按q退出）：\n");
	}
	
	system("pause");
}
//二分查找法
void binarysearch(int array[N], int num)
{
	bool NoFind =true;//没有找到  true
	int front = 0;
	int rear = N - 1;
	int mid = 0;
	int count = 0;//计算器  记下查找的次数

	/*int mid = ( front + rear )/ 2; */
	while (rear>=front)
	{
		count++;
		/*mid = (front + rear) / 2;*/
		mid = front + (rear - front) * 1 / 2;
		if (array[mid] == num)
		{
			/*printf("%d\n", array[mid]);*/

			NoFind = false;
			printf("发现目标:");
			printf("a[%d]的值是%d 查找了%d次", mid, array[mid],count);
			break;
		}
		else if (num<array[mid])
		{
			rear = mid - 1;
		}
		else
		{
			front = mid + 1;
		}
		
	}
	if (NoFind)
	{
		printf("没有发现目标！");
	}
}
//拉格朗日查找法
void lagrangesearch(int array[N], int num)
{
	bool Find = false;
	int front = 0;
	int rear = N-1;
	int count = 0;
	int mid = 0;
	while (rear>=front)
	{
		count++;
		if (num>array[rear]||num<array[front])//如果需要查找的关键字num大于最大的数或者小于最小的数 就不需要查找了 会导致后面的系数大于1<(num-array[front])/ (array[rear] - array[front])//
		{
			break;
		}
	/*	mid = front + (rear - front) * 1 / 2;*///改变后面的系数
		mid = front + (rear - front)*(num-array[front])/ (array[rear] - array[front]);
		if (num>array[mid])
		{
			front = mid + 1;

		}
		else if (num<array[mid])
		{
			rear = mid - 1;
		}
		else
		{
			printf("发现目标："
				"array[%d]=%d 查找了%d次",mid,array[mid],count);
			Find = true;
			break;
		}

	}
	if (!Find)
	{
		printf("目标丢失了！");
		printf("查找了%d次", count);
	}

}