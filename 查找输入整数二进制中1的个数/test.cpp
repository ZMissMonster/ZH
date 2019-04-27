#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//让n与1进行按位与运算，如果最低二进制位上是1，则与运算结果为1，count+1；否则为0，count不变；然后运算一次，n右移1位，直到所有二进制位都运算结束，输出count。
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n > 0)
		{
			if (n & 1)
			{
				++count;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}