#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
#include <iostream>
#include <string>
using namespace std;
bool hw(string str)
{
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] != str[length - 1])
		{
			return false;
		}
		length = length - 1;
	}
	return true;
}
int main()
{
	string s1, s2;
	string tmp;//����жϣ��ȱ����ַ���
	int count = 0, length = 0;
	while (cin >> s1 >> s2)
	{
		length = s1.length();
		tmp = s1;
		for (int i = 0; i <= length; i++)
		{
			s1 = tmp;
			s1.insert(i, s2);//�ڸ�λ�ò���ʱ���ж��Ƿ����
			if (hw(s1))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	system("pause");	
	return 0;
}
