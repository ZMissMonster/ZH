#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db
//��Դ��ţ����
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
//�������� :
//	 ����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
// ������� :
//���������������к�����ֵ��
//ʾ��1
//����
//3 - 1 2 1
//���
//3
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int a[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int sum = 0, max = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += a[i];
//		if (sum>max)
//		{
//			max = sum;
//		}
//		if (sum < 0)
//		{
//			sum = 0;
//		}
//	}
//	cout << max << endl;
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include <stdlib.h>
int main()
{
	char a = 0, ch;
	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a' &&ch <= 'z'))
			ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	} 
	printf("\n");
	system("pause");
	return 0;
}