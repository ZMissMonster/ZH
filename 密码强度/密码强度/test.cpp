#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
//һ�����볤�� :
//5 �� : С�ڵ���4 ���ַ�
//10 �� : 5 ��7 �ַ�
//25 �� : ���ڵ���8 ���ַ�
//������ĸ :
//0 �� : û����ĸ
//10 �� : ȫ����С����д��ĸ
//20 �� : ��Сд�����ĸ
//�������� :
//0 �� : û������
//10 �� : 1 ������
//20 �� : ����1 ������
//�ġ����� :
//0 �� : û�з���
//10 �� : 1 ������
//25 �� : ����1 ������
//�塢���� :
//2 �� : ��ĸ������
//3 �� : ��ĸ�����ֺͷ���
//5 �� : ��Сд��ĸ�����ֺͷ���
//�������ֱ�׼ :
//>= 90 : �ǳ���ȫ
//>= 80 : ��ȫ��Secure��
//>= 70 : �ǳ�ǿ
//>= 60 : ǿ��Strong��
//>= 50 : һ�㣨Average��
//>= 25 : ����Weak��
//>= 0 : �ǳ���
//��Ӧ���Ϊ��
//VERY_WEAK,
//WEAK,
//AVERAGE,
//STRONG,
//VERY_STRONG,
//SECURE,
//VERY_SECURE
//���������������ַ��������а�ȫ������
#include <iostream>
#include <string>
using namespace std;

int SumChar(string str, int len)//��ĸ�÷�
{
	//���Ը���ASCII���жϴ�СȻ�����
	int small = 0;
	int big = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)//��д��ĸ
		{
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122)//Сд��ĸ
		{
			small++;
		}
	}
		if ((small + big) == 0)
		{
			return 0;
		}
		else if (small ==len || big == len)
		{
			return 10;
		}
		else if (small > 0 && big > 0)
		{
			return 20;
		}
		return 0;
}
int SumNumber(string str, int len)//���ֵ÷�
{
	//����ASCII���ж����ָ�������ȥ�ַ���0��֮����0~9֮��ļ�Ϊ����
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			num++;
		}
	} 
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 10;
	}
	else
	{
		return 20;
	}
}

int SumSign(string str, int len)//���ŵ÷�
{
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		//��ȥ��ĸ�����֣�������Ϊ����
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	} 
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 10;
	}
	else
	{
		return 25;
	}
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int len = str.size();
		//���ȵ÷�
		if (len <= 4)
		{
			sum1 = 5;
		}
		else if (len >= 8)
		{
			sum1 = 25;
		}
		else
		{
			sum1 = 10;
		}
		sum2 = SumChar(str, len);//��ĸ�÷�
		sum3 = SumNumber(str, len);//���ֵ÷�
		sum4 = SumSign(str, len);//���ŵ÷�
		//��������
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
		{
			sum5 = 2;
		}
		//���ݷ����ж��ȼ�
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	} 
	return 0;
}
