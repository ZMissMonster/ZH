#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/aed1c7bbc2604e7c9661a2348b0541b8?pos=46&mutiTagIds=579&orderByHotValue=1
//��Դ��ţ����
//��C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
//���������ĳ���Ա���Զ�ת����������
//�������� :
//��������������ݡ�
//ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��
//������� :
//��Ӧÿһ�����ݣ������������Ӧ��������������

//��˼·��
//����һ���ַ�һ���ַ��Ķ�ȡ����
//1. ���� _ ��ֱ������
//2. �����һ���ַ��� _ ����һ���ַ�ת��д��ĸ
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			// 1. ���� _ ��ֱ������
			if (s[i] == '_') continue;
			// 2. �����һ���ַ��� _ ����һ���ַ�תΪ��д��ĸ
			if (i > 0 && s[i - 1] == '_') cout << (char)toupper(s[i]);
			else cout << s[i];
		}
		cout << endl;
	} 
	return 0;
}