#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void bubble_sort(char **a, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (strcmp(a[j], a[j + 1])>0)
			{
				char* tmp = 0;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	char* a[] = { "ssssss", "aaaaa", "bbbbbb" };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", a[i]);
	}
	//ÅÅÐò
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	bubble_sort(a, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", a[i]);
	}
	system("pause");
	return 0;
}
