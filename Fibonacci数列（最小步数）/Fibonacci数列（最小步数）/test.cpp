//Fibonacci����
//���ӣ�https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66
//��Դ��ţ����
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a = 0;
	int b = 1;
	int c = 1;
	int n;
	cin >> n;
	while (n>b)//n=6
	{
		a = b;//a=1,b=1,c=2; a=1,b=2,c=3; .....a=5,b=8,c=13;
		b = c;
		c=a+b;
	}
	cout << min((n - a), (b - n)) << endl;//  a<n<b  ���ȡ����С����
	system("pause");
	return 0;
}