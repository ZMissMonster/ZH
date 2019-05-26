#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
//输入描述:
//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述 :
//依次输出倒置之后的字符串, 以空格分割
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	string s;
	while (cin >> s){//cin遇到空格就结束，所以输入进vector时候用cin，分割单词
		v.push_back(s);
	}
	for (int i = v.size() - 1; i > 0; i--)
		cout << v[i] << " ";//倒着输出
	cout << v[0] << endl;
	return 0;
}