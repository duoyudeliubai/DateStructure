#include<stdio.h>  
#include<stdlib.h>  

#include<iostream>
#define STACK_INIT_SIZE 100  //存储空间初始分配量  
#define STACKINCREMENT  10   //存储空间分配增量  

typedef struct  Stack
{
	int* Top;
	int* Bottom;
	int  Stacksize;//栈的实际长度  
	int  size;//当前已分配的存储空间，以元素为单位  
}Stack, *SqStack;

bool CreateStack(SqStack);  //初始化 
bool Push(SqStack, int);     //压栈 
bool IsEmpty(SqStack);     //判断是否空 
int Pop(SqStack);        //出栈 
void Traverse(SqStack);   //遍历 
void Destroy(SqStack);   //销毁 
void Clear(SqStack);   //删除 
int Stacklength(SqStack); // 栈的长度 
int GetTop(SqStack);  //获得栈顶元素 

void main()
{
	Stack S; int data=0;
	//创建一个空的栈  
	if (CreateStack(&S) == 1)
		printf("Successfully build stack!\n");
	//进行入栈操作，之后遍历输出栈内数据  
	Push(&S, 6);
	Push(&S, 25);
	Push(&S, 89);
	Push(&S, 127);
	Push(&S, 888);
	Traverse(&S);

	//栈的长度  
	printf("Now the length of stack is:%d\n", Stacklength(&S));

	//取出栈顶元素  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else printf("\nNow the top of stack is:%d\n", GetTop(&S));

	//进行出栈操作，之后遍历输出  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else
	{
		printf("pop succeed!the pop data is:%d\n", Pop(&S));
		Traverse(&S);
	}

	//重新输出栈的长度  
	printf("Now the length of stack is:%d\n", Stacklength(&S));

	//重新取出栈顶元素  
	if (IsEmpty(&S))
		printf("\nNow the stack is IsEmpty!");
	else printf("\nNow the top of stack is:%d\n", GetTop(&S));

	//清空栈，并输出清空后栈中的数据    
	Clear(&S);
	printf("\ndata cleared!\n");
	Traverse(&S);
	system("pause");
}

//建立顺序栈  
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

//进栈  
bool Push(SqStack S, int e)
{
	if ((*S).Top - (*S).Bottom >= (*S).size)//若栈满，追加存储空间  
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

//判断栈是否为空栈  
bool IsEmpty(SqStack S)
{
	if ((*S).Top == (*S).Bottom) return true;
	else return false;
}

//出栈，将出栈得到的值保存在e中，避免丢失  
int Pop(SqStack S)
{
	int e;
	if (IsEmpty(S))  printf("\nNow the stack is IsEmpty!");
	e = *--(*S).Top;
	*(*S).Top = 0;
	(*S).Stacksize--;
	return e;
}

//遍历并输出栈内数据  
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

//销毁栈，栈不再存在  
void Destroy(SqStack S)
{
	free((*S).Bottom);
	(*S).Top = NULL;
	(*S).Bottom = NULL;
	(*S).Stacksize = (*S).size = 0;
}

//清空栈，把栈置为空栈  
void Clear(SqStack S)
{
	if (IsEmpty(S)) printf("\nNow the stack is IsEmpty!");
	else  Destroy(S);
}

//栈的长度，即栈内元素个数  
int Stacklength(SqStack S)
{
	return (*S).Stacksize;
}

//取栈顶元素  
int GetTop(SqStack S)
{
	int e;
	if (IsEmpty(S)) printf("\nNow the stack is IsEmpty!");
	e = *((*S).Top - 1);
	return e;
}
