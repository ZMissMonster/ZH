#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//题目描述
//查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
//输入描述 :
//输入两个字符串
//输出描述 :
//返回重复出现的字符
//示例1
//输入
//复制
//abcdefghijklmnop
//abcsafjklmnopqrstuvw
//输出
//复制
//jklmnop
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string ls, ss;
	while (cin >> ls>> ss)
	{
		//以最短的字符串作为s1
		if (ls.size() > ss.size())
			swap(ls, ss);
		int len1 = ls.size(), len2 =ss.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (ls[i - 1] == ss[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//如果有更长的公共子串，更新长度
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//以i结尾的最大长度为max, 则子串的起始位置为i - max
				start = i - max;
			}
		}
		cout <<ls.substr(start, max) << endl;
	} 
	return 0;
}