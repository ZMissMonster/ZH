#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())//×Ö·û´®Îª¿Õ£¬·µ»Ø0
		{
			return 0;
		}
		int flag = 1;
		if (str[0] == '-')//¸ººÅ
		{
			flag = -1;
			str[0] = '0';
		}
		if (str[0] == '+')//¸ººÅ
		{
			flag = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return flag*sum;
	}
};