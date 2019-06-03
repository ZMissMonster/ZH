#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//1. 二进制位异或运算相当于对应位相加，不考虑进位
//		比如： 1 ^ 1 = 0 ---> 1 + 1 = 0 (当前位值为0，进一位)
//		1 ^ 0 = 1 ---> 1 + 0 = 1 (当前位值为1)
//		0 ^ 0 = 0 ---> 0 + 0 = 0 (当前位值为0)
//2. 二进制位与运算相当于对应位相加之后的进位
//		比如： 1 & 1 = 1 ---> 1 + 1 = 0 (当前位的值进一位)
//		1 & 0 = 0 ---> 1 + 0 = 1 (当前位的值不进位)
//		0 & 0 = 0 ---> 0 + 0 = 0 (当前位的值不进位)
//3. 两个数相加：对应二进制位相加的结果 + 进位的结果
//		比如：3 + 2 -- > 0011 + 0010 -- > 0011 ^ 0010 + ((0011 & 0010) << 1)
//		---> (0011 ^ 0010) ^ ((0011 & 0010) << 1)， 当进位之后的结果为0时，相加结束
#include <iostream>
#include <algorithm>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;//进位
		while (B != 0)
		{
			sum = A^B;//对应位求和
			carry = (A&B) << 1;//计算进位
			A = sum;
			B = carry;
		}
		return sum;
	}
};