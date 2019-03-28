//连续子数组的最大和
//https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int max = array[0];
		for (int i = 1; i < array.size(); ++i)
		{
			sum += array[i];
			if (sum>max)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		return max;
	}
};