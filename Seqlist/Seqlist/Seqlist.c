#include "SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	assert(psl);
	if (capacity == 0)
	{
		psl->_a = NULL;
		psl->_capacity = 0;
		psl->_size = 0;
	}
	else
	{
		psl->_a = (SLDateType*)malloc(sizeof((SLDateType*)capacity));
		psl->_capacity = capacity;
		psl->_size = 0;
		assert(psl->_a);
	}
}
void SeqListDestory(SeqList*psl)//销毁
{
	assert(psl);

	free(psl->_a);
	psl->_a = NULL;
	psl->_size = psl->_capacity = 0;
}
void CheckCapacity(SeqList*psl)
{
	if (psl->_size == psl->_capacity)
	{
		SLDateType* tmp;
		if (psl->_capacity == 0)
		{
			psl->_capacity = 2;
		}
		tmp = realloc(psl->_a, psl->_capacity * 2 * sizeof(SLDateType));
		assert(tmp);
		psl->_a = tmp;
		psl->_capacity *= 2;
	}
}
void SeqListPushBack(SeqList*psl, SLDateType x)//尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->_a[psl->_size] = x;
	psl->_size++;
}
void SeqListPopBack(SeqList*psl)//尾删
{
	assert(psl);
	if (psl->_size>0)
	{
		psl->_size--;
	}

}
void SeqListPushFront(SeqList*psl, SLDateType x)//头插
{
	int end=0;
	assert(psl);
	CheckCapacity(psl);
	end = psl->_size;
	while (end >= 0)
	{
		psl->_a[end + 1] = psl->_a[end];
		--end;
	}
	psl->_a[0] = x;
	psl->_size++;
}
void SeqListPopFront(SeqList*psl)//头删
{
	assert(psl);
	if (psl->_size > 0)
	{
		int start = 0;
		while (start < (int)psl->_size-1)
		{
			psl->_a[start] = psl->_a[start + 1];
			start++;
		}
		psl->_size--;
	}
	
}
void SeqListInsert(SeqList*psl, size_t pos, SLDateType x)//中间插入
{
	int end = 0;
	end=psl->_size - 1;
	assert(psl&&pos<=psl->_size);
	CheckCapacity(psl);
	while (end >= (int)pos)
	{
		psl->_a[end + 1] = psl->_a[end];
		--end;
	}
	psl->_a[pos] = x;
	psl->_size++;
}
void SeqListErase(SeqList*psl, size_t pos)//给下标，删除下标处的东西
{
	assert(psl&&pos<psl->_size);
	int start = 0;
	start = pos;
	while (start < (int)psl->_size - 1)
	{
		psl->_a[start] = psl->_a[start + 1];
		++start;
	}
	--psl->_size;
}
int SeqListFind(SeqList*psl,SLDateType x)
{
	int i = 0;
	assert(psl);
	for (i = 0; i < (int)psl->_size; ++i)
	{
		if (psl->_a[i] == x)
		{
			return i;
		}
	}
	return -1;

}
void SeqListRemove(SeqList*psl,SLDateType x)//给一个x，删除它
{
	int pos = 0;
	assert(psl);
	pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		SeqListErase(psl, pos);
	}
}
void SeqListPrint(SeqList* psl)
{
	size_t i = 0;
	assert(psl);
	for (i = 0; i < psl->_size; ++i)
	{
		printf("%d", psl->_a[i]);
	}
	printf("\n");
}
void SeqListModify(SeqList*psl, size_t pos, SLDateType x)
{
	assert(psl&&pos < psl->_size);
	psl->_a[pos] = x;
}

void SeqListBubbleSort(SeqList*psl);
void SeqListBinaryFind(SeqList*psl, SLDateType x);
void SeqListRemoveAll(SeqList*psl, SLDateType x);

void TestSeqList()
{
	SeqList sl;
	SeqListInit(&sl, 10);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushFront(&sl, 0);
	SeqListInsert(&sl, 2, 6);
	SeqListPrint(&sl);

	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
    //SeqListPopBack(&sl);
	//SeqListPopFront(&sl);
	SeqListRemove(&sl, 3);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}
