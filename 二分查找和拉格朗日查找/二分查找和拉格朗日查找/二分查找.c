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
	
	printf("\n������Ҫ���������\n");
	while ((scanf("%d", &num))!=0)
	{
		/*scanf("%d", &num);*/
		/*search( array[N],num);*///���� ȡ�����׵�ַ  ����array[N]  ���������
		lagrangesearch(array, num);
		
		printf("\n��������һ��Ҫ�����������q�˳�����\n");
	}
	
	system("pause");
}
//���ֲ��ҷ�
void binarysearch(int array[N], int num)
{
	bool NoFind =true;//û���ҵ�  true
	int front = 0;
	int rear = N - 1;
	int mid = 0;
	int count = 0;//������  ���²��ҵĴ���

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
			printf("����Ŀ��:");
			printf("a[%d]��ֵ��%d ������%d��", mid, array[mid],count);
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
		printf("û�з���Ŀ�꣡");
	}
}
//�������ղ��ҷ�
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
		if (num>array[rear]||num<array[front])//�����Ҫ���ҵĹؼ���num��������������С����С���� �Ͳ���Ҫ������ �ᵼ�º����ϵ������1<(num-array[front])/ (array[rear] - array[front])//
		{
			break;
		}
	/*	mid = front + (rear - front) * 1 / 2;*///�ı�����ϵ��
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
			printf("����Ŀ�꣺"
				"array[%d]=%d ������%d��",mid,array[mid],count);
			Find = true;
			break;
		}

	}
	if (!Find)
	{
		printf("Ŀ�궪ʧ�ˣ�");
		printf("������%d��", count);
	}

}