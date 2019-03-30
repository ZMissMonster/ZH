//最长公共子串
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	unsigned int start1, start2;
	int count = 0;
	int maxcount = 0;
	for (unsigned int i = 0; i < s1.size(); ++i)
	{
		for (unsigned int j = 0; j < s2.size(); ++j)
		{
			start1 = i;
			start2 = j;
			//abcabcabcdef
			//abcdabcdef
			while (s1[start1] == s2[start2] && start1 < s1.size() && start2 < s2.size())
			{
				start1++;
				start2++;
				count++;
			}
		}
		if (maxcount < count)
		{
			maxcount = count;
		}
		count = 0;
	}
	cout << (s1.size() > s2.size() ? s1.substr(start1, maxcount) : s2.substr(start2, maxcount));
	system("pause");
	return 0;
}

////汽水瓶
//链接：https ://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int number(int n)
//{
//	int count = 0;
//	if (n == 1)
//	{
//		return 0;
//	}
//	else if (n == 2)
//	{
//		return count + 1;
//	}
//	else
//	{
//		count = (n / 3) + number((n / 3) + (n % 3));
//	}
//	return count;
//}
//int main()
//{
//	vector<int> v;
//	int n;
//	int num;
//	while (cin >> n)
//	{
//		if (n == 0)
//			break;
//		v.push_back(n);
//	}
//	for (int i = 0; i < v.size(); ++i)
//	{
//		num = number(v[i]);
//		cout << num << endl;
//	}
//	system("pause");
//	return 0;
//}