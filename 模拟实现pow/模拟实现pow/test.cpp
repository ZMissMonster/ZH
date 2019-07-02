#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//(1)����������0��ָ��Ϊ����ʱ������
//(2)���������⣬ָ����Ϊ���ڵ���0����С��0
//   ��ָ�� >= 0, ֱ����ֵ��
//   ��ָ�� < 0���ȸ�ָ��ȡ����ֵ��Ȼ����ָ��Ϊ����ֵ�������������
double fun(double bash, unsigned int tmp);//����ݵ�ֵ
bool Zero(double bash, double num);//�жϵ����Ƿ����0

double Power(double bash, int exponent)
{
	if (Zero(bash,0.0) && (exponent < 0))//����������0��ָ��Ϊ����ʱ������
	{
		cout<< "error" << endl;
		exit(EXIT_FAILURE);
	}
	unsigned int tmp = (unsigned int)exponent;//tmp���ڱ����Ϊ�����Ĵ���
	if (exponent < 0)
	{
		tmp = (unsigned int)(-exponent);
	}
	double ret = fun(bash, tmp);//���۴���������ͳһ������������
	if (exponent < 0)//������ʱС��0����������ؽ���ĵ���
	{
		ret = 1.0 / ret;
	}
	return ret;//������ʱ���ڻ��ߵ���0�������ֱ�ӷ��ؽ��
}
double fun(double bash, unsigned int tmp)//����ݵ�ֵ
{
	//�����������
	if (tmp == 0)
	{
		return 1;
	}
	if (tmp == 1)
	{
		return bash;
	}

	//���湫ʽ
	double ret = fun(bash, tmp / 2);//��a^(n/2)
	ret *= ret;//����Ϊż����a^n=a^(n/2)*a^(n/2)
	if (tmp % 2 != 0)//����Ϊ����,��ż���Ĵ������ڳ�һ�ε���
	{
		ret = ret*bash;//a^n=a^(n/2)*a^(n/2)*a
	}
	return ret;//���ؽ����
}
bool Zero(double bash, double num)//�жϵ����Ƿ����0
{
	if ((bash - num > -0.0000001) && (bash - num < 0.0000001))
	{
		return true;
	}
	return false;
}

int main()
{
	//������>=0
	cout << Power(2.0, 3) << endl;
	cout << Power(2.0, -3) << endl;
	cout << Power(0.0, 3) << endl;
	//������<0
	cout << Power(-2.0, 3) << endl;
	cout << Power(-2.0, -3) << endl;
	//������<0&&����<0
	cout << Power(0, -3) << endl;
	system("pause");
	return 0;
}