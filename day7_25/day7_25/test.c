#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//
//int Find(int a[3][3], int row, int col,int k)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x<row&&y>=0)
//	{
//		if (a[x][y] < k)
//			x++;
//		else if (a[x][y]>k)
//			y--;
//		else
//			return 1;
//	}
//}
//
//int main()
//{
//	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int k =7;
//	int ret = Find(a,3,3,k);
//	if (ret == 1)
//		printf("找到了\n");
//	else
//		printf("找不到呀\n");
//
//	system("pause");
//	return 0;
//}




//void Movenum(int a[], int sz)
//{
//	int *left = a;
//	int *right = a + sz - 1;
//
//	while (left < right)
//	{
//		while (((left < right) && (*left) % 2 != 0))
//		{
//			left++;
//		}
//		while (((left < right) && (*right) % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp=*left;
//			*left = *right;
//			*right = tmp;
//		}
//	}
//}
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	int i = 0;
//	int sz = (sizeof(a) / sizeof(a[0]));
//	Movenum(a, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//	system("pause");
//	return 0;
//}