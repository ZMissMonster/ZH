#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/
//请实现如下接口
//public   static   int  findNumberOf1(int num)
//{
//	/*  请实现  */
//	return  0;
//
//} 譬如：输入5 ，5的二进制为101，输出2
//
//输入描述 :
//输入一个整数
//输出描述 :
//计算整数二进制中1的个数
#include <iostream>
using namespace std;
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