#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//(1)当底数等于0且指数为负数时，错误；
//(2)当底数任意，指数分为大于等于0，和小于0
//   ①指数 >= 0, 直接求值；
//   ②指数 < 0，先给指数取绝对值，然后按照指数为正求值，最后给结果求倒数
double fun(double bash, unsigned int tmp);//求次幂的值
bool Zero(double bash, double num);//判断底数是否等于0

double Power(double bash, int exponent)
{
	if (Zero(bash,0.0) && (exponent < 0))//当底数等于0且指数为负数时，错误；
	{
		cout<< "error" << endl;
		exit(EXIT_FAILURE);
	}
	unsigned int tmp = (unsigned int)exponent;//tmp用于保存变为正数的次数
	if (exponent < 0)
	{
		tmp = (unsigned int)(-exponent);
	}
	double ret = fun(bash, tmp);//无论次数正负，统一用正次数求结果
	if (exponent < 0)//当次数时小于0的情况，返回结果的倒数
	{
		ret = 1.0 / ret;
	}
	return ret;//当次数时大于或者等于0的情况，直接返回结果
}
double fun(double bash, unsigned int tmp)//求次幂的值
{
	//特殊情况处理
	if (tmp == 0)
	{
		return 1;
	}
	if (tmp == 1)
	{
		return bash;
	}

	//常规公式
	double ret = fun(bash, tmp / 2);//求a^(n/2)
	ret *= ret;//次数为偶数，a^n=a^(n/2)*a^(n/2)
	if (tmp % 2 != 0)//次数为奇数,在偶数的处理上在乘一次底数
	{
		ret = ret*bash;//a^n=a^(n/2)*a^(n/2)*a
	}
	return ret;//返回结果；
}
bool Zero(double bash, double num)//判断底数是否等于0
{
	if ((bash - num > -0.0000001) && (bash - num < 0.0000001))
	{
		return true;
	}
	return false;
}

int main()
{
	//当底数>=0
	cout << Power(2.0, 3) << endl;
	cout << Power(2.0, -3) << endl;
	cout << Power(0.0, 3) << endl;
	//当底数<0
	cout << Power(-2.0, 3) << endl;
	cout << Power(-2.0, -3) << endl;
	//当底数<0&&次数<0
	cout << Power(0, -3) << endl;
	system("pause");
	return 0;
}