#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/
//�����һ���㷨������������������ļӷ���

//�ӿ�˵��
///*
//�����һ���㷨������������������ļӷ���
//���������
//String addend������
//String augend��������
//����ֵ���ӷ����
//*/
//public String AddLongInteger(String addend, String augend)
//{
//	/*������ʵ�ֹ���*/
//
//
//	return null;
//}
//��������:
//���������ַ�������
//������� :
//�����Ӻ�Ľ����string��
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string ADD(string &s1, string &s2)
{
	//�ӷ������ɵ�λ���λ���㣬Ҳ�����ַ����ĺ�߿�ʼ��ǰ��
	int i = s1.size() - 1;
	int j = s2.size() - 1;
	string sum = "";//������Ž�������ʱֱ��Ϊ�ַ���
	int result = 0;//��ǰλ����ӽ��
	while(i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			result += s1[i] - '0';//�ַ�ת��Ϊ����
		}
		if (j >= 0)
		{
			result += s2[j] - '0';
		}
		//����Ҫ��λ
		sum += (char)(result % 10 + '0');//����ת��Ϊ�ַ�
		//��Ҫ��λ
		result /= 10;//�������ǰ��λ����
		i--;
		j--;
	}
	//�����������н�λ������ǰ��λ
	if (result == 1)
	{
		sum += '1';
	}
	//������ÿһλ�����������ַ����sum������sum���õ��ַ���
	reverse(sum.begin(),sum.end());
	return sum;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << ADD(str1, str2) << endl;
	}
	return 0;
}