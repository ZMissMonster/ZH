#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
//�������� :
//����N���ַ�
//������� :
//������ַ�����ת����ַ���


//�ַ�����ת����Ҫ������β�ַ���������β����λ��start��end��ÿ�ν�����β�ַ���Ȼ��start++, end--��ֱ��start��end��������ת���

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