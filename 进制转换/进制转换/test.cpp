#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//题目描述
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//输入描述 :
//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//输出描述 :
//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	/*string str,table = "0123456789ABCDEF";
	int m, N;
	cin >> m >> N;
	while (m)
	{
	if (m < 0)
	{
	m = -m;
	cout << "-";
	}
	str += table[m%N];
	m /= N;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;*/
	system("pause");
	return 0;
}