#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//输入: 一个byte型的数字
//输出 : 无
//返回 : 对应的二进制数字中1的最大连续数
//  输入描述 :
//  输入一个byte数字
//  输出描述 :
//  输出转成二进制之后连续1的个数
#include <iostream>
#include <algorithm>
using namespace std;
//根据位运算，获取每一位的二进制值。获取第i位的值：(n >> i) & 1。如果1连续，则计数累加，如果不连
//续，则从0开始计数。
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int maxnum = 0;
		while (n)//右移32次为0,自动跳出循环
		{
			if (n & 1)//获取当前位的bit位
			{
				count++;
				maxnum = max(count, maxnum);
			}
			else//一旦不连续就清零
			{
				count = 0;
			}
			n >>= 1;//右移一位，判断下一位
		}
		cout << maxnum << endl;
	}
	system("pause");
	return 0;
}