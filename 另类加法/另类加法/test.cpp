#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//1. ������λ��������൱�ڶ�Ӧλ��ӣ������ǽ�λ
//		���磺 1 ^ 1 = 0 ---> 1 + 1 = 0 (��ǰλֵΪ0����һλ)
//		1 ^ 0 = 1 ---> 1 + 0 = 1 (��ǰλֵΪ1)
//		0 ^ 0 = 0 ---> 0 + 0 = 0 (��ǰλֵΪ0)
//2. ������λ�������൱�ڶ�Ӧλ���֮��Ľ�λ
//		���磺 1 & 1 = 1 ---> 1 + 1 = 0 (��ǰλ��ֵ��һλ)
//		1 & 0 = 0 ---> 1 + 0 = 1 (��ǰλ��ֵ����λ)
//		0 & 0 = 0 ---> 0 + 0 = 0 (��ǰλ��ֵ����λ)
//3. ��������ӣ���Ӧ������λ��ӵĽ�� + ��λ�Ľ��
//		���磺3 + 2 -- > 0011 + 0010 -- > 0011 ^ 0010 + ((0011 & 0010) << 1)
//		---> (0011 ^ 0010) ^ ((0011 & 0010) << 1)�� ����λ֮��Ľ��Ϊ0ʱ����ӽ���
#include <iostream>
#include <algorithm>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;//��λ
		while (B != 0)
		{
			sum = A^B;//��Ӧλ���
			carry = (A&B) << 1;//�����λ
			A = sum;
			B = carry;
		}
		return sum;
	}
};