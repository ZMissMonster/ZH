#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

//数字的相加可以转换为二进制的加法，注意每一位相加与进位即可
// 两个数异或：相当于每一位相加，而不考虑进位；
//两个数相与，并左移一位：相当于求得进位；
//将上述两步的结果相加

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0){
			int sum = num1 ^ num2;
			int carray = (num1 & num2) << 1;
			num1 = sum;
			num2 = carray;
		}
		return num1;
	}
};