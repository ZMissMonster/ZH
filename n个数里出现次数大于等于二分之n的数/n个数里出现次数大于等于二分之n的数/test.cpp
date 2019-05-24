#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b?tpId=85&&tqId=29866&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//输入描述:
//每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。
//输出描述 :
//输出出现次数大于等于n / 2的数。
//输入n个整数，输出出现次数大于等于数组长度一半的数

//将数据输入进vector中，排序，出现次数过半则排在最中间那个就是
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	vector <int> v;
	while (cin >> n)
	{
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cout << v[v.size() / 2 - 1] << endl;
	system("pause");
	return 0;
}