#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
//输入描述 :
//输入N个字符
//输出描述 :
//输出该字符串反转后的字符串


//字符串反转，需要交换首尾字符，设置首尾两个位置start，end，每次交换首尾字符，然后start++, end--，直到start，end相遇，反转完成

#include <iostream>
#include <string>
using namespace std;
string RS(string s)
{
	if (s.empty())
		return s;
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		swap(s[begin], s[end]);
		begin ++;
		end--;
	}
	return s;
}
int main()
{
	string str1;
	while (getline(cin, str1))
	{
		cout << RS(str1) << endl;
	}
	return 0;
}