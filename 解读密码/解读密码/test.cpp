#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482
//来源：牛客网
//nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
//现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main(){
	string s;
	while (getline(cin, s))
	{
		int len = s.length();
		for (int i = 0; i < len; i++){
			if (s[i] >= '0'&&s[i] <= '9')
				cout << s[i];
		} 
		cout << endl;
	} 
	return 0;
}