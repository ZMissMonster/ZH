#define _CRT_SECURE_NO_WARNINGS 1
//hoare版本：定义一个key值左右指针begin和end，key一般选择最左或者最右边的值，begin从左往右走找比key值大的，找到就停，end从右往左走找比key小的，找到就停，然后交换begin和end所指向的值，然后继续寻找交换，直到begin和end相遇，此时交换begin与key的值，将key值放在中间，此时比key值小的都在他的左边，比key值大的都在他的右边，此时一趟排序完成。然后对左右两个区间进行递归的排序，直至所有的有序。
#include <stdio.h>
#include <stdlib.h>


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int PartSort(int *a, int begin, int end)
{
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		//end从右边走，找到比key小的即停
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		//begin从左边走，找到比key大的就停止
		while (begin < end&&a[begin] <= key)
		{
			begin++;
		}
		//begin和end相遇，交换begin和start
		Swap(&a[begin], &a[start]);
		return begin;
	}
}
void QiuckSort(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div=PartSort(a, left, right);
	//以div为基准的左边区间去找新的key
	//左边区间：[left,div-1]
	QiuckSort(a, left, div - 1);
	//在以div为基准的右边区间去找新的key
	//右边区间:[div+1,right]
	QuickSort(a, div + 1, right);
}
int main()
{
	int a[10] = { 3, 6, 9, 1, 2, 4, 5, 8, 7, 9};
	QiuckSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}