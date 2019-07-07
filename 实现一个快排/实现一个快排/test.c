#define _CRT_SECURE_NO_WARNINGS 1
//hoare�汾������һ��keyֵ����ָ��begin��end��keyһ��ѡ������������ұߵ�ֵ��begin�����������ұ�keyֵ��ģ��ҵ���ͣ��end�����������ұ�keyС�ģ��ҵ���ͣ��Ȼ�󽻻�begin��end��ָ���ֵ��Ȼ�����Ѱ�ҽ�����ֱ��begin��end��������ʱ����begin��key��ֵ����keyֵ�����м䣬��ʱ��keyֵС�Ķ���������ߣ���keyֵ��Ķ��������ұߣ���ʱһ��������ɡ�Ȼ�����������������еݹ������ֱ�����е�����
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
		//end���ұ��ߣ��ҵ���keyС�ļ�ͣ
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		//begin������ߣ��ҵ���key��ľ�ֹͣ
		while (begin < end&&a[begin] <= key)
		{
			begin++;
		}
		//begin��end����������begin��start
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
	//��divΪ��׼���������ȥ���µ�key
	//������䣺[left,div-1]
	QiuckSort(a, left, div - 1);
	//����divΪ��׼���ұ�����ȥ���µ�key
	//�ұ�����:[div+1,right]
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