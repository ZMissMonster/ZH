#include "Heap.h"

void HeapInit(Heap* pHeap)
{
	assert(pHeap);
	pHeap->_a = NULL;
	pHeap->_capacity = pHeap->_size = 0;
}
void HeapCreate(Heap* pHeap, HPDataType* a, int n)
{
	assert(pHeap);
	pHeap->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(pHeap->_a, a, sizeof(HPDataType)*n);

	for (i)

}
void HeapPush(Heap* pHeap, HPDataType x);
void HeapPop(Heap* pHeap);
HPDataType HeapTop(Heap* pHeap);
bool HeapEmpty(Heap* pHeap);
size_t HeapSize(Heap* pHeap);
void HeapDestory(Heap* pHeap);