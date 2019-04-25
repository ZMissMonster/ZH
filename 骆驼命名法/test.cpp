#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/aed1c7bbc2604e7c9661a2348b0541b8?pos=46&mutiTagIds=579&orderByHotValue=1

//从C / C++转到Java的程序员，一开始最不习惯的就是变量命名方式的改变。C语言风格使用下划线分隔多个单词，例如“hello_world”；而Java则采用一种叫骆驼命名法的规则：除首个单词以外，所有单词的首字母大写，例如“helloWorld”。请你帮可怜的程序员们自动转换变量名。

// 首先一个字符一个字符的读取内容
// 1. 遇到 _ 就直接跳过
// 2. 如果上一个字符是 _ 则下一个字符转为大写字母

#include<iostream>
#include<string>
#include<algorithm>

#define INF 1000000
using namespace std;
int main(int argc, char** argv)
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			// 1. 遇到 _ 就直接跳过
			if (s[i] == '_') continue;
			// 2. 如果上一个字符是 _ 则下一个字符转为大写字母
			if (i > 0 && s[i - 1] == '_') cout << (char)toupper(s[i]);
			else cout << s[i];
		} 
		cout << endl;
	} 
	return 0;
}