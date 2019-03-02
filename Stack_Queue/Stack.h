#include "common.h"

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//top�����һ�����ݵ���һ��λ��
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n);
void StackDestory(Stack* ps);
void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);//��0 �ǿ�1

void StackTest();



