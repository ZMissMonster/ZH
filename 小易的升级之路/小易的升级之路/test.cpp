#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, ���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����, ��������������n������, ÿ������ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc, ��ô���������ɴ�ܹ���, �� ��ʹ���Լ�������ֵ����bi; ���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.��ô��������, ��һϵ�еĶ�����, С�׵���������ֵΪ���� ?
//�������� :
//	 ����ÿ������, ��һ������������n(1��n < 100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
//	 �ڶ���n������, b1, b2...bn(1��bi��n)��ʾÿ������ķ�����
// ������� :
//����ÿ������, ���һ��.ÿ�н�����һ������, ��ʾС�׵���������ֵ
#include<vector>
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	} 
	return b;
} 
int main()
{
	int n, power;
	vector<int> num;
	while (cin >> n >> power)
	{
		num.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		} 
		for(int k = 0; k < n; k++)
		{
				if (num[k] < power)
				{
					power += num[k];
				} 
				else
				{
					power += GCD(power, num[k]);
				}
			} 
		cout << power << endl;
	} 
	return 0;
}