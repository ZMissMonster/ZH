#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������
//��������:
//����һ��ż��
//
//������� :
//�����������
#include <iostream>
#include <algorithm>
using namespace std;

bool IsPrNumber(int num)
{
	int tmp = sqrt(num);
	//ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	for (int i = 2; i <= tmp; i++)
	{
		if (num%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	int i = 0;
	while (cin >> n)
	{
		int half = n / 2; //���м俪ʼ�������ҵĻ���ֵ��С
		for ( i = half; i > 0; i--)
		{
			if (IsPrNumber(i) && IsPrNumber(n - i))
				break;
		}
		cout << i << endl;
		cout << n - i << endl;
	}
	system("pause");
	return 0;
}