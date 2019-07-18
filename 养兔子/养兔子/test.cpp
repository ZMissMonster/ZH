#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
//
//一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
//输入描述 :
//测试数据包括多组，每组一行，为整数n(1≤n≤90)。
//输出描述 :
//对应输出第n天有几只兔子(假设没有兔子死亡现象)。

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	} 
	int d;
	while (cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}