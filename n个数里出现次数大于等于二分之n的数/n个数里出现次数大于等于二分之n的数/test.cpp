#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b?tpId=85&&tqId=29866&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//��������:
//ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��
//������� :
//������ִ������ڵ���n / 2������
//����n��������������ִ������ڵ������鳤��һ�����

//�����������vector�У����򣬳��ִ����������������м��Ǹ�����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	vector <int> v;
	while (cin >> n)
	{
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cout << v[v.size() / 2 - 1] << endl;
	system("pause");
	return 0;
}