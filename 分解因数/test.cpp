//�ֽ�����
//���ӣ�https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
//��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an, ���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�
//�������� :
//��������������ݣ�ÿ�����ݰ���һ��������a��2��a��1000000����
//������� :
//��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " " << '=';
		for (int i = 2; i <= sqrt(n); ++i)
		{
			while (n%i == 0 && n != i)
			{
				cout << " " << i << " " << '*';
				n = n / i;
			}
		}
		cout << " " << n << endl;
	}
	system("pause");
	return 0;
}