#include "Sort.h"

void PrintArray(int*a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int *a, int n)
{
	assert(a);
	for (int i = 0; i<n - 1; ++i)
	{
		int end = i;
		int tmp = 0;
		tmp = a[end + 1];
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int *a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int *p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min=begin, max=end;
		for (int i =begin; i < end; i++)
		{
			if (a[i]>a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
		//PrintArray(a, n);

	}
}

void TestSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	//InsertSort(a, sizeof(a) / sizeof (int));
	//ShellSort(a, sizeof(a) / sizeof (int));
	SelectSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof (int));
}

void TestSortOP()
{
	const int n = 100000;
	int *a1 = (int*)malloc(sizeof(int)*n);
	int *a2 = (int*)malloc(sizeof(int)*n);
	int *a3 = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];

	}
	size_t begin1 = clock();
	InsertSort(a1, n);
	size_t end1 = clock();

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();

	size_t begin3 = clock();
	SelectSort(a3, n);
	size_t end3 = clock();

	printf("%u\n", end1 - begin1);
	printf("%u\n", end2 - begin2);
	printf("%u\n", end3 - begin3);

}