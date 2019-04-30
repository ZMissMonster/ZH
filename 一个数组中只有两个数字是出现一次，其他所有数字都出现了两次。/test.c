#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

void find_diff_num(int *arr, int sz, int* px, int* py)
{
	//1.�����������
	int num = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}

	//2.��num�Ķ�����λ�е�1��λ��
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//3.����posλΪ0����1����
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
		{
			*py ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	find_diff_num(arr, sz, &n1, &n2);
	printf("%d %d", n1, n2);
	system("pause");
	return 0;
}
