#define _CRT_SECURE_NO_WARNINGS 1
//概念：
//每次从待排序的数组元素中，选出最小或最大的，存放在序列的起始位置，直到全部待排序的数组元素排完。
//核心思想：
//如果有n个元素需要排序，首先从n个元素中找到最小的那个元素, 并与第0个位置上的元素交换，最大的那个元素与最后一个位置上的数交换（说明一点，如果没有比第0位置上的元素小的就不用交换了，大的也一样）；然后再从剩下的n - 1个元素中找到最小的元素与第1个位置上的元素交换，找到最大的元素与倒数第二个位置上的数交换；之后依次类推，直到所有元素都排序好。
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void SelectSort(int *a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	int min = 0;
	int max = 0;
	int i = 0;
	while (begin < end)
	{
		min = begin;
		max = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] <= a[min])
			{
				min = i;
			}
		}
	}
	if (a[begin] != a[min])
	{
		Swap(&a[begin], &a[min]);
	}
	if (a[begin] == a[max])
	{
		max = min;
	}
	Swap(&a[end], &a[max]);
	begin++;
	end--;
}

int main()
{
	int a[9] = {3, 1, 4, 2, 7, 9, 8, 6, 5};
	SelectSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}