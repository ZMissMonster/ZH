#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/
//请设计一个算法完成两个超长正整数的加法。

//接口说明
///*
//请设计一个算法完成两个超长正整数的加法。
//输入参数：
//String addend：加数
//String augend：被加数
//返回值：加法结果
//*/
//public String AddLongInteger(String addend, String augend)
//{
//	/*在这里实现功能*/
//
//
//	return null;
//}
//输入描述:
//输入两个字符串数字
//输出描述 :
//输出相加后的结果，string型
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string ADD(string &s1, string &s2)
{
	//加法运算由低位向高位运算，也就是字符串的后边开始往前加
	int i = s1.size() - 1;
	int j = s2.size() - 1;
	string sum = "";//用来存放结果，输出时直接为字符串
	int result = 0;//当前位置相加结果
	while(i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			result += s1[i] - '0';//字符转化为数字
		}
		if (j >= 0)
		{
			result += s2[j] - '0';
		}
		//不需要进位
		sum += (char)(result % 10 + '0');//数字转化为字符
		//需要进位
		result /= 10;//计算出往前进位多少
		i--;
		j--;
	}
	//相加完如果还有进位，则向前进位
	if (result == 1)
	{
		sum += '1';
	}
	//结束后将每一位计算结果按照字符存进sum，逆置sum，得到字符串
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