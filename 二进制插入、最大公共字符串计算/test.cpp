#define _CRT_SECURE_NO_WARNINGS 1
//最大公共字串计算
#include <iostream>
#include <string>
using namespace std;

int Maxsubstr(string a, string b)
{
	unsigned int start1, start2;
	int count = 0;
	int max = 0;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		for (unsigned int j = 0; j < b.size(); j++)
		{
			start1 = i; start2 = j;
			while(a[start1] == b[start2] && start1 < a.size() && start2 < b.size())
			{
				start1++;
				start2++;
				count++;
			}
			if (max < count)
				max = count;
			count = 0;
		}
		
	}
	return max;
}



int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	//不区分大小写,将小写转为大写再比较
	for (unsigned int i = 0; i<str1.size(); i++)
	{
		str1[i] = toupper(str1[i]);
	}
	for (unsigned int i = 0; i<str2.size(); i++)
	{
		str2[i] = toupper(str2[i]);
	}
	cout << Maxsubstr(str1, str2) << endl;
	system("pause");
}



//二进制插入
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		m <<= j;
//		return n | m;
//	}
//};

//#include <iostream>
//using namespace std;
//#define SQR(A) A*A
//void main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= SQR(y + z) / SQR(y + z);
//	cout << x << endl;
//	system("pause");
//}