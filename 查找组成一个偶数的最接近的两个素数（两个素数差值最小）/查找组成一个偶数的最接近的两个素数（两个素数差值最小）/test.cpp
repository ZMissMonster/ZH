#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
//输入描述:
//输入一个偶数
//
//输出描述 :
//输出两个素数
#include <iostream>
#include <algorithm>
using namespace std;

bool IsPrNumber(int num)
{
	int tmp = sqrt(num);
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
	for (int i = 2; i <= tmp; i++)
	{
		if (num%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	int i = 0;
	while (cin >> n)
	{
		int half = n / 2; //从中间开始向两边找的话差值最小
		for ( i = half; i > 0; i--)
		{
			if (IsPrNumber(i) && IsPrNumber(n - i))
				break;
		}
		cout << i << endl;
		cout << n - i << endl;
	}
	system("pause");
	return 0;
}