#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
//��������:
//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//������� :
//�����������֮����ַ���, �Կո�ָ�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	string s;
	while (cin >> s){//cin�����ո�ͽ��������������vectorʱ����cin���ָ��
		v.push_back(s);
	}
	for (int i = v.size() - 1; i > 0; i--)
		cout << v[i] << " ";//�������
	cout << v[0] << endl;
	return 0;
}