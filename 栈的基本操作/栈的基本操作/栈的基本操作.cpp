#include<stdio.h>  
#include<stdlib.h>  

#include<iostream>
#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ������  
#define STACKINCREMENT  10   //�洢�ռ��������  

typedef struct  Stack
{
	int* Top;
	int* Bottom;
	int  Stacksize;//ջ��ʵ�ʳ���  
	int  size;//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ  
}Stack, *SqStack;

bool CreateStack(SqStack);  //��ʼ�� 
bool Push(SqStack, int);     //ѹջ 
bool IsEmpty(SqStack);     //�ж��Ƿ�� 
int Pop(SqStack);        //��ջ 
void Traverse(SqStack);   //���� 
void Destroy(SqStack);   //���� 
void Clear(SqStack);   //ɾ�� 
int Stacklength(SqStack); // ջ�ĳ��� 
int GetTop(SqStack);  //���ջ��Ԫ�� 

void main()
{
	Stack S; int data=0;
	//����һ���յ�ջ  
	if (CreateStack(&S) == 1)
		printf("Successfully build stack!\n");
	//������ջ������֮��������ջ������  
	Push(&S, 6);
	Push(&S, 25);
	Push(&S, 89);
	Push(&S, 127);
	Push(&S, 888);
	Traverse(&S);

	//ջ�ĳ���  
	printf("Now the length of stack is:%d\n", Stacklength(&S));

	//ȡ��ջ��Ԫ��  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else printf("\nNow the top of stack is:%d\n", GetTop(&S));

	//���г�ջ������֮��������  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else
	{
		printf("pop succeed!the pop data is:%d\n", Pop(&S));
		Traverse(&S);
	}

	//�������ջ�ĳ���  
	printf("Now the length of stack is:%d\n", Stacklength(&S));

	//����ȡ��ջ��Ԫ��  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else printf("\nNow the top of stack is:%d\n", GetTop(&S));

	//���ջ���������պ�ջ�е�����    
	Clear(&S);
	printf("\ndata cleared!\n");
	Traverse(&S);
	system("pause");
}

//����˳��ջ  
bool CreateStack(SqStack S)
{
	(*S).Bottom = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!(*S).Bottom)
	{
		printf("Malloc failed!");
		exit(-1);
	}
	(*S).Top = (*S).Bottom;
	(*S).size = STACK_INIT_SIZE;
	(*S).Stacksize = 0;
	return true;
}

//��ջ  
bool Push(SqStack S, int e)
{
	if ((*S).Top - (*S).Bottom >= (*S).size)//��ջ����׷�Ӵ洢�ռ�  
	{
		(*S).Bottom = (int*)realloc((*S).Bottom, ((*S).size + STACKINCREMENT)*sizeof(int));
		if (!(*S).Bottom)
		{
			printf("Realloc failed!");
			exit(-1);
		}
		(*S).Top = (*S).Bottom + (*S).size;
		(*S).size += STACKINCREMENT;
	}
	*(*S).Top++ = e;
	(*S).Stacksize++;
	return true;
}

//�ж�ջ�Ƿ�Ϊ��ջ  
bool IsEmpty(SqStack S)
{
	if ((*S).Top == (*S).Bottom) return true;
	else return false;
}

//��ջ������ջ�õ���ֵ������e�У����ⶪʧ  
int Pop(SqStack S)
{
	int e;
	if (IsEmpty(S))  printf("\nNow the stack is IsEmpty!");
	e = *--(*S).Top;
	*(*S).Top = 0;
	(*S).Stacksize--;
	return e;
}

//���������ջ������  
void Traverse(SqStack S)
{
	int* p = (*S).Top;
	if (IsEmpty(S)) printf("\nNow the stack is IsEmpty!\n");
	else
	{
		printf("Now datas int the stack are:\n");
		while (p != (*S).Bottom)
		{
			printf("%d", *--p);
			putchar(32);
		}
		printf("\n");
	}
}

//����ջ��ջ���ٴ���  
void Destroy(SqStack S)
{
	free((*S).Bottom);
	(*S).Top = NULL;
	(*S).Bottom = NULL;
	(*S).Stacksize = (*S).size = 0;
}

//���ջ����ջ��Ϊ��ջ  
void Clear(SqStack S)
{
	if (IsEmpty(S)) printf("\nNow the stack is IsEmpty!");
	else  Destroy(S);
}

//ջ�ĳ��ȣ���ջ��Ԫ�ظ���  
int Stacklength(SqStack S)
{
	return (*S).Stacksize;
}

//ȡջ��Ԫ��  
int GetTop(SqStack S)
{
	int e;
	if (IsEmpty(S)) printf("\nNow the stack is IsEmpty!");
	e = *((*S).Top - 1);
	return e;
}
