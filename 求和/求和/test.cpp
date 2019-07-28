#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
//来源：牛客网
//
//输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数, 使其和等于 m, 要求将其中所有的可能组合列出来
//输入描述 :
//每个测试输入包含2个整数, n和m
//输出描述 :
//按每个组合的字典序排列输出, 每行输出一种组合
#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	// m == 0 为递归结束条件. 此时 v 中可能已经包含了若干个元素了. 并且 v 中的内容就是一组结果.
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			// 这个 ? : 只是为了让结果的格式能够和要求一样.
			i == 0 ? cout << v[i] : cout << " " << v[i];
		} 
		cout << endl;
	} 
	for(int i = beg; i <= n&&i <= m; i++) {
			// 以下几行代码是该题目的关键. 问题的转换.
			// 为了求 i -> n 有多少种情况和为 m, 则把问题转换为
			// i + 1 -> n 有多少中情况和为 m - i
			v.push_back(i);
			help(n, m - i, v, i + 1);
			v.pop_back();
		}
} 
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}