#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/f0db4c36573d459cae44ac90b90c6212
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
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
		while ((ret = str1.find(str2[i])) != -1)//ֱ����str1�в���str2��ÿһ���ַ���find�Ҳ�������-1���ҵ������ظ�λ�ã����ԣ�������صĲ���-1��˵���ַ�һ����ɾ����λ�õ��ַ�����
		{
			str1.erase(ret,1);
		}
	}	
	cout << str1 << endl;
	system("pause");
	return 0;
}