#define _CRT_SECURE_NO_WARNINGS 1
//���
//ÿ�δӴ����������Ԫ���У�ѡ����С�����ģ���������е���ʼλ�ã�ֱ��ȫ�������������Ԫ�����ꡣ
//����˼�룺
//�����n��Ԫ����Ҫ�������ȴ�n��Ԫ�����ҵ���С���Ǹ�Ԫ��, �����0��λ���ϵ�Ԫ�ؽ����������Ǹ�Ԫ�������һ��λ���ϵ���������˵��һ�㣬���û�бȵ�0λ���ϵ�Ԫ��С�ľͲ��ý����ˣ����Ҳһ������Ȼ���ٴ�ʣ�µ�n - 1��Ԫ�����ҵ���С��Ԫ�����1��λ���ϵ�Ԫ�ؽ������ҵ�����Ԫ���뵹���ڶ���λ���ϵ���������֮���������ƣ�ֱ������Ԫ�ض�����á�
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