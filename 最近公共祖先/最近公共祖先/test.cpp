#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�
//����������
//2��3
//���أ�1

#include <iostream>
using namespace std;
//1 / \ 2 3 / \ / \ 4 5 6 7 ���������ӽڵ��븸�ڵ�֮��Ĺ�ϵΪroot = child / 2,�������a �� = b���������еĽϴ�������2�� ���ѭ��ֱ��a == b ����ԭ��������������������� ���磺 2��7������������ȣ�7 / 2 = 3 ---> 3 / 2 = 1�� 2 / 2 = 1�� �õ�1Ϊ���ǵĹ�������
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};