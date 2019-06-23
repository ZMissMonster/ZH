#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//题目描述
//找出字符串中第一个只出现一次的字符
//输入描述:
//输入一个非空字符串
//输出描述 :
//输出第一个只出现一次的字符，如果不存在输出 - 1

//哈希记录词频，用一个数组的每一个位置表示字符对应的位置。对应的字符位置存放字符出现的次数。统计完之后，遍历输入字符，遇到第一个只出现一次的字符就停止
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int flag = 1;//记录有没有找到
		int hash[256] = { 0 };
		for (auto& e : str)
		{
			hash[e]++;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (hash[str[i]] == 1)
			{
				flag = 0;
				cout << str[i] << endl;
				break;
			}
		}
		if (flag)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}