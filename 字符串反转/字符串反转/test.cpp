//字符串反转
//链接：https ://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
#include <iostream>
#include <string>
using namespace std;

string ReverseString(string str)
{
	size_t begin = 0;//定义两个指针一前一后遍历
	size_t end=str.size()-1;
	if (str.empty())
		return str;
	while (begin < end)
	{
		swap(str[begin], str[end]);
		begin++;
		end--;
	}
	return str;
}
int main()
{
	string s;
	getline(cin,s);
	cout << ReverseString(s) << endl;
	system("pause");
	return 0;
}