#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

//递归求解
//a. 如果n或者m为1，则只有一行或者一列，从左上角走到右下角的路径数为n + m
//		比如： 1 * 1格子，可以先向下走，再向右走，到达右下角；或者先向右走，再向下走，到达右下角，共两条，即 1 + 1 = 2。
//b.如果n, m都大于1，那么走到[n][m]格子的右下角只有两条路径，
//		<1>: 从[n - 1][m]格子的右下角向下走，到达
//		<2> : 从[n][m - 1]格子的右下角向右走，到达
//		所以走到[n][m]格子的右下角的数量为[n - 1][m] + [n][m - 1], 可以通过递归实现，情况a为递归的终止条件

#include <iostream>
using namespace std;

int Num(int x, int y)
{
	if (x > 1 && y > 1)
	{
		return Num(x, y - 1) + Num(x - 1, y);
	}
	else if ((x >= 1) && (y == 1) || (x == 1) && (y >= 1))
		return x + y;
	else
		return 0;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << Num(a, b) << endl;
	}
	system("pause");
	return 0;
}