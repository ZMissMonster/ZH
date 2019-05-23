#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/bd891093881d4ddf9e56e7cc8416562d
//读入一个字符串str，输出字符串str中的连续最长的数字串
//测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述:
//在一行内输出str中里连续最长的数字串。
#include <iostream>
#include <string>
using namespace std;

//遍历比较长度
int main()
{
	string s;
	string maxs, tmps;
	cin >> s;
	for (int i = 0; i <= s.length(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')//先看数字字符串，如果是数字串就转存进tmps
		{
			tmps += s[i];
		}
		else//数字串结束,与maxs比较
		{
			if (maxs.size() < tmps.size())
			{
				maxs = tmps;//如果tmps长，那就更新maxs。否则重新找更长的
			}
			else
			{
				tmps.clear();
			}
		}
	}
	cout << maxs << endl;
	system("pause");
	return 0;
}