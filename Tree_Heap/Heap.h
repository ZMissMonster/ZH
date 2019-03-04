#pragma once
#include "common.h"

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;//Êý×é
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* pHeap);
void HeapCreate(Heap* pHeap, HPDataType* a, int n);
void HeapPush(Heap* pHeap, HPDataType x);
void HeapPop(Heap* pHeap);
HPDataType HeapTop(Heap* pHeap);
bool HeapEmpty(Heap* pHeap);
size_t HeapSize(Heap* pHeap);
void HeapDestory(Heap* pHeap);


// ¶ÑÅÅÐò 
void HeapSort(int* a, int n);

void TestHeap();