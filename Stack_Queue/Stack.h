#include "common.h"

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//top是最后一个数据的下一个位置
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n);
void StackDestory(Stack* ps);
void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);//空0 非空1

void StackTest();



