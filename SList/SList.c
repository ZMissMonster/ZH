#include "SList.h"


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head=plist->_tail= NULL;
}
void SListDestory(SList* plist)
{
	SListNode* cur;
	SListNode* next;
	assert(plist);
	cur = plist->_head;
	while (cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = plist->_tail = NULL;
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	return node;
}
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_tail == NULL)
	{
		plist->_head = plist->_tail = BuySListNode(x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		plist->_tail->_next = newnode;
		plist->_tail = newnode;
	}
}
void SListPrint(SList* plist)
{
	SListNode* cur = plist->_head;
	while (cur != plist->_tail->_next)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void SListPopBack(SList* plist)
{
	SListNode*prev, *tail;
	assert(plist);
	prev = NULL;
	tail = plist->_head;
	if (tail->_next == NULL)
	{
		free(tail);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode* newnode;
	assert(plist);
	newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}
void SListPopFront(SList* plist)
{
	SListNode* next;
	assert(plist);
	next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
			return cur;

		cur = cur->_next;
	}
	return NULL;
}
void SListInsertAfter(SList* plist, SListNode* pos, SLTDataType x)//在pos后面插入
{
	SListNode* next, *newnode;
	assert(pos);
	next = pos->_next;
	newnode = BuySListNode(x);
	// pos newnode next
	pos->_next = newnode;
	newnode->_next = next;
}
void SListEraseAfter( SListNode* pos)//删除pos后面的
{
	SListNode* next;
	assert(pos);
	if (pos->_next == NULL)
		return;
	next=pos->_next;
	pos->_next = next->_next;
	free(next);
	next = NULL;
}
void SListRemove(SList* plist, SLTDataType x)//删除一个值
{
	assert(plist);
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}
	SListNode* prev=NULL;
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void TestSList()
{
	SList s1;
	SListInit(&s1);
	SListPushBack(&s1,1);
	SListPushBack(&s1,3);
	SListPushBack(&s1,2);
	SListPushBack(&s1,4);
	SListPrint(&s1);
	//SListPopBack(&s1);
	//SListPrint(&s1);
	//SListPushFront(&s1, 6);
	//SListPushFront(&s1, 7);
	//SListPrint(&s1);
	//SListPopFront(&s1);
	//SListPrint(&s1);
	SListNode* pos = SListFind(&s1, 2);
	SListInsertAfter(&s1,pos,5);
	SListPrint(&s1);
	SListEraseAfter(pos);
	SListPrint(&s1);
	SListRemove(&s1, 3);
	SListPrint(&s1);
    //SListDestory(&s1);
	//SListPrint(&s1);



}
