//Fibonacci数列
//链接：https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66
//来源：牛客网
//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a = 0;
	int b = 1;
	int c = 1;
	int n;
	cin >> n;
	while (n>b)//n=6
	{
		a = b;//a=1,b=1,c=2; a=1,b=2,c=3; .....a=5,b=8,c=13;
		b = c;
		c=a+b;
	}
	cout << min((n - a), (b - n)) << endl;//  a<n<b  相减取得最小步数
	system("pause");
	return 0;
}