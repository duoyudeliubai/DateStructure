#include<stdlib.h>
#include<stdio.h>
#define status int

typedef struct stack{
	status* top;
	status* base;
	int length;
}Stack;