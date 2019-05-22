#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/f0db4c36573d459cae44ac90b90c6212
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i < str2.size(); i++)
	{
		int ret;
		while ((ret = str1.find(str2[i])) != -1)//直接在str1中查找str2的每一个字符，find找不到返回-1，找到啦返回该位置，所以，如果返回的不是-1则说明字符一样，删除该位置的字符即可
		{
			str1.erase(ret,1);
		}
	}	
	cout << str1 << endl;
	system("pause");
	return 0;
}