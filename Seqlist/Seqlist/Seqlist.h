#pragma once//windows vs

#ifndef _SEQLIST_H_//vs+gcc
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
////��̬˳���
//#define N 10
//typedef int SLDateType;
//struct SeqList
//{
//	SLDateType _a[N];//����
//	size_t _size;//�ж��ٸ���Ч����
//};
//void SeqListInit(SeqList*psl);//��ʼ��
//void SeqListDestory(SeqList*psl);//����
//
//void SeqListPushBack(SeqList*psl, SLDateType x);//β��
//void SeqListPopBack(SeqList*psl);//ͷ��
//void SeqListPushFront(SeqList*psl, SLDateType x);//βɾ
//void SeqListPopFront(SeqList*psl);//ͷɾ
//
//void SeqListInsert(SeqList*psl,size_t pos, SLDateType x);//�м����
//void SeqListErase(SeqList*psl, size_t pos, SLDateType x);//���±꣬ɾ���±괦�Ķ���
//void SeqListRemove(SeqList*psl, size_t pos, SLDateType x);//��һ��x��ɾ����

//��̬˳���

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //����
	size_t _size;
	size_t _capacity;//�ж��ٸ���Ч����
}SeqList;

void CheckCapacity(SeqList*psl);
void SeqListInit(SeqList* psl,size_t capacity);//��ʼ��
void SeqListDestory(SeqList* psl);//����

void SeqListPushBack(SeqList* psl, SLDateType x);//β��
void SeqListPopBack(SeqList* psl);//ͷ��
void SeqListPushFront(SeqList* psl, SLDateType x);//βɾ
void SeqListPopFront(SeqList* psl);//ͷɾ

int SeqListFind(SeqList*psl,SLDateType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDateType x);//�м����
void SeqListErase(SeqList* psl, size_t pos);//���±꣬ɾ���±괦�Ķ���
void SeqListRemove(SeqList* psl,SLDateType x);//��һ��x��ɾ����
void SeqListPrint(SeqList* psl);
void SeqListModify(SeqList*psl, size_t pos, SLDateType x);
void TestSeqList();

void SeqListBubbleSort(SeqList*psl);
void SeqListBinaryFind(SeqList*psl, SLDateType x);
void SeqListRemoveAll(SeqList*psl, SLDateType x);

#endif //_SEQLIST_H_