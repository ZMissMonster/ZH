//1.求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
#include <iostream>
using namespace std;

class Solution {
class Sum{
public:
		sum()
		{
			sum += i;
			++i;
		}
};
public:
	int Sum_Solution(int n) {
		i = 1;
		sum = 0;
		sum a[n];
		return sum;
	}
private:
	static int sum;
	static int i;
};
int Solution::i = 1;
int Solution::sum = 0;