//分解因数
//链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an, 并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
//输入描述 :
//输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
//输出描述 :
//对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " " << '=';
		for (int i = 2; i <= sqrt(n); ++i)
		{
			while (n%i == 0 && n != i)
			{
				cout << " " << i << " " << '*';
				n = n / i;
			}
		}
		cout << " " << n << endl;
	}
	system("pause");
	return 0;
}