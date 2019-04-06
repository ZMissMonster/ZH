#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int n;
	while (cin >> n >> s)
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '0')
			{
				x++;//0
			}
			else
			{
				y++;//1
			}
		}
		if (x>y)
			cout << x - y << endl;
		else if (x == y)
			cout << 0 << endl;
		else
			cout << y - x<< endl;
	}
	system("pause");
	return 0;
}