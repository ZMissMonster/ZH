#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482
//��Դ��ţ����
//nowcoderҪ�����ѽ���һЩ���е���Ϣ���������ĵ绰����ȡ������Ҫ����Щ������Ϣ���л����������������м����һЩ����ķ��ţ�������������һ�����롣
//���������æ����һ����򣬽�����nowcoder�Ƕ����յ�����Ϣ����ȡ���м����õ���Ϣ

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