#define _CRT_SECURE_NO_WARNINGS 1
//两种排序方法
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char str[100][100];
int  islex(int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (strcmp(str[i], str[i + 1])>0)
		{
			return -1;
		}
	}
	return 0;
}
int islen(int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (strlen(str[i])>strlen(str[i + 1]))
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}
	if ((islex(n) == 0) && (islen(n) == 0))
	{
		cout << "both" << endl;
	}
	if ((islex(n) == -1) && (islen(n) == 0))
	{
		cout << "lengths" << endl;;
	}
	if ((islex(n) == 0) && (islen(n) == -1))
	{
		cout << "lexicographically" << endl;
	}
	if ((islex(n) == -1) && (islen(n) == -1))
	{
		cout << "none"<<endl;
	}
	system("pause");
	return 0;
}


//最小公倍数
#include <iostream>
using namespace std;

int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x%y);
}
int LCM(int x, int y)
{
	return x*y / GCD(x, y);
}
int main()
{
	int a;
	int b;
	while (cin >> a >> b)
	{
		cout << LCM(a, b) << endl;
	}
	system("pause");
	return 0;
}