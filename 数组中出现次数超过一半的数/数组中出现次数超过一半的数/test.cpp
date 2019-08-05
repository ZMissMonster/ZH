#define _CRT_SECURE_NO_WARNINGS 1
//
//链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
//来源：牛客网
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//排序，中间那个就是超过半数的
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
		{
			return 0;
		}
		sort(numbers.begin(), numbers.end());//排序，取中间数
		int mid = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == mid)
				count++;
		}
		return count>(numbers.size() / 2) ? mid : 0;
	}
};