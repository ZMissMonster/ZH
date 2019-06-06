#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//一、密码长度 :
//5 分 : 小于等于4 个字符
//10 分 : 5 到7 字符
//25 分 : 大于等于8 个字符
//二、字母 :
//0 分 : 没有字母
//10 分 : 全都是小（大）写字母
//20 分 : 大小写混合字母
//三、数字 :
//0 分 : 没有数字
//10 分 : 1 个数字
//20 分 : 大于1 个数字
//四、符号 :
//0 分 : 没有符号
//10 分 : 1 个符号
//25 分 : 大于1 个符号
//五、奖励 :
//2 分 : 字母和数字
//3 分 : 字母、数字和符号
//5 分 : 大小写字母、数字和符号
//最后的评分标准 :
//>= 90 : 非常安全
//>= 80 : 安全（Secure）
//>= 70 : 非常强
//>= 60 : 强（Strong）
//>= 50 : 一般（Average）
//>= 25 : 弱（Weak）
//>= 0 : 非常弱
//对应输出为：
//VERY_WEAK,
//WEAK,
//AVERAGE,
//STRONG,
//VERY_STRONG,
//SECURE,
//VERY_SECURE
//请根据输入的密码字符串，进行安全评定。
#include <iostream>
#include <string>
using namespace std;

int SumChar(string str, int len)//字母得分
{
	//可以根据ASCII码判断大小然后计算
	int small = 0;
	int big = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)//大写字母
		{
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122)//小写字母
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
int SumNumber(string str, int len)//数字得分
{
	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
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

int SumSign(string str, int len)//符号得分
{
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		//除去字母，数字，其它都为符号
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
		//长度得分
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
		sum2 = SumChar(str, len);//字母得分
		sum3 = SumNumber(str, len);//数字得分
		sum4 = SumSign(str, len);//符号得分
		//奖励分数
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
		//根据分数判定等级
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
