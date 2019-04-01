//找出字符串中第一个只出现一次的字符
//链接：https ://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int IsOne(string s)
{
	char a[256] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		a[s[i] - 'a']++;//记录每个位置的字符出现了几次
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (a[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	string s1;
	while (cin >>s1)
	{
		int i = IsOne(s1);
		if (i == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << s1[i] << endl;
		}
	}
	system("pause");
	return 0;
}
