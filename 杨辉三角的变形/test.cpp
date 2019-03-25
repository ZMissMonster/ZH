

//杨辉三角的变形
//链接：https ://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
//#include <iostream>
//using namespace std;
//int member(int n,int k)
//{
//	if (k == 1 || k == n * 2 - 1)
//		return 1;
//	if (k<1 || k>n * 2 - 1)
//		return 0;
//	else
//		return member(n - 1, k - 2) + member(n - 1, k - 1) + member(n - 1, k);
//}
//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		for (int i = 1; i <= 2 * N - 1; i++)
//		{
//			if (member(N, i) % 2 == 0)
//			{
//				cout << i << endl;
//				break;
//			}
//			else if (i == 2 * N - 1)
//				cout << "-1" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//超长正整数相加
//链接：https ://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string addstring(string n1, string n2)
{
	int i = n1.size() - 1;
	int j = n2.size() - 1;
	string result = "";
	int sum = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		result += (char)(sum % 10 + '0');
		sum /= 10;
		i--; 
		j--;
	}
	if (sum == 1)
		result += '1';
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addstring(s1, s2) << endl;
	}
	system("pause");
	return 0;
}