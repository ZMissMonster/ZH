#define _CRT_SECURE_NO_WARNINGS 1
//
//���ӣ�https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
//��Դ��ţ����
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//�����м��Ǹ����ǳ���������
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
		{
			return 0;
		}
		sort(numbers.begin(), numbers.end());//����ȡ�м���
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