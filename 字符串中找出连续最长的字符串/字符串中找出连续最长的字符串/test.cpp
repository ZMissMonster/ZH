#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/bd891093881d4ddf9e56e7cc8416562d
//����һ���ַ���str������ַ���str�е�����������ִ�
//�����������1������������һ���ַ���str�����Ȳ�����255��
//�������:
//��һ�������str��������������ִ���
#include <iostream>
#include <string>
using namespace std;

//�����Ƚϳ���
int main()
{
	string s;
	string maxs, tmps;
	cin >> s;
	for (int i = 0; i <= s.length(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')//�ȿ������ַ�������������ִ���ת���tmps
		{
			tmps += s[i];
		}
		else//���ִ�����,��maxs�Ƚ�
		{
			if (maxs.size() < tmps.size())
			{
				maxs = tmps;//���tmps�����Ǿ͸���maxs�����������Ҹ�����
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