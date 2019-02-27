#pragma once//windows vs

#ifndef _SEQLIST_H_//vs+gcc
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
////静态顺序表
//#define N 10
//typedef int SLDateType;
//struct SeqList
//{
//	SLDateType _a[N];//数组
//	size_t _size;//有多少个有效数据
//};
//void SeqListInit(SeqList*psl);//初始化
//void SeqListDestory(SeqList*psl);//销毁
//
//void SeqListPushBack(SeqList*psl, SLDateType x);//尾插
//void SeqListPopBack(SeqList*psl);//头插
//void SeqListPushFront(SeqList*psl, SLDateType x);//尾删
//void SeqListPopFront(SeqList*psl);//头删
//
//void SeqListInsert(SeqList*psl,size_t pos, SLDateType x);//中间插入
//void SeqListErase(SeqList*psl, size_t pos, SLDateType x);//给下标，删除下标处的东西
//void SeqListRemove(SeqList*psl, size_t pos, SLDateType x);//给一个x，删除它

//动态顺序表

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //数组
	size_t _size;
	size_t _capacity;//有多少个有效数据
}SeqList;

void CheckCapacity(SeqList*psl);
void SeqListInit(SeqList* psl,size_t capacity);//初始化
void SeqListDestory(SeqList* psl);//销毁

void SeqListPushBack(SeqList* psl, SLDateType x);//尾插
void SeqListPopBack(SeqList* psl);//头插
void SeqListPushFront(SeqList* psl, SLDateType x);//尾删
void SeqListPopFront(SeqList* psl);//头删

int SeqListFind(SeqList*psl,SLDateType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDateType x);//中间插入
void SeqListErase(SeqList* psl, size_t pos);//给下标，删除下标处的东西
void SeqListRemove(SeqList* psl,SLDateType x);//给一个x，删除它
void SeqListPrint(SeqList* psl);
void SeqListModify(SeqList*psl, size_t pos, SLDateType x);
void TestSeqList();

void SeqListBubbleSort(SeqList*psl);
void SeqListBinaryFind(SeqList*psl, SLDateType x);
void SeqListRemoveAll(SeqList*psl, SLDateType x);

#endif //_SEQLIST_H_