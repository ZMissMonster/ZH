#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��n��1���а�λ�����㣬�����Ͷ�����λ����1������������Ϊ1��count+1������Ϊ0��count���䣻Ȼ������һ�Σ�n����1λ��ֱ�����ж�����λ��������������count��
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n > 0)
		{
			if (n & 1)
			{
				++count;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}