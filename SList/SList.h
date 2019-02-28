#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//单向不带头非循环
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
	SListNode* _tail;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist); 
void SListPushFront(SList* plist, SLTDataType x); 
void SListPopFront(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SList* plist, SListNode* pos, SLTDataType x);
void SListEraseAfter( SListNode* pos);
void SListRemove(SList* plist,SLTDataType x);

void SListPrint(SList* plist);

void TestSList();