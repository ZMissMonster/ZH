#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//����: һ��byte�͵�����
//��� : ��
//���� : ��Ӧ�Ķ�����������1�����������
//  �������� :
//  ����һ��byte����
//  ������� :
//  ���ת�ɶ�����֮������1�ĸ���
#include <iostream>
#include <algorithm>
using namespace std;
//����λ���㣬��ȡÿһλ�Ķ�����ֵ����ȡ��iλ��ֵ��(n >> i) & 1�����1������������ۼӣ��������
//�������0��ʼ������
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int maxnum = 0;
		while (n)//����32��Ϊ0,�Զ�����ѭ��
		{
			if (n & 1)//��ȡ��ǰλ��bitλ
			{
				count++;
				maxnum = max(count, maxnum);
			}
			else//һ��������������
			{
				count = 0;
			}
			n >>= 1;//����һλ���ж���һλ
		}
		cout << maxnum << endl;
	}
	system("pause");
	return 0;
}