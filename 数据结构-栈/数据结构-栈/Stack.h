#include<stdio.h>
#include<stdlib.h>
#incldue<bool.h>
#define ElemType int
#define N 100

 struct mystack {
	//ElemType *base;
	//ElemType *top;
	ElemType a[N];
	int Stacksize;                                                                             
};
 typedef  Stack mystack;   //����mystackΪStack

void InitStack(Stack *p);  //��ʼ��ջ
bool IsFull(Stack *p);     //�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack *p);    //�ж�ջ�Ƿ�Ϊ��
void Get_top(Stack *p);    //���ջ��Ԫ��
void push(Stack *p, ElemType i); //ѹջ����
void pop(Stack *p);             //��ջ����
