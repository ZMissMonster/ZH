#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
//�������� :
//����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//�ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�
//������� :
//���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector <int> v;
		v.resize(n);
		for (int i = 0; i < n;i++)
		{
			cin >> v[i];
		}
		int num = 1;
		for (int i = 1; i < v.size()-1; i++)
		{//v[i]��ǰһ���󣬱Ⱥ�һ��С�����߱�ǰһ��С�Ⱥ�һ����
			if (v[i - 1]<v[i] && v[i]>v[i + 1]
				|| (v[i - 1] > v[i] && v[i] < v[i + 1]))
			{
				num++;
				if (i != n - 3)//һ������������������Ҫ������������
					i++;
			}
		}
		cout << num << endl;
	}
	system("pause");
	return 0;
}