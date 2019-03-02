#include "common.h"
typedef int	QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);

void QueuePush(Queue* q, QUDataType x);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QUDataType QueueFront(Queue* q);//ȡ��ͷ������
QUDataType QueueBack(Queue* q); // ȡ��β������

void QueueTest();