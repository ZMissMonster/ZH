#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//��Ŀ����
//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//��������:
//����һ���ǿ��ַ���
//������� :
//�����һ��ֻ����һ�ε��ַ��������������� - 1

//��ϣ��¼��Ƶ����һ�������ÿһ��λ�ñ�ʾ�ַ���Ӧ��λ�á���Ӧ���ַ�λ�ô���ַ����ֵĴ�����ͳ����֮�󣬱��������ַ���������һ��ֻ����һ�ε��ַ���ֹͣ
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int flag = 1;//��¼��û���ҵ�
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