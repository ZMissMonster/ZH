#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
//��Դ��ţ����
//
//������������ n �� m��������1��2��3.......n ������ȡ������, ʹ��͵��� m, Ҫ���������еĿ�������г���
//�������� :
//ÿ�������������2������, n��m
//������� :
//��ÿ����ϵ��ֵ����������, ÿ�����һ�����
#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	// m == 0 Ϊ�ݹ��������. ��ʱ v �п����Ѿ����������ɸ�Ԫ����. ���� v �е����ݾ���һ����.
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			// ��� ? : ֻ��Ϊ���ý���ĸ�ʽ�ܹ���Ҫ��һ��.
			i == 0 ? cout << v[i] : cout << " " << v[i];
		} 
		cout << endl;
	} 
	for(int i = beg; i <= n&&i <= m; i++) {
			// ���¼��д����Ǹ���Ŀ�Ĺؼ�. �����ת��.
			// Ϊ���� i -> n �ж����������Ϊ m, �������ת��Ϊ
			// i + 1 -> n �ж����������Ϊ m - i
			v.push_back(i);
			help(n, m - i, v, i + 1);
			v.pop_back();
		}
} 
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}