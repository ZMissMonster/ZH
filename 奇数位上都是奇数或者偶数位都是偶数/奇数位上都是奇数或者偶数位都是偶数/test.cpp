#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/b89b14a3b5a94e438b518311c5156366

//����һ�����Ȳ�С��2������arr�� дһ����������arr��ʹarr��Ҫô���е�ż��λ�϶���ż����Ҫô���е�����λ�϶��������ϡ� Ҫ��������鳤��ΪN��ʱ�临�Ӷ���ﵽO(N)������ռ临�Ӷ���ﵽO(1), �±�0, 2, 4, 6...����ż��λ, �±�1, 3, 5, 7...��������λ������[1, 2, 3, 4]����Ϊ[2, 1, 4, 3]����
#include <iostream>
#include <vector>

class Solution {
public:
	void oddInOddEvenInEven(std::vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i < len && j < len){
			if ((arr[i] % 2) == 0) { i += 2; continue; }//ż��λ��Ѱ�ҷ�ż��
			if ((arr[j] % 2) != 0) { j += 2; continue; }//����λ��Ѱ�ҷ�����
			swap(arr[i], arr[j]);
		}
	}
};