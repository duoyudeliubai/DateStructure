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
 typedef  Stack mystack;   //命名mystack为Stack

void InitStack(Stack *p);  //初始化栈
bool IsFull(Stack *p);     //判断栈是否为满
bool IsEmpty(Stack *p);    //判断栈是否为空
void Get_top(Stack *p);    //获得栈顶元素
void push(Stack *p, ElemType i); //压栈操作
void pop(Stack *p);             //出栈操作
