#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
//
//һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
//�������� :
//�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
//������� :
//��Ӧ�����n���м�ֻ����(����û��������������)��

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	} 
	int d;
	while (cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}