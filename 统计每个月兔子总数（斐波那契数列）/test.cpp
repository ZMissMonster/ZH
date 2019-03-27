//统计每个月兔子的总数
//链接：https ://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << f(n) << endl;
	}
	system("pause");
	return 0;
}